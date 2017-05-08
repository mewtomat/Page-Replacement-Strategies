#include <stdio.h>
#include "am.h"
#include "pf.h"
// #include "testam.h"
#include "db.h"
#include <string.h>

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

main(int argc, char *argv[])
{
FILE *infile;
infile = fopen("mydata.txt","r");
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
	#define TABLENAME1 "./databases/db1"
	#define TABLENAME2 "./databases/db2"
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
	printf("create file = %d\n",DB_CreateFile(fname, RECORDSIZ1));	
	fd = PF_OpenFile(fname);	
	// printf("fd = %d\n", fd);			
	AM_CreateIndex("./databases/db1", 0, 'c', 9);
	sprintf(fname_index,"%s.0","./databases/db1");
	fd_index = PF_OpenFile(fname_index);

/* start adding records, preferably in a loop */	
	// printf("%d \n done \n",(recId=DB_AddRecord(fd,temprecord , RECORDSIZ1)));
	int t1=50, t2 = 50, t3 = 10, t4 = 10, t5 = 10;
	char * s1 = (char*)malloc(t1+1);
	char * s2 = (char*)malloc(t2+1);
	char * s3 = (char*)malloc(t3+1);
	char * s4 = (char*)malloc(t4+1);
	char * s5 = (char*)malloc(t5+1);
	int k;
	for(k = 0; k <100; k++){
		//printf("%d\n",k);
		//reading from fle to database
		getline(&s1, &t1, infile);
		getline(&s2, &t2, infile);
		getline(&s3, &t3, infile);
		getline(&s4, &t4, infile);
		getline(&s5, &t5, infile);
		if ((strlen(s1)>0) && (s1[strlen (s1) - 1] == '\n'))s1[strlen (s1) - 1] = '\0';
		if ((strlen(s2)>0) && (s2[strlen (s2) - 1] == '\n'))s2[strlen (s2) - 1] = '\0';
		if ((strlen(s3)>0) && (s3[strlen (s3) - 1] == '\n'))s3[strlen (s3) - 1] = '\0';
		if ((strlen(s4)>0) && (s4[strlen (s4) - 1] == '\n'))s4[strlen (s4) - 1] = '\0';
		if ((strlen(s5)>0) && (s5[strlen (s5) - 1] == '\n'))s5[strlen (s5) - 1] = '\0';
		sprintf(temprecord,s1);
		sprintf(temprecord+50,s2);
		sprintf(temprecord+100,s3);
		sprintf(temprecord+110,s4);
		sprintf(temprecord+120,s5);
		recId=DB_AddRecord(fd,temprecord , RECORDSIZ1); //right now, add this record id
													//and the key in the b+ tree too.
	
		AM_InsertEntry(fd_index,'c',9,s1,recId); //insert into B+tree
	//printf("%s\n", s1);
	}
	fclose(infile);
/*end of adding records. Now access them */
	printf("%s\n","Database 1 completed" );
	/* Use B+ tree to search for key, it will give you the recId*/
	//DB_GetRecord(fd, &recId, temprecord, RECORDSIZ1, THIS);	//
	//DB_GetRecord(fd, &recId, temprecord, RECORDSIZ1, THIS);	//
	//printf("%s\n",temprecord );
	//printf("%s\n",temprecord+50 );
	//printf("%s\n",temprecord+100 );
	//printf("%s\n",temprecord+110 );
	//printf("%s\n",temprecord+120 );
/* record is accessed. peace yo! */

	// fwrite(temprecord, RECORDSIZ1,1, stdout);
	//PF_CloseFile(fd);

		//join	
	infile = fopen("mydata2.txt","r");
	printf("create file = %d\n",DB_CreateFile(fname1, RECORDSIZ1));	
	fd1 = PF_OpenFile(fname1);	
	// printf("fd = %d\n", fd);			
	AM_CreateIndex("./databases/db2", 0, 'c', 9);
	sprintf(fname_index1,"%s.0","./databases/db2");
	fd_index1 = PF_OpenFile(fname_index1);

/* start adding records, preferably in a loop */	
	// printf("%d \n done \n",(recId=DB_AddRecord(fd,temprecord , RECORDSIZ1)));
	t1=50, t2 = 50, t3 = 10, t4 = 10, t5 = 10;
	s1 = (char*)malloc(t1+1);
	s2 = (char*)malloc(t2+1);
	s3 = (char*)malloc(t3+1);
	s4 = (char*)malloc(t4+1);
	s5 = (char*)malloc(t5+1);
	for(k = 0; k <100; k++){
		//printf("%d\n",k);
		//reading from fle to database
		getline(&s1, &t1, infile);
		getline(&s2, &t2, infile);
		getline(&s3, &t3, infile);
		getline(&s4, &t4, infile);
		getline(&s5, &t5, infile);
		if ((strlen(s1)>0) && (s1[strlen (s1) - 1] == '\n'))s1[strlen (s1) - 1] = '\0';
		if ((strlen(s2)>0) && (s2[strlen (s2) - 1] == '\n'))s2[strlen (s2) - 1] = '\0';
		if ((strlen(s3)>0) && (s3[strlen (s3) - 1] == '\n'))s3[strlen (s3) - 1] = '\0';
		if ((strlen(s4)>0) && (s4[strlen (s4) - 1] == '\n'))s4[strlen (s4) - 1] = '\0';
		if ((strlen(s5)>0) && (s5[strlen (s5) - 1] == '\n'))s5[strlen (s5) - 1] = '\0';
		sprintf(temprecord1,s1);
		sprintf(temprecord1+50,s2);
		sprintf(temprecord1+100,s3);
		sprintf(temprecord1+110,s4);
		sprintf(temprecord1+120,s5);
		recId=DB_AddRecord(fd1,temprecord1 , RECORDSIZ1); //right now, add this record id
													//and the key in the b+ tree too.
	
		AM_InsertEntry(fd_index1,'c',9,s1,recId); //insert into B+tree
	//printf("%s\n", s1);
	}
	fclose(infile);/*end of adding records. Now access them */
	printf("%s\n","Database 2 completed" );
	/* Use B+ tree to search for key, it will give you the recId*/
	//DB_GetRecord(fd1, &recId, temprecord, RECORDSIZ1, THIS);	//
	//DB_GetRecord(fd, &recId, temprecord, RECORDSIZ1, THIS);	//
	//printf("%s\n",temprecord );
	//printf("%s\n",temprecord+50 );
	//printf("%s\n",temprecord+100 );
	//printf("%s\n",temprecord+110 );
	//printf("%s\n",temprecord+120 );
/* record is accessed. peace yo! */

	// fwrite(temprecord, RECORDSIZ1,1, stdout);
	
	
	
	
	
	//join
	printf("opening index scan on rollnumber\n");
	sd = AM_OpenIndexScan(fd_index,'c',9, NE_OP,NULL);
	printf("loop1 %d\n",sd);
	numrec = 0;
	while((recnum=RecIdToInt(AM_FindNextEntry(sd)))>= 0){
		//printf("%d\n",recnum);
		numrec++;
		DB_GetRecord(fd, &recnum, temprecord, RECORDSIZ1, THIS);	//
		//DB_GetRecord(fd, &recId, temprecord, RECORDSIZ1, THIS);	//
		char id[50];
		sprintf(id, temprecord);
		printf("id = %s\n",id);
		sd1 = AM_OpenIndexScan(fd_index1,'c',9, EQ_OP,id);
		//printf("loop2 %d\n",sd1);
		numrec1 = 0;
		while((recnum1=RecIdToInt(AM_FindNextEntry(sd1)))>= 0){
			//printf("%d\n",recnum1);
			numrec1++;
			DB_GetRecord(fd1, &recnum1, temprecord1, RECORDSIZ1, THIS);	//
			//DB_GetRecord(fd, &recId, temprecord, RECORDSIZ1, THIS);	//
			printf("From first relation ");
			printf("%s ",temprecord );
			printf("%s ",temprecord+50 );
			printf("%s ",temprecord+100 );
			printf("%s ",temprecord+110 );
			printf("%s\n",temprecord+120 );
		
			printf("From second relation ");
			printf("%s ",temprecord1 );
			printf("%s ",temprecord1+50 );
			printf("%s ",temprecord1+100 );
			printf("%s ",temprecord1+110 );
			printf("%s\n",temprecord1+120 );
		
		}
		
		
		
	}
	printf("retrieved %d records\n",numrec);
	AM_CloseIndexScan(sd);
	AM_CloseIndexScan(sd1);
	
	
	
	
	
	//select
	printf("running select\n");
	char *p;
	int code = strtoimax(argv[1], &p, 10);
	sd = AM_OpenIndexScan(fd_index,'c',9, code,argv[2]);
	numrec = 0;
	while((recnum=RecIdToInt(AM_FindNextEntry(sd)))>= 0){
		printf("%d\n",recnum);
		numrec++;
			DB_GetRecord(fd, &recnum, temprecord, RECORDSIZ1, THIS);	//
			printf("%s ",temprecord );
			printf("%s ",temprecord+50 );
			printf("%s ",temprecord+100 );
			printf("%s ",temprecord+110 );
			printf("%s\n",temprecord+120 );
	
		}
		
		
		
	
	printf("retrieved %d records\n",numrec);
	AM_CloseIndexScan(sd);
	
	
	
	
	
	
	PF_CloseFile(fd);
	PF_CloseFile(fd1);
	
	
	/* destroy everything */
	printf("closing down\n");
	//xAM_CloseIndexScan(sd1);
	PF_CloseFile(fd_index);
	PF_CloseFile(fd_index1);




	

	
	
}
