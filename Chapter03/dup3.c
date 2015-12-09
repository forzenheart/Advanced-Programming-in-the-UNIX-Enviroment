#include "../apue.h"
#include <errno.h>
#include <limits.h>
#include <unistd.h>
#include <fcntl.h>

int	dup3(int filedes, int filedes2)
{
	long int	openMax = sysconf(_SC_OPEN_MAX);	/*最大文件描述符*/
	int	n;
	int	fd;
	int	array[openMax];	/* 保存使用dup打开的文件描述符. */
	int	ptr = 0;	/* 指向dup打开的当前文件描述符. */

	if (filedes > openMax) /* 超过系统限制的最大文件描述符. */
		err_sys("over _SC_OPEN_MAX");
	if (filedes == filedes2)	/* 相等则直接返回filedes2,不关闭 */
		return filedes;
	/* 若不相等，则先关闭filedes2 */
	if ((n = close(filedes)) < 0)
		err_sys("close filedes %d error", n);

	/*重复调用dup()直到找到符合要求的文件描述符*/
	do {
		if((fd = dup(filedes)) == -1) 
			err_sys("dup() error");
		else 
			array[ptr++] = fd;
	} while (fd != filedes2);
	//关闭其他不等于filedes的描述符
	ptr--;	/* 将指针前移一个，保存符合要求的文件描述符，然后关闭其他文件描述符　*/
	while (ptr > 0) {
		if ((n = close(array[--ptr])) < 0)	/* 注意此处是--ptr 不要关闭需要的filedes */
		err_sys("close filedes %d error", n);
	}
	return fd;
}

int	main(void)
{
	printf("new dup =	%d\n", dup3(1, 5));
	printf("new dup =	%d\n", dup(1));	/* 此处返回值为3，0 1 2已被标准输入　输出　标准错误输出占用 */
	printf("new dup =	%d\n", dup(1));
	printf("new dup =	%d\n", dup(1));
	exit (0);

}
