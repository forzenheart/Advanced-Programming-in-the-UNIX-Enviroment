#include "../apue.h"
#include <sys/wait.h>

int	main(void)
{
	pid_t pid;

	if ((pid = fork()) < 0) {
		err_sys("fork error");
	} else if (pid == 0) {
		if ((pid = fork()) < 0) 
			err_sys("fork error");
		else if (pid > 0)
			exit (0); /* parent from second child == first child */
		/* second child process */
		


		sleep(2);
		printf("second child, parent pid= %d\n", getppid());
		printf("second child, pid	= %d\n", getpid());
		exit(0);
	}
	
	if (waitpid(pid,  NULL, 0) != pid) /* wait for the first child */
		err_sys("waitpid error");

	/* we are the original process, we continue executing, 
	  knowing that we are no the parent of second child.
	 */
	exit(0);
}
