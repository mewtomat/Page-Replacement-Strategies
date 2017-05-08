extern void
PF_Init( );

extern int
PF_CreateFile(char *fileName);
/*
	char	*fileName;	<  name of file  >

        returns errVal
*/

extern int
PF_DestroyFile(char *fileName);
/*
	char	*fileName;	<  name of file  >
	
	returns errVal
*/

extern int
PF_OpenFile(char *fileName);
/*
	char	*fileName;	<  name of file  >
	
	returns fileDesc
*/

extern int
PF_CloseFile(int fileDesc);
/*
	int	fileDesc;		<  file descriptor  >
	
	returns errVal
*/

extern int
PF_GetFirstPage(int fileDesc,int *pageNum,char **pageBuf);
/*
	int	fileDesc;		<  file descriptor  >
	int	*pageNum;	<  page number of first page  >
	char	**pageBuf;	<  indirect pointer to buffer  >
	
	returns errVal
*/

extern int
PF_GetNextPage(int fileDesc,int *pageNum,char **pageBuf);
/*
	int	fileDesc;		<  file descriptor  >
	int	*pageNum;	<  page number of first/next page  >
	char	**pageBuf;	<  indirect pointer to buffer  >
	
	returns errVal
*/

extern int 
PF_GetThisPage(int fileDesc,int pageNum,char **pageBuf);
/*
	int	fileDesc;		<  file descriptor  >
	int	pageNum;	<  page number of desired page  >
	char	**pageBuf;	<  indirect pointer to buffer  >
	
	returns errVal
*/

extern int
PF_AllocPage(int fileDesc,int *pageNum,char **pageBuf);
/*
	int	fileDesc;		<  file descriptor  >
	int	*pageNum;	<  page number of new page  >
	char	**pageBuf;	<  indirect pointer to buffer  >
	
	returns errVal
*/

extern int
PF_DisposePage(int fileDesc,int pageNum);
/*
	int	fileDesc;		<  file descriptor  >
	int	pageNum;	<  page number of old page  >
	
	returns errVal
*/

extern int
PF_UnfixPage(int fileDesc,int pageNum,int dirty);
/*
	int	fileDesc;		<  file descriptor  >
	int	pageNum;	<  page number of page  >
	int	dirty;		<  true if page is dirty  >
	
	returns errVal
*/

extern void
PF_PrintError(char *errString);
/*
	char	*errString;	<  string to write  >
*/


extern void PF_BufRelease();
extern int BufferSize();
extern void PF_bufPrint();

extern int
PF_FixPage(int fileDesc,int pageNum);
/*
	int	fileDesc;		<  file descriptor  >
	int	pageNum;	<  page number of page  >
	
	returns errVal
*/

int PF_bufList(int * fd_list, int * page_list);
/*
	int	* fd_list;	<  list of file descriptor of pages in buffer  >
	int	* page_list;	<  list of page number of pages in buffer  >
*/