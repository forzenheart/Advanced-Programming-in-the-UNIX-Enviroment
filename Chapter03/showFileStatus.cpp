#include "../apue.h"
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int	val;

	if(argc != 2)
		err_quit("Usage: showFileStatus <descriptor#>");

	if((val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0)
		err_sys("fcntl error for %d", atoi(argv[1]));


	switch(val & O_ACCMODE) {
		case O_RDONLY:
			printf("read only\n");
			break;
		case O_WRONLY:
			printf("write only\n");
			break;
		case O_RDWR:
			printf("read & write \n");
			break;
		default:
			err_dump("unknown access mode");
	}

	if (val & O_APPEND)
		printf("append\n");

	if (val & O_NONBLOCK)
		printf("nonblock\n");

#if defined(O_SYNC)
	if (val & O_SYNC)
		printf("sync\n");
#endif

#if !defined(_POSIX_C_SOURCE) && defined(O_FSYNC)
	if (val & O_FSYNC)
		printf("synchronous writes\n");
#endif

	return 0;
}
