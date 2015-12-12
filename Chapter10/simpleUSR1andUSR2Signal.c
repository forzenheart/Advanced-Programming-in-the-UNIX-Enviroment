#include "../apue.h"

static void sig_usr(int); /* one handler for both signals*/ 

int
main(void)
{
	if (signal(SIGUSR1, sig_usr) == SIG_ERR)
		err_sys("can`t catch SIGUSR1");
	if (signal(SIGUSR2, sig_usr) == SIG_ERR)
		err_sys("can`t catch SIGUSR2");
	for( ; ; )
		pause();
	return 0;
}

static void
sig_usr(int signo) /* argument is signal number*/ 
{
	if (signo == SIGUSR1)
		printf("recived SIGUSR1\n");
	else if (signo == SIGUSR2)
		printf("recived SIGUSR2\n");
	else
		err_dump("recived signal %d\n", signo);
}
