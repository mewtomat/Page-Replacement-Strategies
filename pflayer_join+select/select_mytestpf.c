/* testpf.c */
#include <stdio.h>
#include "pf.h"
#include "pftypes.h"
#include <sys/time.h>

#define FILE1	"file1"
#define FILE2	"file2"
#define FILE_PAGE_COUNT 100

main(int argc , char* argv[])
{
	printf("Entered main loop\n");
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
	else if(strcmp("random", argv[1]) == 0)
	{
		ALGO= 5;
	}
	else if(strcmp("belady", argv[1]) == 0)
	{
		ALGO= 6;
	}

	else 
	{
		printf("incorrect argument");
		return 51;
	}


	/* create a file */
	if ((error=PF_CreateFile(FILE1))!= PFE_OK){
		PF_PrintError("file1");
		exit(1);
	}
	printf("file1 created\n");

	/* write to file1 */
	printf("Writing to file1\n");
	mywritefile(FILE1);
	printf("Succesfully written to  file1\n\n");


	/* open the file */
	if ((fd1=PF_OpenFile(FILE1))<0){
		PF_PrintError("open file1\n");
		exit(1);
	}
	printf("Yo opened file1, fd1 = %d\n", fd1);


	/* print the buffer */
	printf("buffer***************************************:\n");
	PFbufPrint();
	printf("***************************************buffer:\n");


	ACCESS = 0;
	MISS = 0;

	int operation_count = FILE_PAGE_COUNT; 
	int page_order[operation_count];
	for(i = 0; i<FILE_PAGE_COUNT; i++) {
		scanf("%d", &page_order[i]);
		printf("%d %d\n", i, page_order[i] );
	}

	// for(i = 0; i<count; i++)
	// 	printf("%d %d\n", i, page_order[i]);


	/*
	* In this I am extracting a page say Pi from file1
	* Then I am extracting all the pages from file2
	* Problem in this approach is that, for every join operation
	* 	we need both the tuples again
	* Therefore we need to extract Pi again and again for every page of file2
	* This has been corrected in this version.
	* Another problem popped up !
	* Now as we are unfixing Pi of file1 just after accessing so it's leading to poor performance of
	* 	mru as compared to lru.
	* The above problem too is fixed in this version. Pi is fixed at the start of Pj loop and unfixed after
	* 	it ends.
	*/
	printf("Select Operation\n");
	struct timeval tim;  
	gettimeofday(&tim, NULL);  
    double t1=tim.tv_sec+(tim.tv_usec/1000000.0); 
	for (i=0; i < FILE_PAGE_COUNT; i++){

			if(ALGO == BELADY){
				mygetpage(fd1, page_order[i], &buf, page_order, i, operation_count);
				continue;
			}

			// Fixing page page_order[i] from file1
			if ((error=PF_GetThisPage(fd1,page_order[i],&buf))!=PFE_OK){
				PF_PrintError("get this on fd1");
				exit(1);
			}

			// Unfixing page i from file1
			if ((error=PF_UnfixPage(fd1,page_order[i],FALSE))!= PFE_OK){
				PF_PrintError("get this on fd1");
					exit(1);
			}
	}

	gettimeofday(&tim, NULL);  
    double t2=tim.tv_sec+(tim.tv_usec/1000000.0);
    printf("%.6lf milli seconds elapsed\n", (t2-t1)*1000); 


	if ((error=PF_CloseFile(fd1))!= PFE_OK){
		PF_PrintError("close fd1");
		exit(1);
	}
	printf("closed file1\n");

	/* destroy the two files */
	if ((error=PF_DestroyFile(FILE1))!= PFE_OK){
		PF_PrintError("destroy file1");
		exit(1);
	}

	/* print the buffer */
	printf("******************************************\n");
	PFbufPrint();
	printf("******************************************\n");


	printf("misses = %d accesses = %d\n",MISS, ACCESS);
	if(ACCESS!=0)
	{
		printf("miss rate = %f\n", MISS/(ACCESS*1.0));
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

int unfix_farthest(page_order, start, operation_count)
int * page_order; // array containing in which order pages are required
int start; // pointing to the current position which needs to be read.
int operation_count; // total size of the array, i.e. , total no. of pages required
{
	// Getting the buffer list
	int fd_list[PF_MAX_BUFS], page_list[PF_MAX_BUFS];
	int list_count;
	// printf("Calling PFbufList\n");
	// TODO : PFbufList is in buf.c but is still working :/
	list_count = PFbufList(fd_list, page_list);
	// printf("End of call to PFbufList\n");
	if(list_count < PF_MAX_BUFS) {
		// printf("unfix_farthest : Buffer is still empty full\n");
		return -1;
	} else if (list_count > PF_MAX_BUFS) {
		printf("unfix_farthest error : Buffer having more pages than allowed.\n");
		return -2;
	}

	// printf("unfix_farthest : Buffer size is : %d\n", *list_count);
	// Converting buffer list into : fd * FILE_PAGE_COUNT
	int i;
	int page_present[PF_MAX_BUFS];
	for(i = 0; i < PF_MAX_BUFS; i++) {
		page_present[i] = fd_list[i]*FILE_PAGE_COUNT + page_list[i];
		// printf("%d %d\n", i, page_present[i]);
	}

	// finding farthest here.
	int curr_farthest = -1;
	int curr_farthest_distance = 0;
	for(i=0; i<PF_MAX_BUFS; i++) {
		int j;
		// Finding next occurence of i th page in the buffer.
		for(j = start; j<operation_count; j++) {
			if(page_present[i] == page_order[j]) {
				if(j > curr_farthest_distance) {
					curr_farthest = i;
					curr_farthest_distance = j;
				}
				break;
			}
			// No occurence of i th page exists. So let's tag this as the farthest.
			if(j == operation_count-1) {
				curr_farthest = i;
				curr_farthest_distance = operation_count;
			}
		}
		if(curr_farthest_distance == operation_count) break;
	}
	// printf("Farthest buffer page is : %d with page no. : %d at distance : %d\n", page_present[curr_farthest], curr_farthest, curr_farthest_distance );

	int to_unfix = curr_farthest;
	// Now I need to unfix the page
	// printf("%d Unfixing page : %d of file : %d \n", to_unfix, fd_list[to_unfix], page_list[to_unfix] );
	// PFbufPrint();
	int error;
	if ((error=PF_UnfixPage(fd_list[to_unfix],page_list[to_unfix],FALSE))!= PFE_OK){
				PF_PrintError("get this on fd");
					exit(1);
			}
	return (fd_list[to_unfix]*FILE_PAGE_COUNT + page_list[to_unfix]);
}

mygetpage(fd, page_num, buf, page_order, start, operation_count)
int * page_order; // array containing in which order pages are required
int start; // pointing to the current position which needs to be read.
int operation_count; // total size of the array, i.e. , total no. of pages required
int fd;
int page_num;
char ** buf;
{
	// This implementation assumes that all the pages are unfixed.
	// Whenever a page is desired, we check whether it's there in the buffer
	// If so cool. Just Get it and unfix it.
	// Else Find the farthest. Fix everyone except it.
	// Get the required page
	// Unfix everything again.

	// Getting the buffer list
	int error;
	int fd_list[PF_MAX_BUFS], page_list[PF_MAX_BUFS];
	int list_count;

	// TODO : PFbufList is in buf.c but is still working :/
	// Done !!
	list_count = PF_bufList(fd_list, page_list);
	int is_present = FALSE;
	int i;
	for(i = 0; i< list_count; i++) {
		if(fd_list[i] == fd && page_list[i] == page_num){
			is_present = TRUE;
		}
	}

	if(is_present || list_count < PF_MAX_BUFS){
		if ((error=PF_GetThisPage(fd,page_num,buf))!=PFE_OK){
				PF_PrintError("mygetpage : get this on fd1");
				exit(1);
			}
		if ((error=PF_UnfixPage(fd,page_num,FALSE))!= PFE_OK){
				PF_PrintError("mygetpage : get this on fd");
					exit(1);
			}
		return;
	}

	// printf("Check1\n");

	int page_present[PF_MAX_BUFS];
	for(i = 0; i < PF_MAX_BUFS; i++) {
		page_present[i] = fd_list[i]*FILE_PAGE_COUNT + page_list[i];
		// printf("%d %d\n", i, page_present[i]);
	}

	// finding farthest here.
	int curr_farthest = -1;
	int curr_farthest_distance = 0;
	for(i=0; i<PF_MAX_BUFS; i++) {
		int j;
		// Finding next occurence of i th page in the buffer.
		for(j = start; j<operation_count; j++) {
			if(page_present[i] == page_order[j]) {
				if(j > curr_farthest_distance) {
					curr_farthest = i;
					curr_farthest_distance = j;
				}
				break;
			}
			// No occurence of i th page exists. So let's tag this as the farthest.
			if(j == operation_count-1) {
				curr_farthest = i;
				curr_farthest_distance = operation_count;
			}
		}
		if(curr_farthest_distance == operation_count) break;
	}
	// printf("Farthest buffer page is : %d with page no. : %d at distance : %d\n", page_present[curr_farthest], curr_farthest, curr_farthest_distance );

	int to_remove = curr_farthest;


	// printf("To remove : %d\n", to_remove);

	// /* print the buffer */
	// printf("buffer***************************************:\n");
	// PFbufPrint();
	// printf("***************************************buffer:\n");
	// Fixing all pages other than the farthest one
	for(i=0; i<PF_MAX_BUFS; i++) {
		if(i == to_remove) continue;
		if ((error=PF_FixPage(fd_list[i],page_list[i]))!= PFE_OK){
				PF_PrintError("mygetpage : page not fixed");
					exit(1);
			}
	}

	// /* print the buffer */
	// printf("buffer***************************************:\n");
	// PFbufPrint();
	// printf("***************************************buffer:\n");	

	// Getting the required page. This will replace the unfixed page.
	if ((error=PF_GetThisPage(fd,page_num,buf))!=PFE_OK){
			PF_PrintError("mygetpage : getting required page from buffer");
			exit(1);
		}

	// /* print the buffer */
	// printf("buffer***************************************:\n");
	// PFbufPrint();
	// printf("***************************************buffer:\n");
	
	list_count = PF_bufList(fd_list, page_list);
	// Unfixing all the pages
	for(i=0; i<PF_MAX_BUFS; i++) {
		if ((error=PF_UnfixPage(fd_list[i],page_list[i],FALSE))!= PFE_OK){
				printf("%d %d\n", fd_list[i], page_list[i]);
				PF_PrintError("mygetpage : unfix all the pages");
					exit(1);
			}
	}

	// /* print the buffer */
	// printf("buffer***************************************:\n");
	// PFbufPrint();
	// printf("***************************************buffer:\n");
}