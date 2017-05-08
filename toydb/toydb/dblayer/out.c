# 1 "db.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "db.c"
# 1 "db.h" 1
# 1 "/usr/include/stdio.h" 1 3 4
# 27 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/features.h" 1 3 4
# 374 "/usr/include/features.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 1 3 4
# 385 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 386 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 2 3 4
# 375 "/usr/include/features.h" 2 3 4
# 398 "/usr/include/features.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 1 3 4
# 10 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/gnu/stubs-64.h" 1 3 4
# 11 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 2 3 4
# 399 "/usr/include/features.h" 2 3 4
# 28 "/usr/include/stdio.h" 2 3 4





# 1 "/usr/lib/gcc/x86_64-linux-gnu/4.8/include/stddef.h" 1 3 4
# 212 "/usr/lib/gcc/x86_64-linux-gnu/4.8/include/stddef.h" 3 4
typedef long unsigned int size_t;
# 34 "/usr/include/stdio.h" 2 3 4

# 1 "/usr/include/x86_64-linux-gnu/bits/types.h" 1 3 4
# 27 "/usr/include/x86_64-linux-gnu/bits/types.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 28 "/usr/include/x86_64-linux-gnu/bits/types.h" 2 3 4


typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;


typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;

typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;







typedef long int __quad_t;
typedef unsigned long int __u_quad_t;
# 121 "/usr/include/x86_64-linux-gnu/bits/types.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/typesizes.h" 1 3 4
# 122 "/usr/include/x86_64-linux-gnu/bits/types.h" 2 3 4


typedef unsigned long int __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long int __ino_t;
typedef unsigned long int __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned long int __nlink_t;
typedef long int __off_t;
typedef long int __off64_t;
typedef int __pid_t;
typedef struct { int __val[2]; } __fsid_t;
typedef long int __clock_t;
typedef unsigned long int __rlim_t;
typedef unsigned long int __rlim64_t;
typedef unsigned int __id_t;
typedef long int __time_t;
typedef unsigned int __useconds_t;
typedef long int __suseconds_t;

typedef int __daddr_t;
typedef int __key_t;


typedef int __clockid_t;


typedef void * __timer_t;


typedef long int __blksize_t;




typedef long int __blkcnt_t;
typedef long int __blkcnt64_t;


typedef unsigned long int __fsblkcnt_t;
typedef unsigned long int __fsblkcnt64_t;


typedef unsigned long int __fsfilcnt_t;
typedef unsigned long int __fsfilcnt64_t;


typedef long int __fsword_t;

typedef long int __ssize_t;


typedef long int __syscall_slong_t;

typedef unsigned long int __syscall_ulong_t;



typedef __off64_t __loff_t;
typedef __quad_t *__qaddr_t;
typedef char *__caddr_t;


typedef long int __intptr_t;


typedef unsigned int __socklen_t;
# 36 "/usr/include/stdio.h" 2 3 4
# 44 "/usr/include/stdio.h" 3 4
struct _IO_FILE;



typedef struct _IO_FILE FILE;





# 64 "/usr/include/stdio.h" 3 4
typedef struct _IO_FILE __FILE;
# 74 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/libio.h" 1 3 4
# 31 "/usr/include/libio.h" 3 4
# 1 "/usr/include/_G_config.h" 1 3 4
# 15 "/usr/include/_G_config.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/4.8/include/stddef.h" 1 3 4
# 16 "/usr/include/_G_config.h" 2 3 4




# 1 "/usr/include/wchar.h" 1 3 4
# 82 "/usr/include/wchar.h" 3 4
typedef struct
{
  int __count;
  union
  {

    unsigned int __wch;



    char __wchb[4];
  } __value;
} __mbstate_t;
# 21 "/usr/include/_G_config.h" 2 3 4
typedef struct
{
  __off_t __pos;
  __mbstate_t __state;
} _G_fpos_t;
typedef struct
{
  __off64_t __pos;
  __mbstate_t __state;
} _G_fpos64_t;
# 32 "/usr/include/libio.h" 2 3 4
# 49 "/usr/include/libio.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/4.8/include/stdarg.h" 1 3 4
# 40 "/usr/lib/gcc/x86_64-linux-gnu/4.8/include/stdarg.h" 3 4
typedef __builtin_va_list __gnuc_va_list;
# 50 "/usr/include/libio.h" 2 3 4
# 144 "/usr/include/libio.h" 3 4
struct _IO_jump_t; struct _IO_FILE;
# 154 "/usr/include/libio.h" 3 4
typedef void _IO_lock_t;





struct _IO_marker {
  struct _IO_marker *_next;
  struct _IO_FILE *_sbuf;



  int _pos;
# 177 "/usr/include/libio.h" 3 4
};


enum __codecvt_result
{
  __codecvt_ok,
  __codecvt_partial,
  __codecvt_error,
  __codecvt_noconv
};
# 245 "/usr/include/libio.h" 3 4
struct _IO_FILE {
  int _flags;




  char* _IO_read_ptr;
  char* _IO_read_end;
  char* _IO_read_base;
  char* _IO_write_base;
  char* _IO_write_ptr;
  char* _IO_write_end;
  char* _IO_buf_base;
  char* _IO_buf_end;

  char *_IO_save_base;
  char *_IO_backup_base;
  char *_IO_save_end;

  struct _IO_marker *_markers;

  struct _IO_FILE *_chain;

  int _fileno;



  int _flags2;

  __off_t _old_offset;



  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];



  _IO_lock_t *_lock;
# 293 "/usr/include/libio.h" 3 4
  __off64_t _offset;
# 302 "/usr/include/libio.h" 3 4
  void *__pad1;
  void *__pad2;
  void *__pad3;
  void *__pad4;
  size_t __pad5;

  int _mode;

  char _unused2[15 * sizeof (int) - 4 * sizeof (void *) - sizeof (size_t)];

};


typedef struct _IO_FILE _IO_FILE;


struct _IO_FILE_plus;

extern struct _IO_FILE_plus _IO_2_1_stdin_;
extern struct _IO_FILE_plus _IO_2_1_stdout_;
extern struct _IO_FILE_plus _IO_2_1_stderr_;
# 338 "/usr/include/libio.h" 3 4
typedef __ssize_t __io_read_fn (void *__cookie, char *__buf, size_t __nbytes);







typedef __ssize_t __io_write_fn (void *__cookie, const char *__buf,
     size_t __n);







typedef int __io_seek_fn (void *__cookie, __off64_t *__pos, int __w);


typedef int __io_close_fn (void *__cookie);
# 390 "/usr/include/libio.h" 3 4
extern int __underflow (_IO_FILE *);
extern int __uflow (_IO_FILE *);
extern int __overflow (_IO_FILE *, int);
# 434 "/usr/include/libio.h" 3 4
extern int _IO_getc (_IO_FILE *__fp);
extern int _IO_putc (int __c, _IO_FILE *__fp);
extern int _IO_feof (_IO_FILE *__fp) __attribute__ ((__nothrow__ , __leaf__));
extern int _IO_ferror (_IO_FILE *__fp) __attribute__ ((__nothrow__ , __leaf__));

extern int _IO_peekc_locked (_IO_FILE *__fp);





extern void _IO_flockfile (_IO_FILE *) __attribute__ ((__nothrow__ , __leaf__));
extern void _IO_funlockfile (_IO_FILE *) __attribute__ ((__nothrow__ , __leaf__));
extern int _IO_ftrylockfile (_IO_FILE *) __attribute__ ((__nothrow__ , __leaf__));
# 464 "/usr/include/libio.h" 3 4
extern int _IO_vfscanf (_IO_FILE * __restrict, const char * __restrict,
   __gnuc_va_list, int *__restrict);
extern int _IO_vfprintf (_IO_FILE *__restrict, const char *__restrict,
    __gnuc_va_list);
extern __ssize_t _IO_padn (_IO_FILE *, int, __ssize_t);
extern size_t _IO_sgetn (_IO_FILE *, void *, size_t);

extern __off64_t _IO_seekoff (_IO_FILE *, __off64_t, int, int);
extern __off64_t _IO_seekpos (_IO_FILE *, __off64_t, int);

extern void _IO_free_backup_area (_IO_FILE *) __attribute__ ((__nothrow__ , __leaf__));
# 75 "/usr/include/stdio.h" 2 3 4




typedef __gnuc_va_list va_list;
# 90 "/usr/include/stdio.h" 3 4
typedef __off_t off_t;
# 102 "/usr/include/stdio.h" 3 4
typedef __ssize_t ssize_t;







typedef _G_fpos_t fpos_t;




# 164 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/stdio_lim.h" 1 3 4
# 165 "/usr/include/stdio.h" 2 3 4



extern struct _IO_FILE *stdin;
extern struct _IO_FILE *stdout;
extern struct _IO_FILE *stderr;







extern int remove (const char *__filename) __attribute__ ((__nothrow__ , __leaf__));

extern int rename (const char *__old, const char *__new) __attribute__ ((__nothrow__ , __leaf__));




extern int renameat (int __oldfd, const char *__old, int __newfd,
       const char *__new) __attribute__ ((__nothrow__ , __leaf__));








extern FILE *tmpfile (void) ;
# 209 "/usr/include/stdio.h" 3 4
extern char *tmpnam (char *__s) __attribute__ ((__nothrow__ , __leaf__)) ;





extern char *tmpnam_r (char *__s) __attribute__ ((__nothrow__ , __leaf__)) ;
# 227 "/usr/include/stdio.h" 3 4
extern char *tempnam (const char *__dir, const char *__pfx)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) ;








extern int fclose (FILE *__stream);




extern int fflush (FILE *__stream);

# 252 "/usr/include/stdio.h" 3 4
extern int fflush_unlocked (FILE *__stream);
# 266 "/usr/include/stdio.h" 3 4






extern FILE *fopen (const char *__restrict __filename,
      const char *__restrict __modes) ;




extern FILE *freopen (const char *__restrict __filename,
        const char *__restrict __modes,
        FILE *__restrict __stream) ;
# 295 "/usr/include/stdio.h" 3 4

# 306 "/usr/include/stdio.h" 3 4
extern FILE *fdopen (int __fd, const char *__modes) __attribute__ ((__nothrow__ , __leaf__)) ;
# 319 "/usr/include/stdio.h" 3 4
extern FILE *fmemopen (void *__s, size_t __len, const char *__modes)
  __attribute__ ((__nothrow__ , __leaf__)) ;




extern FILE *open_memstream (char **__bufloc, size_t *__sizeloc) __attribute__ ((__nothrow__ , __leaf__)) ;






extern void setbuf (FILE *__restrict __stream, char *__restrict __buf) __attribute__ ((__nothrow__ , __leaf__));



extern int setvbuf (FILE *__restrict __stream, char *__restrict __buf,
      int __modes, size_t __n) __attribute__ ((__nothrow__ , __leaf__));





extern void setbuffer (FILE *__restrict __stream, char *__restrict __buf,
         size_t __size) __attribute__ ((__nothrow__ , __leaf__));


extern void setlinebuf (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));








extern int fprintf (FILE *__restrict __stream,
      const char *__restrict __format, ...);




extern int printf (const char *__restrict __format, ...);

extern int sprintf (char *__restrict __s,
      const char *__restrict __format, ...) __attribute__ ((__nothrow__));





extern int vfprintf (FILE *__restrict __s, const char *__restrict __format,
       __gnuc_va_list __arg);




extern int vprintf (const char *__restrict __format, __gnuc_va_list __arg);

extern int vsprintf (char *__restrict __s, const char *__restrict __format,
       __gnuc_va_list __arg) __attribute__ ((__nothrow__));





extern int snprintf (char *__restrict __s, size_t __maxlen,
       const char *__restrict __format, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 4)));

extern int vsnprintf (char *__restrict __s, size_t __maxlen,
        const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 0)));

# 412 "/usr/include/stdio.h" 3 4
extern int vdprintf (int __fd, const char *__restrict __fmt,
       __gnuc_va_list __arg)
     __attribute__ ((__format__ (__printf__, 2, 0)));
extern int dprintf (int __fd, const char *__restrict __fmt, ...)
     __attribute__ ((__format__ (__printf__, 2, 3)));








extern int fscanf (FILE *__restrict __stream,
     const char *__restrict __format, ...) ;




extern int scanf (const char *__restrict __format, ...) ;

extern int sscanf (const char *__restrict __s,
     const char *__restrict __format, ...) __attribute__ ((__nothrow__ , __leaf__));
# 443 "/usr/include/stdio.h" 3 4
extern int fscanf (FILE *__restrict __stream, const char *__restrict __format, ...) __asm__ ("" "__isoc99_fscanf")

                               ;
extern int scanf (const char *__restrict __format, ...) __asm__ ("" "__isoc99_scanf")
                              ;
extern int sscanf (const char *__restrict __s, const char *__restrict __format, ...) __asm__ ("" "__isoc99_sscanf") __attribute__ ((__nothrow__ , __leaf__))

                      ;
# 463 "/usr/include/stdio.h" 3 4








extern int vfscanf (FILE *__restrict __s, const char *__restrict __format,
      __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 2, 0))) ;





extern int vscanf (const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 1, 0))) ;


extern int vsscanf (const char *__restrict __s,
      const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__format__ (__scanf__, 2, 0)));
# 494 "/usr/include/stdio.h" 3 4
extern int vfscanf (FILE *__restrict __s, const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vfscanf")



     __attribute__ ((__format__ (__scanf__, 2, 0))) ;
extern int vscanf (const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vscanf")

     __attribute__ ((__format__ (__scanf__, 1, 0))) ;
extern int vsscanf (const char *__restrict __s, const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vsscanf") __attribute__ ((__nothrow__ , __leaf__))



     __attribute__ ((__format__ (__scanf__, 2, 0)));
# 522 "/usr/include/stdio.h" 3 4









extern int fgetc (FILE *__stream);
extern int getc (FILE *__stream);





extern int getchar (void);

# 550 "/usr/include/stdio.h" 3 4
extern int getc_unlocked (FILE *__stream);
extern int getchar_unlocked (void);
# 561 "/usr/include/stdio.h" 3 4
extern int fgetc_unlocked (FILE *__stream);











extern int fputc (int __c, FILE *__stream);
extern int putc (int __c, FILE *__stream);





extern int putchar (int __c);

# 594 "/usr/include/stdio.h" 3 4
extern int fputc_unlocked (int __c, FILE *__stream);







extern int putc_unlocked (int __c, FILE *__stream);
extern int putchar_unlocked (int __c);






extern int getw (FILE *__stream);


extern int putw (int __w, FILE *__stream);








extern char *fgets (char *__restrict __s, int __n, FILE *__restrict __stream)
     ;
# 638 "/usr/include/stdio.h" 3 4
extern char *gets (char *__s) __attribute__ ((__deprecated__));


# 665 "/usr/include/stdio.h" 3 4
extern __ssize_t __getdelim (char **__restrict __lineptr,
          size_t *__restrict __n, int __delimiter,
          FILE *__restrict __stream) ;
extern __ssize_t getdelim (char **__restrict __lineptr,
        size_t *__restrict __n, int __delimiter,
        FILE *__restrict __stream) ;







extern __ssize_t getline (char **__restrict __lineptr,
       size_t *__restrict __n,
       FILE *__restrict __stream) ;








extern int fputs (const char *__restrict __s, FILE *__restrict __stream);





extern int puts (const char *__s);






extern int ungetc (int __c, FILE *__stream);






extern size_t fread (void *__restrict __ptr, size_t __size,
       size_t __n, FILE *__restrict __stream) ;




extern size_t fwrite (const void *__restrict __ptr, size_t __size,
        size_t __n, FILE *__restrict __s);

# 737 "/usr/include/stdio.h" 3 4
extern size_t fread_unlocked (void *__restrict __ptr, size_t __size,
         size_t __n, FILE *__restrict __stream) ;
extern size_t fwrite_unlocked (const void *__restrict __ptr, size_t __size,
          size_t __n, FILE *__restrict __stream);








extern int fseek (FILE *__stream, long int __off, int __whence);




extern long int ftell (FILE *__stream) ;




extern void rewind (FILE *__stream);

# 773 "/usr/include/stdio.h" 3 4
extern int fseeko (FILE *__stream, __off_t __off, int __whence);




extern __off_t ftello (FILE *__stream) ;
# 792 "/usr/include/stdio.h" 3 4






extern int fgetpos (FILE *__restrict __stream, fpos_t *__restrict __pos);




extern int fsetpos (FILE *__stream, const fpos_t *__pos);
# 815 "/usr/include/stdio.h" 3 4

# 824 "/usr/include/stdio.h" 3 4


extern void clearerr (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));

extern int feof (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;

extern int ferror (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;




extern void clearerr_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
extern int feof_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int ferror_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;








extern void perror (const char *__s);






# 1 "/usr/include/x86_64-linux-gnu/bits/sys_errlist.h" 1 3 4
# 26 "/usr/include/x86_64-linux-gnu/bits/sys_errlist.h" 3 4
extern int sys_nerr;
extern const char *const sys_errlist[];
# 854 "/usr/include/stdio.h" 2 3 4




extern int fileno (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;




extern int fileno_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;
# 873 "/usr/include/stdio.h" 3 4
extern FILE *popen (const char *__command, const char *__modes) ;





extern int pclose (FILE *__stream);





extern char *ctermid (char *__s) __attribute__ ((__nothrow__ , __leaf__));
# 913 "/usr/include/stdio.h" 3 4
extern void flockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));



extern int ftrylockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;


extern void funlockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
# 943 "/usr/include/stdio.h" 3 4

# 2 "db.h" 2
# 48 "db.h"
extern int DBerrno;
# 61 "db.h"
extern void InitLnTable(void) ;
extern int ln2[129];

extern
int DBerrno;

extern
int _recordSize,_no_of_records,_recordStart ;




extern int
DB_CreateFile(char *fileName, int recordSize);







extern int
DB_AddRecord(int fileDesc, char *record, int recordSize);

extern void
DB_Init(void);

extern int
DB_GetRecord(int fileDesc, int *recId, char *record,
      int recordSize, char whence);
# 2 "db.c" 2
# 1 "am.h" 1
typedef struct am_leafheader
 {
  char pageType;
  int nextLeafPage;
  short recIdPtr;
  short keyPtr;
  short freeListPtr;
  short numinfreeList;
  short attrLength;
  short numKeys;
  short maxKeys;
 } AM_LEAFHEADER;

typedef struct am_intheader
 {
  char pageType;
  short numKeys;
  short maxKeys;
  short attrLength;
 } AM_INTHEADER ;

extern int AM_RootPageNum;
extern int AM_LeftPageNum;
extern int AM_Errno;
extern char *calloc();
extern char *malloc();
# 3 "db.c" 2
# 1 "pf.h" 1
# 44 "pf.h"
extern int PFerrno;
extern void PF_Init();
extern void PF_PrintError();
extern int ALGO;
extern int MISS;
extern int ACCESS;
# 4 "db.c" 2

# 1 "pflayer.h" 1
extern void
PF_Init( );

extern int
PF_CreateFile(char *fileName);






extern int
PF_DestroyFile(char *fileName);






extern int
PF_OpenFile(char *fileName);






extern int
PF_CloseFile(int fileDesc);






extern int
PF_GetFirstPage(int fileDesc,int *pageNum,char **pageBuf);
# 46 "pflayer.h"
extern int
PF_GetNextPage(int fileDesc,int *pageNum,char **pageBuf);
# 56 "pflayer.h"
extern int
PF_GetThisPage(int fileDesc,int pageNum,char **pageBuf);
# 66 "pflayer.h"
extern int
PF_AllocPage(int fileDesc,int *pageNum,char **pageBuf);
# 76 "pflayer.h"
extern int
PF_DisposePage(int fileDesc,int pageNum);







extern int
PF_UnfixPage(int fileDesc,int pageNum,int dirty);
# 95 "pflayer.h"
extern void
PF_PrintError(char *errString);
# 6 "db.c" 2
# 1 "amlayer.h" 1
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
# 7 "db.c" 2
# 1 "/usr/lib/gcc/x86_64-linux-gnu/4.8/include/stdarg.h" 1 3 4
# 8 "db.c" 2

int DBerrno=0;
int _recordSize,_no_of_records,_recordStart ;
# 19 "db.c"
int
initialise_header(char *pageBuf, int recordSize)
# 31 "db.c"
{
  int firstFree = -201,prevFree = -201;
  int recordStart,no_of_records;
  int bits_avail,first_approx,bitvect_size;

  bits_avail = (4096 -(2*sizeof(int)))*8;
  first_approx = bits_avail/(recordSize*8+1);
  bitvect_size = (first_approx+7)/8;
  recordStart = (2*sizeof(int)) + bitvect_size;
  no_of_records = (4096 - (2*sizeof(int)) - bitvect_size)/recordSize;

  if (no_of_records == 0)
    return -113 ;

  memcpy(pageBuf,&firstFree,sizeof(int));
  memcpy((pageBuf+=sizeof(int)),&prevFree,sizeof(int));
  memcpy((pageBuf+=sizeof(int)),&recordSize,sizeof(int));
  memcpy((pageBuf+=sizeof(int)),&recordStart,sizeof(int));
  memcpy((pageBuf+=sizeof(int)),&no_of_records,sizeof(int));

  return 0 ;
}



void
setPageParams(char *headerBuf)
{
  memcpy(&_recordSize,(headerBuf+=(2*sizeof(int))),sizeof(int));
  memcpy(&_recordStart,(headerBuf+=sizeof(int)),sizeof(int));
  memcpy(&_no_of_records,(headerBuf+=sizeof(int)),sizeof(int));
}

int
getNextFree(char *pageBuf)



{
  int pageNum;

  memcpy(&pageNum,pageBuf,sizeof(int));
  return pageNum;
}

void
initPage(char *pageBuf)






{
  int pagePtr = -201;

  memcpy(pageBuf,&pagePtr,sizeof(int));
  memcpy(pageBuf,&pagePtr,sizeof(int));
  memset(pageBuf+(2*sizeof(int)),0,_recordStart-(2*sizeof(int)));
  pageBuf[(2*sizeof(int))] = ~( (1 << (_no_of_records%8)) - 1 );
}

int
setFirstFreeSlot(char *pageBuf)




{
  int i,pos,byte=0;

  for (i=_recordStart-1;i>=(2*sizeof(int));i--)
    if (!( (pos=ln2[ (~pageBuf[i]) & ~((~pageBuf[i])-1) ]) < 0)) {
      pageBuf[i] = ( (pageBuf[i]) | (1 << (pos)) );
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
  return (((pageNum) * (_no_of_records+1) + (recordNo) +1));
}

int
pageIsFull(char *pageBuf)
{
  int i;



  for (i=(2*sizeof(int));i<_recordStart;i++)
    if (~pageBuf[i])
      return 0;
  return 1;
}

int
setNextFree(int fileDesc, int pageNum, int nextpageNum)







{
  char *pageBuf;

  { if((DBerrno=PF_GetThisPage(fileDesc,pageNum,&pageBuf)) < 0) { printf("err #: %d in %s\n",DBerrno, "setNextFree" ); return DBerrno ; } };
  memcpy(pageBuf,&nextpageNum,sizeof(int));
  { if((DBerrno=PF_UnfixPage(fileDesc,pageNum,1)) < 0) { printf("err #: %d in %s\n",DBerrno, "setNextFree" ); return DBerrno ; } };

  if (nextpageNum != -201) {
    { if((DBerrno=PF_GetThisPage(fileDesc,nextpageNum,&pageBuf)) < 0) { printf("err #: %d in %s\n",DBerrno, "setNextFree" ); return DBerrno ; } };
    memcpy(pageBuf+sizeof(int),&pageNum,sizeof(int));
    { if((DBerrno=PF_UnfixPage(fileDesc,nextpageNum,1)) < 0) { printf("err #: %d in %s\n",DBerrno, "setNextFree" ); return DBerrno ; } };
  }

  return 0;
}

int
checkSize(int size1,int size2)




{
  return ((size1 == size2) ? 0 : -101 ) ;
}

int ln2[129] ;
void
InitLnTable(void)





{
  int i,j=1;

  ln2[0] = -1;
  for (i=0; i<8; i++) {
    ln2[j] = i;
    j = j<<1;
  }
}




int
getFirstFilledSlot(char *pageBuf)
{
  int i,pos,byte=0;

  for (i=_recordStart-1;i>=(2*sizeof(int));i--)
    if (!( (pos=ln2[ (pageBuf[i]) & ~((pageBuf[i])-1) ]) < 0)) {



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
  return ( (pageBuf[_recordStart-1-byte]) & (1 << (pos)) );
}


int
nextFilledSlot(char *pageBuf, int recordNum)
{
  int byte,pos,nextRecNum;
  char temp;

  byte = recordNum / 8;
  pos = recordNum % 8;







  temp = ( (pageBuf[_recordStart-1-byte]) & ~( (1 << (pos+1)) - 1 ) );
  if (!( (pos=ln2[ (temp) & ~((temp)-1) ]) < 0))
    if ((nextRecNum = byte*8+pos) < _no_of_records) {



      return nextRecNum;
    }
    else
      return -203;
  else
    byte++;

  while (byte < (_recordStart-(2*sizeof(int))) )
    if (!( (pos=ln2[ (pageBuf[_recordStart-1-byte]) & ~((pageBuf[_recordStart-1-byte])-1) ]) < 0))
      if ((nextRecNum = byte*8+pos) < _no_of_records) {



 return nextRecNum;
      }
      else
 return -203;
    else
      byte++;

  return -203;
}


int
GetRecord(int pageNum, char *pageBuf, char *record, int recordNum,int whence)
{
  int recNum;
# 286 "db.c"
  switch(whence) {
  case 1:
    if ((recNum=getFirstFilledSlot(pageBuf)) < 0)
      return -202;
    else {
      memcpy(record,pageBuf+_recordStart+_recordSize*recNum,_recordSize);
      return ((pageNum) * (_no_of_records+1) + (recNum) +1);
    }
    break;

  case 3:
    if (isFilledSlot(pageBuf,recordNum)) {
      memcpy(record,pageBuf+_recordStart+_recordSize*recordNum,_recordSize);
      return ((pageNum) * (_no_of_records+1) + (recordNum) +1);
    }
    else
      return -204;
    break;

  case 2:
    if ((recNum=nextFilledSlot(pageBuf,recordNum)) < 0)
      return -203 ;
    else {
      memcpy(record,pageBuf+_recordStart+_recordSize*recNum,_recordSize);
      return ((pageNum) * (_no_of_records+1) + (recNum) +1);
    }
    break;
  }
}



void
DB_Init(void)




{
  PF_Init() ;

  InitLnTable() ;

}


int
 DB_CreateFile(char *fileName, int recordSize)
# 345 "db.c"
 {
   int fileDesc,pageNum;
   char *pageBuf;

   if ( recordSize <= 0 ) {
     printf("DB basic: record size = %d not possible \n ", recordSize);
     return -118 ;
   }



   { if((DBerrno=PF_CreateFile(fileName)) < 0) { printf("err #: %d in %s\n",DBerrno, "DB_CreateFile" ); return DBerrno ; } } ;


   { if((fileDesc=PF_OpenFile(fileName)) < 0) { printf("err #: %d in %s\n",fileDesc, "DB_CreateFile" ); return (DBerrno=fileDesc) ; } } ;


   if (PF_AllocPage(fileDesc,&pageNum,&pageBuf) != 0) {
     { if((DBerrno=PF_CloseFile(fileDesc)) < 0) { printf("err #: %d in %s\n",DBerrno, "DB_CreateFile" ); return DBerrno ; } } ;
     { if((DBerrno=PF_DestroyFile(fileName)) < 0) { printf("err #: %d in %s\n",DBerrno, "DB_CreateFile" ); return DBerrno ; } } ;
     return PFerrno ;
   }


   if (initialise_header (pageBuf,recordSize) != 0) {

     printf("DB Basic: DB_CreateFile: %d :size too large", -113);
      { if((DBerrno=PF_DisposePage(fileDesc,pageNum)) < 0) { printf("err #: %d in %s\n",DBerrno, "DB_CreateFile" ); return DBerrno ; } } ;
      { if((DBerrno=PF_CloseFile(fileDesc)) < 0) { printf("err #: %d in %s\n",DBerrno, "DB_CreateFile" ); return DBerrno ; } } ;
      { if((DBerrno=PF_DestroyFile(fileName)) < 0) { printf("err #: %d in %s\n",DBerrno, "DB_CreateFile" ); return DBerrno ; } } ;
      return -113 ;
    }

   if (PF_UnfixPage(fileDesc,pageNum,1) != 0) {
     { if((DBerrno=PF_CloseFile(fileDesc)) < 0) { printf("err #: %d in %s\n",DBerrno, "DB_CreateFile" ); return DBerrno ; } } ;
     { if((DBerrno=PF_DestroyFile(fileName)) < 0) { printf("err #: %d in %s\n",DBerrno, "DB_CreateFile" ); return DBerrno ; } } ;
     return PFerrno ;
   }


   { if((DBerrno=PF_CloseFile(fileDesc)) < 0) { printf("err #: %d in %s\n",DBerrno, "DB_CreateFile" ); return DBerrno ; } } ;

   return 0;
 }



int
DB_AddRecord(int fileDesc, char *record, int recordSize)
# 409 "db.c"
{
  int headerNum,pageNum;
  int recId ;
  char *headerBuf,*pageBuf ;


  { if((DBerrno=PF_GetFirstPage(fileDesc,&headerNum,&headerBuf)) < 0) { printf("err #: %d in %s\n",DBerrno, "DB_AddRecord" ); return DBerrno ; } } ;
  { if((DBerrno=PF_UnfixPage(fileDesc,headerNum,0)) < 0) { printf("err #: %d in %s\n",DBerrno, "DB_AddRecord" ); return DBerrno ; } } ;


  setPageParams (headerBuf) ;
  { if((DBerrno=checkSize(recordSize,_recordSize)) < 0) { printf("err #: %d in %s\n",DBerrno, "DB_AddRecord" ); return DBerrno ; } } ;



  if ( record == (char *) ((void *)0)) {

    printf("error in addrecord:db.c : null rec pointer \n");
    return -119 ;
  }

  if ( (pageNum = getNextFree(headerBuf)) == -201 ) {
    { if((DBerrno=PF_AllocPage(fileDesc,&pageNum,&pageBuf)) < 0) { printf("err #: %d in %s\n",DBerrno, "DB_AddRecord" ); return DBerrno ; } } ;
    initPage (pageBuf) ;
    recId = addRecord (pageNum,pageBuf,record) ;
    { if((DBerrno=PF_UnfixPage(fileDesc,pageNum,1)) < 0) { printf("err #: %d in %s\n",DBerrno, "DB_AddRecord" ); return DBerrno ; } } ;
    if ( ! pageIsFull(pageBuf) )
      { if((DBerrno=setNextFree (fileDesc,headerNum,pageNum)) < 0) { printf("err #: %d in %s\n",DBerrno, "DB_AddRecord" ); return DBerrno ; } } ;
  }
  else {
    { if((DBerrno=PF_GetThisPage(fileDesc,pageNum,&pageBuf)) < 0) { printf("err #: %d in %s\n",DBerrno, "DB_AddRecord" ); return DBerrno ; } } ;
    recId = addRecord (pageNum,pageBuf,record) ;
    { if((DBerrno=PF_UnfixPage(fileDesc,pageNum,1)) < 0) { printf("err #: %d in %s\n",DBerrno, "DB_AddRecord" ); return DBerrno ; } } ;
    if ( pageIsFull(pageBuf) )
      { if((DBerrno=setNextFree (fileDesc,headerNum,getNextFree(pageBuf))) < 0) { printf("err #: %d in %s\n",DBerrno, "DB_AddRecord" ); return DBerrno ; } } ;
  }




  printf("successfully record inserted\n");
  return recId ;
}

int
DB_GetRecord(int fileDesc, int *recId, char *record,
      int recordSize, char whence)
# 476 "db.c"
{
  int headerNum,pageNum,recordNum;
  char *headerBuf,*pageBuf ;
  int found = 0 ;

  { if((DBerrno=PF_GetFirstPage(fileDesc,&headerNum,&headerBuf)) < 0) { printf("err #: %d in %s\n",DBerrno, "DB_GetRecord" ); return DBerrno ; } } ;
  { if((DBerrno=PF_UnfixPage(fileDesc,headerNum,0)) < 0) { printf("err #: %d in %s\n",DBerrno, "DB_GetRecord" ); return DBerrno ; } } ;

  setPageParams (headerBuf) ;
  { if((DBerrno=checkSize(recordSize,_recordSize)) < 0) { printf("err #: %d in %s\n",DBerrno, "DB_GetRecord" ); return DBerrno ; } } ;

  if ( record == (char *) ((void *)0)) {


     printf("DB_GetRecord: error null record pointer:%d\n",-119 );
     return -119;
  }

  switch(whence) {

  case 1 :
    pageNum = headerNum ;
    while ( found == 0 ) {
       { if ((DBerrno = PF_GetNextPage(fileDesc,&pageNum,&pageBuf)) == -104 ) return -104 ; else if ( DBerrno != 0 ) { printf("Invalid page error: %d in %s\n",-116 , "DB_GetRecord" ); return -116 ; } { if((DBerrno=PF_UnfixPage(fileDesc,pageNum,0)) < 0) { printf("err #: %d in %s\n",DBerrno, "DB_GetRecord" ); return DBerrno ; } } ; } ;
       if ( (*recId = GetRecord(pageNum,pageBuf,record,0,1))
     != -202 )
  found = 1 ;
    }
    return 0 ;

  case 2 :
  case 3 :
    pageNum = ((*recId) / (_no_of_records+1)) ;
    recordNum = (((*recId) % (_no_of_records+1)) - 1) ;
    if (pageNum == headerNum) { printf("err: DBE_HEADERRECORD #: %d in %s\n",-117 , "DB_GetRecord" ); return -117; } ;

    { if ((DBerrno = PF_GetThisPage(fileDesc,pageNum,&pageBuf)) == -14 ) return -104 ; else if ( DBerrno != 0 ) { printf("err: DBE_INVALIDPAGE #: %d in %s\n",-116 , "DB_GetRecord" ); return -116 ; } { if((DBerrno=PF_UnfixPage(fileDesc,pageNum,0)) < 0) { printf("err #: %d in %s\n",DBerrno, "DB_GetRecord" ); return DBerrno ; } } ; } ;
    *recId = GetRecord(pageNum,pageBuf,record,recordNum,whence) ;

    if ((*recId == -204) ||
 (*recId == -202 )) {
 if ( whence == 3 ) {

       printf("err: DBE_INVALIDRECORD #: %d in %s\n",-102 , "DB_Getrecord" );
   return -102 ;
 }
    }
    else if (*recId != -203)
 found = 1 ;

    if ( whence == 2 ) {
      while ( found == 0 ) {
 { if ((DBerrno = PF_GetNextPage(fileDesc,&pageNum,&pageBuf)) == -104 ) return -104 ; else if ( DBerrno != 0 ) { printf("Invalid page error: %d in %s\n",-116 , "DB_GetRecord" ); return -116 ; } { if((DBerrno=PF_UnfixPage(fileDesc,pageNum,0)) < 0) { printf("err #: %d in %s\n",DBerrno, "DB_GetRecord" ); return DBerrno ; } } ; } ;
 if ( (*recId = GetRecord(pageNum,pageBuf,record,0,1) )
     != -202 )
   found = 1 ;
      }
    }
    return 0 ;

  default :

    printf("err: DBE_WHNECE #: %d in %s\n",-103 , "DB_GetRecord" );
    return -103 ;
  }
}
