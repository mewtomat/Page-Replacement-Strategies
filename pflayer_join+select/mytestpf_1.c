/* testpf.c */
#include <stdio.h>
#include "pf.h"
#include "pftypes.h"

#define FILE1	"file1"
#define FILE2	"file2"
#define FILE_PAGE_COUNT 100

main(int argc , char* argv[])
{
int error;
int i;
int pagenum,*buf;
int *buf1,*buf2;
int fd1,fd2;

	if(strcmp("mru", argv[1]) == 0)
	{
		ALGO= 1;
	}
	else if(strcmp("lru", argv[1]) == 0)
	{
		ALGO= 2;
	}
	else if(strcmp("lfu", argv[1]) == 0)
	{
		ALGO= 3;
	}
	else if(strcmp("fifo", argv[1]) == 0)
	{
		ALGO= 4;
	}
	else if(strcmp("belady", argv[1]) == 0)
	{
		ALGO= 6;
	}
	else if(strcmp("random", argv[1]) == 0)
	{
		ALGO= 5;
	}
	else 
	{
		printf("incorrect argument");
		return 51;
	}


	/* create a few files */
	if ((error=PF_CreateFile(FILE1))!= PFE_OK){
		PF_PrintError("file1");
		exit(1);
	}
	printf("file1 created\n");

	if ((error=PF_CreateFile(FILE2))!= PFE_OK){
		PF_PrintError("file2");
		exit(1);
	}
	printf("file2 created\n\n");

	/* write to file1 */
	printf("Writing to file1\n");
	mywritefile(FILE1);
	printf("Succesfully written to  file1\n\n");

	/* write to file2 */
	printf("Writing to file2\n");
	mywritefile(FILE2);
	printf("Successfully written to file2\n\n");


	/* open both files */
	if ((fd1=PF_OpenFile(FILE1))<0){
		PF_PrintError("open file1\n");
		exit(1);
	}
	printf("Yo opened file1, fd1 = %d\n", fd1);

	if ((fd2=PF_OpenFile(FILE2))<0 ){
		PF_PrintError("open file2\n");
		exit(1);
	}
	printf("Yo opened file2, fd2 = %d\n", fd2);


	/* print the buffer */
	printf("buffer***************************************:\n");
	PFbufPrint();
	printf("***************************************buffer:\n");
	
	ACCESS = 0;
	MISS = 0;
	/*
	* In this I am extracting a page say Pi from file1
	* Then I am extracting all the pages from file2
	* Problem in this approach is that, for every join operation
	* 	we need both the tuples again
	* Therefore we need to extract Pi again and again for every page of file2
	* This has been done in next version of mytestpf.c

	*/
	printf("Wrong join Operation\n");
	for (i=0; i < FILE_PAGE_COUNT; i++){
		int j;
		if ((error=PF_GetThisPage(fd1,i,&buf))!=PFE_OK){
				PF_PrintError("get this on fd1");
				exit(1);
			}
		// printf("%d %d\n",i,*buf);
		if ((error=PF_UnfixPage(fd1,i,FALSE))!= PFE_OK){
			PF_PrintError("get this on fd1");
				exit(1);
		}
		for (j=0; j < FILE_PAGE_COUNT; j++){
			if(i==1 && j==0){		
				printf("i=0 j=5***************************************:\n");
				PFbufPrint();
				printf("***************************************buffer:\n");
			}
			if ((error=PF_GetThisPage(fd2,j,&buf))!=PFE_OK){
				PF_PrintError("get this on fd2");
				exit(1);
			}
			// printf("%d %d\n",i,*buf);
			if ((error=PF_UnfixPage(fd2,j,FALSE))!= PFE_OK){
				PF_PrintError("get this on fd2");
					exit(1);
			}

		}

	}

	// /* print the buffer */
	// printf("******************************************\n");
	// PFbufPrint();
	// printf("******************************************\n");

	if ((error=PF_CloseFile(fd1))!= PFE_OK){
		PF_PrintError("close fd1");
		exit(1);
	}
	printf("closed file1\n");

	if ((error=PF_CloseFile(fd2))!= PFE_OK){
		PF_PrintError("close fd2");
		exit(1);
	}
	printf("closed file2\n");


	/* destroy the two files */
	if ((error=PF_DestroyFile(FILE1))!= PFE_OK){
		PF_PrintError("destroy file1");
		exit(1);
	}
	if ((error=PF_DestroyFile(FILE2))!= PFE_OK){
		PF_PrintError("destroy file2");
		exit(1);
	}

	/* print the buffer */
	printf("******************************************\n");
	PFbufPrint();
	printf("******************************************\n");


	printf("misses = %d accesses = %d\n",MISS, ACCESS);
	if(ACCESS!=0)
	{
		printf("%f\n", MISS/(ACCESS*1.0));
	}
	else
	{
		printf("%s", "access are 0, not possible \n");
	}
}


/************************************************************
Open the File.
allocate as many pages in the file as the buffer
manager would allow, and write the page number
into the data.
then, close file.
******************************************************************/
writefile(fname)
char *fname;
{
int i;
int fd,pagenum;
int *buf;
int error;

	/* open file1, and allocate a few pages in there */
	if ((fd=PF_OpenFile(fname))<0){
		PF_PrintError("open file1");
		exit(1);
	}
	printf("opened %s\n",fname);

	for (i=0; i < FILE_PAGE_COUNT; i++){
		*((int *)buf) = i;
		printf("%d\n", *buf);
		if ((error=PF_AllocPage(fd,&pagenum,&buf))!= PFE_OK){
			PF_PrintError("first buffer\n");
			exit(1);
		}
		printf("allocated page %d\n",pagenum);
	}

	if ((error=PF_AllocPage(fd,&pagenum,&buf))==PFE_OK){
		printf("too many buffers, and it's still OK\n");
		exit(1);
	}

	/* unfix these pages */
	for (i=0; i < FILE_PAGE_COUNT; i++){
		if ((error=PF_UnfixPage(fd,i,TRUE))!= PFE_OK){
			PF_PrintError("unfix buffer\n");
			exit(1);
		}
	}

	/* close the file */
	if ((error=PF_CloseFile(fd))!= PFE_OK){
		PF_PrintError("close file1\n");
		exit(1);
	}

}

mywritefile(fname)
char *fname;
{
int i;
int fd,pagenum;
int *buf;
int error;

	/* open file1, and allocate and simultaneously unfix them */
	if ((fd=PF_OpenFile(fname))<0){
		PF_PrintError("mywritefile : open file1");
		exit(1);
	}
	printf("mywritefile : opened %s\n",fname);

	for (i=0; i < FILE_PAGE_COUNT; i++){
		*((int *)buf) = i;
		
		/* allocate a page */
		// printf("%d\n", *buf);
		if ((error=PF_AllocPage(fd,&pagenum,&buf))!= PFE_OK){
			PF_PrintError("mywritefile : first buffer\n");
			exit(1);
		}
		// printf("mywritefile : allocated page %d\n",pagenum);

		/* unfix that page */
		if ((error=PF_UnfixPage(fd,i,TRUE))!= PFE_OK){
			PF_PrintError("mywritefile : unfix buffer\n");
			exit(1);
		}
	}


	/* close the file */
	if ((error=PF_CloseFile(fd))!= PFE_OK){
		PF_PrintError("mywritefile : close file1\n");
		exit(1);
	}

}

/**************************************************************
print the content of file
*************************************************************/
readfile(fname)
char *fname;
{
int error;
int *buf;
int pagenum;
int fd;

	printf("opening %s\n",fname);
	if ((fd=PF_OpenFile(fname))<0){
		PF_PrintError("open file");
		exit(1);
	}
	printfile(fd);
	if ((error=PF_CloseFile(fd))!= PFE_OK){
		PF_PrintError("close file");
		exit(1);
	}
}

printfile(fd)
int fd;
{
int error;
int *buf;
int pagenum;

	printf("reading file\n");
	pagenum = -1;
	while ((error=PF_GetNextPage(fd,&pagenum,&buf))== PFE_OK){
		printf("got page %d, %d\n",pagenum,*buf);
		if ((error=PF_UnfixPage(fd,pagenum,FALSE))!= PFE_OK){
			PF_PrintError("unfix");
			exit(1);
		}
	}
	if (error != PFE_EOF){
		PF_PrintError("not eof\n");
		exit(1);
	}
	printf("eof reached\n");
	printf("misses = %d accesses = %d\n",MISS, ACCESS);
	if(ACCESS!=0)
	{
		printf("%f\n", MISS/(ACCESS*1.0));
	}
	else
	{
		printf("%s", "access are 0, not possible \n");
	}

}
