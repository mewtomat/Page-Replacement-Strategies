#include "db.h"
#include "am.h"
#include "pf.h"
#include <stdio.h>
#include "pflayer.h"
#include "amlayer.h"
# include <stdarg.h>

int DBerrno=DBE_OK;
int _recordSize,_no_of_records,_recordStart ;
/**************debugging functions*********/


/************************************************/



/**********helper functions for create file***********/
int
initialise_header(char *pageBuf, int recordSize)
/*
 * This function initialises the header page of a newly created file
 * It computes the constants specifying the structure of each page,
 * namely recordStart & no_of_records and stores these in addition to
 * recordSize in the header page. Also the nextFree and prevFree pointers
 * of the header are set to NO_PAGE_FREE
 *
 * The function returns the error DBE_SIZETOOLARGE if the recordSize is too
 * large, else it returns DBE_OK
 */
{
  int firstFree = NO_PAGE_FREE,prevFree = NO_PAGE_FREE;
  int recordStart,no_of_records;
  int bits_avail,first_approx,bitvect_size;
  
  bits_avail = (PF_PAGE_SIZE-BIT_START)*8;
  first_approx = bits_avail/(recordSize*8+1);
  bitvect_size = (first_approx+7)/8;
  recordStart = BIT_START + bitvect_size;
  no_of_records = (PF_PAGE_SIZE - BIT_START - bitvect_size)/recordSize;
  
  if (no_of_records == 0)        /* record size too large to fit on a page */
    return DBE_SIZETOOLARGE ;
    
  memcpy(pageBuf,&firstFree,sizeof(int));  
  memcpy((pageBuf+=sizeof(int)),&prevFree,sizeof(int));
  memcpy((pageBuf+=sizeof(int)),&recordSize,sizeof(int));
  memcpy((pageBuf+=sizeof(int)),&recordStart,sizeof(int));
  memcpy((pageBuf+=sizeof(int)),&no_of_records,sizeof(int));
  
  return DBE_OK ;
}
/*******************/

/*** Helper functions for addrecord ******/
void
setPageParams(char *headerBuf)
{
  memcpy(&_recordSize,(headerBuf+=BIT_START),sizeof(int));
  memcpy(&_recordStart,(headerBuf+=sizeof(int)),sizeof(int));
  memcpy(&_no_of_records,(headerBuf+=sizeof(int)),sizeof(int));
}

int
getNextFree(char *pageBuf)
/*
 * This function returns the nextFree page of a page
 */
{
  int pageNum;
  
  memcpy(&pageNum,pageBuf,sizeof(int));
  return pageNum;
}

void
initPage(char *pageBuf)
/*
 * This function initialises a newly allocated page. The nextFree and
 * prevFree pointers are set to NO_PAGE_FREE. Also the bitvector is
 * initialised to all 0's excepting possibly for extra bits at the
 * left which are initialised to 1's
 */
{
  int pagePtr = NO_PAGE_FREE;
  
  memcpy(pageBuf,&pagePtr,sizeof(int));
  memcpy(pageBuf,&pagePtr,sizeof(int));
  memset(pageBuf+BIT_START,0,_recordStart-BIT_START);
  pageBuf[BIT_START] = ~set_right(_no_of_records%8);
}

int
setFirstFreeSlot(char *pageBuf)
/*
 * This function returns the location of the first free slot on a page and
 * also marks it as occupied. In case there is no free slot
 */
{
  int i,pos,byte=0;
  
  for (i=_recordStart-1;i>=BIT_START;i--)
    if (!( (pos=rightmost_one(~pageBuf[i])) < 0)) {
      set_pos(pageBuf[i],pos);
      return byte*8+pos; 
    }
    else
      byte++;
      
  return -1;
}

int
addRecord(int pageNum, char *pageBuf, char *record)
{
  int recordNo;
  
  recordNo = setFirstFreeSlot(pageBuf);
  memcpy(pageBuf+_recordStart+_recordSize*recordNo,record,_recordSize);
  return (recIdOf(pageNum,recordNo));
}

int
pageIsFull(char *pageBuf)
{
  int i;

  // bin_print_str(pageBuf+BIT_START,_recordStart-BIT_START);
  
  for (i=BIT_START;i<_recordStart;i++)
    if (~pageBuf[i]) 
      return FALSE;
  return TRUE;
}

int
setNextFree(int fileDesc, int pageNum, int nextpageNum)
/*
 * This function sets the nextFree page of pageNum to nextpageNum
 * also the prevFree page of nextpageNum is set to pageNum
 * The required pages are got and unfixed by this routine
 * It returns an error code if the PF layer calls fail else it 
 * returns HFE_OK
 */
{
  char *pageBuf;
  
  PF_perform(PF_GetThisPage(fileDesc,pageNum,&pageBuf),"setNextFree");
  memcpy(pageBuf,&nextpageNum,sizeof(int));
  PF_perform(PF_UnfixPage(fileDesc,pageNum,TRUE),"setNextFree");
  
  if (nextpageNum != NO_PAGE_FREE) {
    PF_perform(PF_GetThisPage(fileDesc,nextpageNum,&pageBuf),"setNextFree");
    memcpy(pageBuf+sizeof(int),&pageNum,sizeof(int));
    PF_perform(PF_UnfixPage(fileDesc,nextpageNum,TRUE),"setNextFree");
  }
  
  return DBE_OK;
}

int
checkSize(int size1,int size2)
/*
 * This simply checks if the two sizes are equal and returns an HF error code
 * if they are not equal
 */
{
  return ((size1 == size2) ? DBE_OK : DBE_INVALIDSIZE ) ;
}

int ln2[129] ;
void
InitLnTable(void)
/*
 * This initialises the array ln2 where ln2[i] = j iff 2^j = i
 * this array is used to determine the no of the leftmost 1 in a byte for
 * efficient bit vector operations
 */
{
  int i,j=1;
  
  ln2[0] = -1;
  for (i=0; i<8; i++) {
    ln2[j] = i;
    j = j<<1;
  }
}

/******************/

/************************functions for getrecord**********/
int
getFirstFilledSlot(char *pageBuf)
{
  int i,pos,byte=0;
  
  for (i=_recordStart-1;i>=BIT_START;i--)
    if (!( (pos=rightmost_one(pageBuf[i])) < 0)) {
    
      // DebugPrintf("FirstFilled : i = %d , pos = %d\n",i,pos);
      
      return byte*8+pos; 
    }
    else
      byte++;
      
  return -1;
}


int
isFilledSlot(char *pageBuf, int recordNum)
{
  int byte,pos;
  
  byte = recordNum / 8;
  pos = recordNum % 8;
  return is_set(pageBuf[_recordStart-1-byte],pos);
}


int
nextFilledSlot(char *pageBuf, int recordNum)
{
  int byte,pos,nextRecNum;
  char temp;
  
  byte = recordNum / 8;
  pos = recordNum % 8;
/*  
 * Commented out to allow for deletions while scanning
 
  if (!is_set(pageBuf[_recordStart-1-byte],pos))
    return NO_SUCH_RECORD;
    
 */    
  temp = clear_right(pageBuf[_recordStart-1-byte],pos+1);
  if (!( (pos=rightmost_one(temp)) < 0)) 
    if ((nextRecNum = byte*8+pos) < _no_of_records) {
      
      // DebugPrintf("NextFilled (%d) = %d\n",recordNum,byte*8+pos);
      
      return nextRecNum;
    }
    else
      return NO_NEXT_RECORD;
  else
    byte++;
    
  while (byte < (_recordStart-BIT_START) )
    if (!( (pos=rightmost_one(pageBuf[_recordStart-1-byte])) < 0))
      if ((nextRecNum = byte*8+pos) < _no_of_records) {
  
	// DebugPrintf("NextFilled (%d) = %d\n",recordNum,byte*8+pos);
  
	return nextRecNum;
      }
      else
	return NO_NEXT_RECORD;
    else
      byte++;
  
  return NO_NEXT_RECORD;
}


int
GetRecord(int pageNum, char *pageBuf, char *record, int recordNum,int whence)
{
  int recNum;
/*
  returns :-
  
  EMPTY_PAGE     : if no record on the page.
  NO_NEXT_RECORD : if no record next to recordNum on the same page.
  NO_SUCH_RECORD : if recordNum not occupied on this page.
  
  */
  
  // /* To be khacched */
  // DebugPrintf("Bit vector of page : ");
  // bin_print_str(pageBuf+BIT_START,_recordStart-BIT_START);
  // DebugPrintf("recordNum = %d , whence = %d\n",recordNum,whence);
  // /*               */
  
  switch(whence) {
  case FIRST: 
    if ((recNum=getFirstFilledSlot(pageBuf)) < 0)
      return EMPTY_PAGE;
    else {
      memcpy(record,pageBuf+_recordStart+_recordSize*recNum,_recordSize);
      return recIdOf(pageNum,recNum);
    }
    break;
    
  case THIS:
    if (isFilledSlot(pageBuf,recordNum)) {
      memcpy(record,pageBuf+_recordStart+_recordSize*recordNum,_recordSize);
      return recIdOf(pageNum,recordNum);
    }
    else
      return NO_SUCH_RECORD;
    break;
    
  case NEXT:
    if ((recNum=nextFilledSlot(pageBuf,recordNum)) < 0)
      return NO_NEXT_RECORD ;
    else {
      memcpy(record,pageBuf+_recordStart+_recordSize*recNum,_recordSize);
      return recIdOf(pageNum,recNum);
    }
    break;
  }
}

/**********************************/

void
DB_Init(void)
/*
 * Initialises the file by calling PF_Init and initialises the scan-table
 * maintained to keep track of in-progress scans.
 */
{
  PF_Init() ;
  // InitScanTable() ;
  InitLnTable() ;
  // InitCompareTable() ;
}


int
	DB_CreateFile(char *fileName, int recordSize)
	/*
	 *	char	*fileName;	<  name of file  >
	 *	int	recordSize;	<  size of records in file  >
	 *	returns errVal.
	 *
	 * It calls the PF_CreateFile to create the file at PFlayer. 
	 * It initialises the header-page maintained by the DBlayer for that file.
	 *
	 * In case the Pflayer-function-call fails, it returns PFerrno.
	 * Else on successful creation of file and header-page, it returns DB_OK.
	 */
	{
	  int fileDesc,pageNum;
	  char *pageBuf;
	  
	  if ( recordSize <= 0 ) {
	    printf("DB basic: record size = %d not possible \n ", recordSize);
	    return DBE_SIZENOTPOS ;
	  }
  		// printf("%s\n", "check 1");
  	// printf("%s\n", "check 1.01");

	  PF_perform (PF_CreateFile(fileName),"DB_CreateFile") ;
  	// printf("%s\n", "check 1.0");

	  PF_perform_in (fileDesc,PF_OpenFile(fileName),"DB_CreateFile") ;
  	if (fileDesc<0)
    {
      printf("DB_CreateFile has failed this code.\n");
    }
    // printf("%s\n", "check 2");
	  
	  if (PF_AllocPage(fileDesc,&pageNum,&pageBuf) != PFE_OK) {  
	    PF_perform (PF_CloseFile(fileDesc),"DB_CreateFile") ;    
	    PF_perform (PF_DestroyFile(fileName),"DB_CreateFile") ;
	    return PFerrno ;
	  }
  	// printf("%s\n", "check 3");
	  
	  if (initialise_header (pageBuf,recordSize) != DBE_OK) {
	     // HF_PrintError (HFE_SIZETOOLARGE,"HF_CreateFile") ;
	  	 printf("DB Basic: DB_CreateFile: %d :size too large", DBE_SIZETOOLARGE);
	     PF_perform (PF_DisposePage(fileDesc,pageNum),"DB_CreateFile") ;
	     PF_perform (PF_CloseFile(fileDesc),"DB_CreateFile") ;     
	     PF_perform (PF_DestroyFile(fileName),"DB_CreateFile") ;     
	     return DBE_SIZETOOLARGE ;
	   }
	  
	  if (PF_UnfixPage(fileDesc,pageNum,TRUE) != PFE_OK) {   
	    PF_perform (PF_CloseFile(fileDesc),"DB_CreateFile") ;    
	    PF_perform (PF_DestroyFile(fileName),"DB_CreateFile") ;          
	    return PFerrno ;
	  }  
  	// printf("%s\n", "check 4");
	  
	  PF_perform (PF_CloseFile(fileDesc),"DB_CreateFile") ;
	  
	  return DBE_OK;
	}

/* Make this function return the pointer to record 
buffer stored in the file, so as to add it in the B+ tree also */
int
DB_AddRecord(int fileDesc, char *record, int recordSize)
/*
 *      int	fileDesc;		<  file descriptor  >
 *	char	*record;		<  record data  >
 *	int	recordSize;	<  size of records in file  >
 *	returns recId
 *
 *  This function also takes care of the book-keeping associated with the
 *  addition of a record that could potentially fill up a free page. The
 *  book-keeping involved is the maintaining the linked-list of the free
 *  pages, starting at the firstFreeNum contained in first 4 bytes of the
 *  header-page.
 *
 *  In case the Pflayer-function-call fails, it returns PFerrno.
 *  Else on successful addition of record to the file, it returns HFE_OK.
 */
{
  int headerNum,pageNum; 
  int recId ;              
  char *headerBuf,*pageBuf ;
  	// printf("%s\n", "check 0");
  
  PF_perform (PF_GetFirstPage(fileDesc,&headerNum,&headerBuf), "DB_AddRecord") ;
  PF_perform (PF_UnfixPage(fileDesc,headerNum,FALSE), "DB_AddRecord") ;
  	// printf("%s\n", "check 0.1");
  
  setPageParams (headerBuf) ;
  perform (checkSize(recordSize,_recordSize), "DB_AddRecord") ;
  
  	// printf("%s\n", "check 1");

  if ( record == (char *) NULL) {
    // HF_PrintError(HFE_NULLRECPTR,"HF_AddRecord") ;
    printf("error in addrecord:db.c : null rec pointer \n");
    return DBE_NULLRECPTR  ;
  }

  if ( (pageNum = getNextFree(headerBuf)) == NO_PAGE_FREE )  {
    PF_perform (PF_AllocPage(fileDesc,&pageNum,&pageBuf), "DB_AddRecord") ;
    // printf("%s\n", "allocating new page");
    initPage (pageBuf) ;
    recId = addRecord (pageNum,pageBuf,record) ;
    PF_perform (PF_UnfixPage(fileDesc,pageNum,TRUE), "DB_AddRecord") ;
    if ( ! pageIsFull(pageBuf) )  
      perform (setNextFree (fileDesc,headerNum,pageNum), "DB_AddRecord") ;
  }
  else {
    PF_perform (PF_GetThisPage(fileDesc,pageNum,&pageBuf), "DB_AddRecord") ;
    recId = addRecord (pageNum,pageBuf,record) ;
    PF_perform (PF_UnfixPage(fileDesc,pageNum,TRUE), "DB_AddRecord") ;
    if ( pageIsFull(pageBuf) )
      perform (setNextFree (fileDesc,headerNum,getNextFree(pageBuf)), "DB_AddRecord") ;
  }		  
  	// printf("%s\n", "check 2");
  
  // DebugPrintf("Added the record %s to fd %d recId = %d\n",record,fileDesc,recId) ;
  // DebugPrintf("Recordlength = %d Passed = %d\n",_recordSize,recordSize) ;
  // printf("successfully record ??inserted\n");
  return recId ;
}

int
DB_GetRecord(int fileDesc, int *recId, char *record, 
	     int recordSize, char whence)
/*
 *	int	fileDesc;		<  file descriptor  >
 *	int	*recId;			<  record Id 	 >
 *	char	*record;		<  record data  >
 *	int	recordSize;	<  size of records in file  >
 *	char	whence;		<  FIRST, NEXT, or THIS  >
 *	returns errVal
 *
 *  In case the Pflayer-function-call fails, it returns PFerrno.
 *  In case of whence = FIRST,
 *      if no page present              -> returns HFE_EOF.
 *  In case of whence = NEXT
 *      if no next page present         -> returns HFE_EOF.
 *      if invalid (*recId) in argument -> returns HFE_INVALIDRECORD.
 *  In case of whence = THIS
 *      if invalid (*recId) in argument -> returns HFE_INVALIDRECORD. 
 *  Some other whence condition         -> returns HFE_WHENCE.
 *  Else on successful retrieval of record from the file, it returns HFE_OK.
 *
 */
{
  int headerNum,pageNum,recordNum; 
  char *headerBuf,*pageBuf ;
  int found = FALSE ;

  PF_perform (PF_GetFirstPage(fileDesc,&headerNum,&headerBuf), "DB_GetRecord") ;
  PF_perform (PF_UnfixPage(fileDesc,headerNum,FALSE), "DB_GetRecord") ;  
  
  setPageParams (headerBuf) ;
  perform (checkSize(recordSize,_recordSize), "DB_GetRecord") ;    
  
  if ( record == (char *) NULL) {
    // HF_PrintError(HFE_NULLRECPTR,"HF_GetRecord") ;
    // return HFE_NULLRECPTR  ;
    	printf("DB_GetRecord: error null record pointer:%d\n",DBE_NULLRECPTR );
    	return DBE_NULLRECPTR;
  }
  
  switch(whence) {
  
  case FIRST :
    pageNum = headerNum ;
    while ( found == FALSE ) {
       MyGetNextPage(DB_GetRecord) ;
       if ( (*recId = GetRecord(pageNum,pageBuf,record,ZERO,FIRST)) 
	    != EMPTY_PAGE ) 
	 found = TRUE ;
    }
    return DBE_OK ;
  
  case  NEXT :
  case  THIS :
    pageNum = pageNumOf (*recId) ;
    recordNum = recordNumOf (*recId) ;  
    CheckIf_Header(DB_GetRecord) ;
    
    MyGetThisPage(DB_GetRecord) ;
    *recId = GetRecord(pageNum,pageBuf,record,recordNum,whence) ;
    
    if ((*recId == NO_SUCH_RECORD)  || 
	(*recId == EMPTY_PAGE )) {
	if ( whence == THIS ) {
	  // HF_PrintError (HFE_INVALIDRECORD,"HF_GetRecord") ;
       printf("err: DBE_INVALIDRECORD #: %d in %s\n",DBE_INVALIDRECORD , "DB_Getrecord" );
	  return DBE_INVALIDRECORD ;
	}
    }
    else if (*recId != NO_NEXT_RECORD)
	found = TRUE ;

    if ( whence == NEXT ) {
      while ( found == FALSE ) {
	MyGetNextPage(DB_GetRecord) ;
	if ( (*recId = GetRecord(pageNum,pageBuf,record,ZERO,FIRST) ) 
	    != EMPTY_PAGE ) 
	  found = TRUE ;      
      }
    }
    return DBE_OK ;
    
  default  :
    // HF_PrintError (HFE_WHENCE,"HF_GetRecord") ;
    printf("err: DBE_WHNECE #: %d in %s\n",DBE_WHENCE , "DB_GetRecord" );
    return DBE_WHENCE ;
  }
}
