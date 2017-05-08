#include <stdio.h>

# define DBE_OK             0
# define DBE_INVALIDSIZE    -101
# define DBE_INVALIDRECORD  -102
# define DBE_WHENCE         -103
# define DBE_EOF            -104
# define DBE_UNIX           -105
# define DBE_MAXSCANS       -106
# define DBE_OPERAND        -107
# define DBE_ATTRTYPE       -108
# define DBE_ATTRLENGTH     -109
# define DBE_ATTRLENGTHOFFSET -110
# define DBE_ATTROFFSET     -111
# define DBE_INVALIDSCAN    -112
# define DBE_SIZETOOLARGE   -113
# define DBE_SCANCLOSED     -114
# define DBE_SCANFILECORRUPT -115
# define DBE_INVALIDPAGE    -116
# define DBE_HEADERRECORD   -117
# define DBE_SIZENOTPOS     -118
# define DBE_NULLRECPTR     -119

# define FIRST  1
# define NEXT   2
# define THIS   3
# define  NEW   4

# define EQ  1
# define LT  2
# define GT  3
# define LE  4
# define GE  5
# define NE  6

# define MAXSCANS 20
/*** taken from defns.h****/

# define NO_PAGE_FREE       -201
# define EMPTY_PAGE         -202
# define NO_NEXT_RECORD     -203
# define NO_SUCH_RECORD     -204
# define INVALID_FD         -205
# define FIRST_SCAN         -206
# define SCAN_OVER          -207


#define MAXRECS	10000	/* max # of records to insert */
#define FNAME_LENGTH 80	/* file name size */
#define EQ_OP	1
#define LT_OP	2
#define GT_OP	3
#define LE_OP   4
#define GE_OP	5
#define NE_OP	6


typedef int RecIdType;		/* type for recid */

#define RecIdToInt(recid)	(recid)	/* converts record id to int */
#define IntToRecId(intval)	(intval) /* converts int to record id */



# define ZERO 0
extern int DBerrno;

# define BIT_START (2*sizeof(int))
# define set_right(x)  ( (1 << (x)) - 1 ) 
# define rightmost_one(x) ln2[ (x) & ~((x)-1) ]
# define set_pos(x,y)  x = ( (x) | (1 << (y)) )
# define is_set(x,y) ( (x) & (1 << (y)) )
# define clear_right(x,y) ( (x) & ~( (1 << (y)) - 1 ) )

# define pageNumOf(x)   ((x) / (_no_of_records+1))
# define recordNumOf(x) (((x) % (_no_of_records+1)) - 1)
# define recIdOf(x,y)   ((x) * (_no_of_records+1) + (y) +1)

extern void InitLnTable(void) ;
extern int ln2[129];

extern
int DBerrno;

extern
int _recordSize,_no_of_records,_recordStart ;

/**************************/


extern int
DB_CreateFile(char *fileName, int recordSize);
/*
	char	*fileName;	<  name of file  >
	int	recordSize;	<  size of records in file  >
	
	returns errVal
*/

extern int
DB_AddRecord(int fileDesc, char *record, int recordSize);

extern void
DB_Init(void);

extern int
DB_GetRecord(int fileDesc, int *recId, char *record, 
	     int recordSize, char whence);

// extern int
// DB_RemoveRecord(int fileDesc, int recId, int recordSize);

// 	int	fileDesc;		<  file descriptor  >
// 	int	recId;		<  record id  >
// 	int	recordSize;	<  size of records in file  >
	
// 	returns errVal

// extern int
// DB_GetRecord(int fileDesc, int *recId, char *record, 
// 	     int recordSize, char whence);
/*
	int	fileDesc;		<  file descriptor  >
	int	*recId;			<  record Id 	 >
	char	*record;		<  record data  >
	int	recordSize;	<  size of records in file  >
	char	whence;		<  FIRST, NEXT, or THIS  >
	
	returns errVal
*/

// extern int
// DB_InitScan(int fileDesc, int recordSize, int attrType, int attrLength,
// 	    int attrOffset, int op, char *value);
// /*                         
// 	int	fileDesc;		<  file descriptor  >
// 	int	recordSize;	<  size of records in file  >
// 	char	attrType;	<  'c', 'i', or 'f'  >
// 	int	attrLength;	<  4 for 'i' or 'f', 1-255 for 'c'  >
// 	int	attrOffset;	<  offset of attribute for comparison  >
// 	int	op;		<  operator for comparison >
// 	char	*value;		<  value for comparison (or null)  >
	
// 	returns scanDesc
// */	

// extern int
// DB_ScanNextRecord(int scanDesc, char *record);
// /*
// 	int	scanDesc;	<  file scan descriptor  >
// 	char	*record;		<  record data  >
	
// 	returns nextRecId
// */

// extern int
// DB_CloseScan(int scanDesc);
// /*
// 	int	scanDesc;	<  file scan descriptor  >
	
// 	returns errVal
// */	

// extern int
// DB_SortFile(int fileDesc, int recordSize, int attrType, int attrLength,
// 	    int attrOffset, char *sortFile);
// /*                         
// 	int	fileDesc;		<  file descriptor  >
// 	int	recordSize;	<  size of records in file  >
// 	char	attrType;	<  'c', 'i', or 'f'  >
// 	int	attrLength;	<  4 for 'i' or 'f', 1-255 for 'c'  >
// 	int	attrOffset;	<  offset of attribute for comparison  >
// 	char    *sortFile;      <  filename of sorted file >
	
// 	returns errVal
// */	
	    
// extern int
// DB_InitBackScan(int fileDesc, int recordSize);
// /*                         
// 	int	fileDesc;		<  file descriptor  >
// 	int	recordSize;	<  size of records in file  >
	
// 	returns recId           <  recId of first record or DBE_EOF  >
// */	

// extern int
// DB_SetBackPos(int recId,char *record);
// /*
//         int  
// */        

// extern int 
// DB_BackScanNextRec(char *record);

// extern int
// DB_CloseBackScan(void);



#define	PF_perform(X,Z)	{ \
			    if((DBerrno=X) < 0) \
				{\
					printf("err #: %d in %s\n",DBerrno, Z );\
					return DBerrno ; \
				}\
			}

#define	PF_perform_in(Y,X,Z)		{ \
					    if((Y=X) < 0) \
					    	{\
								printf("err #: %d in %s\n",Y, Z );\
								return (DBerrno=Y) ; \
							}\
				}

#define	perform(X,Z)	{ \
			    if((DBerrno=X) < 0) \
		    	{\
					printf("err #: %d in %s\n",DBerrno, Z );\
					return DBerrno ; \
				}\
			}

# define CheckIf_Header(x)   \
       if (pageNum == headerNum) {  \
       	printf("err: DBE_HEADERRECORD #: %d in %s\n",DBE_HEADERRECORD , #x );\
          return DBE_HEADERRECORD; \
       }

# define MyGetThisPage(x) {\
    if ((DBerrno = PF_GetThisPage(fileDesc,pageNum,&pageBuf)) == PFE_EOF ) \
         return DBE_EOF ; \
    else if ( DBerrno != PFE_OK ) { \
    	printf("err: DBE_INVALIDPAGE #: %d in %s\n",DBE_INVALIDPAGE , #x );\
         return DBE_INVALIDPAGE ; \
       } \
    PF_perform (PF_UnfixPage(fileDesc,pageNum,FALSE),#x) ; \
    }


# define MyGetNextPage(x)   { \
      if ((DBerrno = PF_GetNextPage(fileDesc,&pageNum,&pageBuf)) == DBE_EOF ) \
         return DBE_EOF ; \
      else if ( DBerrno != DBE_OK ) { \
      	printf("Invalid page error: %d in %s\n",DBE_INVALIDPAGE , #x );\
	 return DBE_INVALIDPAGE ;\
	 } \
      PF_perform (PF_UnfixPage(fileDesc,pageNum,FALSE),#x) ; \
    }