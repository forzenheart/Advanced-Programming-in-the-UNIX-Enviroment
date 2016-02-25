#include "../apue.h"
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

#define	CYCLETIMES 10
void *
thr_fn1(void *arg)
{
	int	i;
	
	for (i = 0; i < CYCLETIMES; i++)
		printf("this is thread 1\n");
	return ((void *)0);
}

void *
thr_fn2(void *arg)
{
	int	i;
	for (i = 0; i < CYCLETIMES; i++ )
		printf("this is thread2\n");
	pthread_exit((void *)1);
}

int
main(void)
{
	int	err;
	pthread_t	tid1, tid2;
	void	*tret;

	err = pthread_create(&tid1, NULL, thr_fn1, NULL);
	if (err != 0)
		err_quit("can`t create thread1: %s\n", strerror(err));
	err = pthread_create(&tid2, NULL, thr_fn2, NULL);
	if (err != 0)
		err_quit("can`t create thread2: %s\n", strerror(err));
	
	sleep(1);

	err = pthread_join(tid1, &tret);
	if (err != 0)
		err_quit("can`t join thread 1:%s\n", strerror(err));
	printf("thread 1 exit code :%d\n", (int)tret);

	err = pthread_join(tid2, &tret);
	if (err != 0)
		err_quit("can`t join thread 2:%s\n", strerror(err));
	printf("thread 2 exit code :%d\n", (int)tret);

	exit(0);
}
