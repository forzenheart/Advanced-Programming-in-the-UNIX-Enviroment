#include "../apue.h"

int	glob = 6;
char	buf[] = "a write to stdout\n";

int	main(void)
{
	int	var;
	pid_t	pid;

	if (write(STDOUT_FILENO, buf, sizeof(buf) - 1) != sizeof(buf) - 1)
		err_sys("write error");
	printf("before fork()\n");

	if (fflush(stdout) == EOF)
		err_sys("fflush(stdout) error");

	if ((pid = fork()) == -1) {
		err_sys("fork() error");
	}
	else if (pid == 0){
		glob++;
		var++;
	}
	else {
		sleep(2);
	}

	printf("pid = %d,  glob = %d, var = %d\n", getpid(), glob, var);

	exit(0);
}
