#include "../apue.h"
#include <errno.h>

static void
sig_hup(int signo)
{
	printf("SIGHUP received, pid = %d\n", getpid());
}

int
main(void)
{
	return 0;
}
