extern int AM_CreateIndex(char *fileName,int indexNo,int attrType,
		   int attrLength);

extern int AM_DestroyIndex(char *fileName,int indexNo);

extern int AM_InsertEntry(int fileDesc,char attrType,char attrLength, char *value,
		   int recId);

extern int AM_DeleteEntry(int fileDesc,char attrType, int attrLength,
		   char *value,int recId);

extern int AM_OpenIndexScan(int fileDesc,char attrType,int attrLength,int op,
		     char *value);

extern int AM_FindNextEntry(int scanDesc);

extern int AM_CloseIndexScan(int scanDesc);
