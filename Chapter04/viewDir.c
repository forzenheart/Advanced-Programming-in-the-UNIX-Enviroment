#include "apue.h"
#include <dirent.h>
#include <limits.h>
/* function type that is called for each file name */
typedef int Myfunc(const char *, const struct stat *, int);
static Myfunc	myfunc;
static int	myftw(char *, Myfunc *);
static int	dopath(Myfunc *);

static long	nreg, ndir, nblk, nfifo, nslink, nsock, ntot;

int	main(int argc, char *argv[])
{
	int	ret;
	if (argc != 2)
		err_quit("usage : ftw <starting-pathname>");

	ret = myftw(argv[1], myfunc);

	ntot = nreg + ndir + nblk + nfifo + nslink + nsock;
	if (ntot == 0)
		ntot = 1;
	printf("regular files	= %7ld, %5.2f, %%\n", nreg,	nreg	* 100.0 / ntot);
	printf("directories	= %7ld, %5.2f, %%\n", ndir,	ndir	* 100.0 / ntot);
	printf("block special	= %7ld, %5.2f, %%\n", nblk,	nblk	* 100.0 / ntot);
	printf("char specail	= %7ld, %5.2f, %%\n", nchr,	nchr	* 100.0 / ntot);
	printf("FIFOs		= %7ld, %5.2f, %%\n", nfifo,	nfifo	* 100.0 / ntot);
	printf("symbolic links	= %7ld, %5.2f, %%\n", nslink,	nslink	* 100.0 / ntot);
	printf("sockets		= %7ld, %5.2f, %%\n", nsock,	nsock	* 100.0 / ntot);

	exit(ret);
}

/*
 Descend through the hierarchy, starting at "pathname".
 The caller`s func() is called for every file.
 */

#define FTE_F	1 /* file other than directory directory */
#define FTW_D	2 /* directory */
#define FTW_DNR	3 /* directory that can`t be read*/
#define FTW_NS	4 /* file that we can`t  stat*/

static char	*fullpath; 
static int	myftw(char* pathname, Myfunc *func)
{
	int len;
	fullpath = path_alloc(&len); /* malloc`s for PATH_MAX+1 bytes*/

	strncpy(fullpath, pathname, len);/* protect against */
	fullpath[len - 1] = 0; /* buffer overrun*/

	return(dopath(func));
}

/* Decrend through the hierarchy, starting at "fullpath".
   if "fullpath" is anything other thana directory.we lstat it.
   call func(); and return. For a directory , we call ourself.
   recursively for each name in the directory.
 */

static int	dopath(Myfunc *func)
{
	struct stat	statbuf;
	struct dirent	*dirp;
	DIR		*dp;
	int		ret;
	char		*ptr;
}
