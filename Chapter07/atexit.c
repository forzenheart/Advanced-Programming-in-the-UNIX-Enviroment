#include "../apue.h"
#include <stdlib.h>

static void	myfunc1(void);
static void	myfunc2(void);

int	main(void)
{
	if (atexit(myfunc2) != 0)
		err_sys("atexit myfunc2 error");
	if (atexit(myfunc1) != 0)
		err_sys("atexit myfunc1 error");
	if (atexit(myfunc1) != 0)
		err_sys("atexit myfunc1 error");
	printf("main(void) is done\n");
	return (0);
}

static void	myfunc1(void)
{
	printf("myfunc1()\n");
}
static void	myfunc2(void)
{
	printf("myfunc2()\n");
}
