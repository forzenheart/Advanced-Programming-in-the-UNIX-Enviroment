#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int
main(void)
{
	int fd;
	if ((fd = creat("file.nohole", FILE_MODE)) < 0)
		printf("creat error\n");

	if (write(fd, buf1, 10) != 10)
		printf("write error\n");

	if (lseek(fd, 16374, SEEK_SET) == -1)
		printf("lseek error\n");

	if (write(fd, buf2, 10) != 10)
		printf("write error\n");

	return 0;
}
