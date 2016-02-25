#include "../apue.h"
#include <pthread.h>

struct foo {
	int a, b, c, d;
};

void
printf_foo(const char *s, const struct foo *fp)
{
	printf(s);
	printf(" structer at 0x%x\n", (unsigned)fp);
	printf(" foo.a = %d\n", fp->a);
	printf(" foo.b = %d\n", fp->b);
	printf(" foo.c = %d\n", fp->c);
	printf(" foo.d = %d\n", fp->d);
}

void *
thr_fn1(void *arg)
{
	struct	foo f = {1, 2, 3, 4};

	printf_foo("thread 1 : \n", &f);
	printf("thread 1 ID :%lu\n", (unsigned long)pthread_self());
	pthread_exit((void*)&f);
}

void *
thr_fn2(void *arg)
{
	printf("thread 2 :ID is %lu\n", (unsigned long)pthread_self());
	return ((void*)0);
}

int
main(void)
{
	int	err;
	pthread_t	tid1, tid2;
	struct foo	*tret;
	
	err = pthread_create(&tid1, NULL, thr_fn1, NULL);
	if (err != 0)
		err_quit("can`t create thread1: %s", strerror(err));

	sleep(1);

	printf("main start second thread:\n");
	err = pthread_create(&tid2, NULL, thr_fn2, NULL);
	if (err != 0)
		err_quit("can`t create thread2: %s", strerror(err));

	err = pthread_join(tid1, (void*)&tret);
	if (err != 0)
		err_quit("can`t join thread1 : %s", strerror(err));
	sleep(1);
	printf_foo("main thread :", tret);
	exit(0);
}
