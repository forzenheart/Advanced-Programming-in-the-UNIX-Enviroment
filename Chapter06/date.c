#include "../apue.h"
#include <time.h>

#define MAXSIZE	1024

int	main(void)
{
	char		timebuf[MAXSIZE];
	struct	tm	*caltime;
	time_t		tt;


	if ((tt = time(NULL)) == -1)
		err_sys("fuction time error");

	if ((caltime = localtime(&tt)) == NULL)
		err_sys("localtime error");

	if (strftime(timebuf, MAXSIZE,
				"%Y 年 %m 月 %d 日 %A %X %Z", caltime) == 0)
		err_sys("strftime error");

	printf("%s\n", timebuf);

	exit(0);
}
