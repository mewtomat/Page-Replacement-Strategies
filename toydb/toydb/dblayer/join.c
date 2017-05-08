#include <stdio.h>
#include "am.h"
#include "pf.h"
// #include "testam.h"
#include "db.h"
#include <string.h>


main(int argc, char *argv[])
{
ALGO = (int)(argv[1][0] - '0');
int fd, fd_index;	/* file descriptor for the index */
int fd1, fd_index1;	/* file descriptor for the index */
char fname[FNAME_LENGTH];	/* file name */
char fname1[FNAME_LENGTH];	/* file name */
char fname_index[FNAME_LENGTH];	/* file name */
char fname_index1[FNAME_LENGTH];	/* file name */
int recnum;	/* record number */
int recnum1;	/* record number */
int sd;	/* scan descriptor */
int sd1;	/* scan descriptor */
int numrec;	/* # of records retrieved */
int numrec1;	/* # of records retrieved */
int testval;	
int recId;
/* First: To create the database file ( add provisions to create a ddl like script which contains data that this function reads) */
	/*info abt db1
		5 attributes: 2 strings(50,50), 3 ints(however ints are also stored like
		 strings.so each digit requires one byte, so for now assuming 10 digits max,
		  and allocating 10 B for each int)
		size = 50 + 50 + 3*10 = 130
	*/
	#define RECORDSIZ1 130
	#define TABLENAME1 "./mydata/db1"
	#define TABLENAME2 "./mydata/db2"
	char temprecord[RECORDSIZ1];
	char temprecord1[RECORDSIZ1];
	//sprintf(temprecord,"130050027");
	//sprintf(temprecord+50,"Anmol Arora");
	//sprintf(temprecord+100,"19");
	//sprintf(temprecord+110,"9");
	//sprintf(temprecord+120,"85");

/* initialise the layers */
	printf("initializing\n");
	DB_Init();

	// strcpy(fname, TABLENAME1);					//The file name containig database #1 is db1
	sprintf(fname, TABLENAME1);
	sprintf(fname1, TABLENAME2);
	// printf("%s\n",fname );
/* physical file created*/
	fd = PF_OpenFile(fname);	
	// printf("fd = %d\n", fd);			
	sprintf(fname_index,"%s.0",TABLENAME1);
	fd_index = PF_OpenFile(fname_index);

	fd1 = PF_OpenFile(fname1);	
	sprintf(fname_index1,"%s.0",TABLENAME2);
	fd_index1 = PF_OpenFile(fname_index1);
	printf("fd_index1 = %d\n", fd_index1);			

/* start adding records, preferably in a loop */	
	// printf("%d \n done \n",(recId=DB_AddRecord(fd,temprecord , RECORDSIZ1)));
	

	MISS = 0;
	ACCESS = 0;
	
	
	//join
	printf("opening index scan on rollnumber\n");
	
	
	sd = AM_OpenIndexScan(fd_index,'c',9,NE_OP,NULL);
	printf("retrieving recid's from scan descriptor %d\n",sd);
	numrec = 0;
	
	while((recnum=RecIdToInt(AM_FindNextEntry(sd)))>= 0){
		//printf("%d\n",recnum);
		DB_GetRecord(fd, &recnum, temprecord, RECORDSIZ1, THIS);	//
		numrec++;
		
		char* id = malloc(50);
		snprintf(id, "%s", temprecord );
		printf(" vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv %s\n", id);
		//int x= 11111;//(char*)&x
		char *x = malloc(10);
		sd1 = AM_OpenIndexScan(fd_index1,'c',9,NE_OP, NULL);
		printf("retrieving recid's from scan descriptor %d\n",NULL);
		while((recnum1=RecIdToInt(AM_FindNextEntry(sd1)))>= 0){
	    //printf("%d\n",recnum1);
	    DB_GetRecord(fd1, &recnum1, temprecord1, RECORDSIZ1, THIS);	//
		char* id1 = malloc(50);
		snprintf(id1, "%s", temprecord1 );
		//printf("%s\n", id1);

		if(strcmp(id, id1) == 0)printf("%s %s\n",id, id1); 
		
		numrec++;
	}
	//printf("retrieved %d records\n",numrec);
		AM_CloseIndexScan(sd1);

		
		
		
		
		
	}

	
	
	printf("\n\n\n\n");
	printf("Final statistics for join are as follows(ALGORITHM=%d):\n", ALGO);
	printf("Misses = %d, Accesses = %d, Miss Rate = %f\n", MISS, ACCESS, MISS/(ACCESS*1.0));
	printf("\n\n\n\n");

	
		
		printf("retrieved %d records\n",numrec);

	perform(PF_CloseFile(fd),"main");
	perform(PF_CloseFile(fd1),"main");
	
	
	/* destroy everything */
	printf("closing down\n");
	//xAM_CloseIndexScan(sd1);
	perform(PF_CloseFile(fd_index),"main: closing fd_index");
	perform(PF_CloseFile(fd_index1),"main: closing fd_index1");	
}

