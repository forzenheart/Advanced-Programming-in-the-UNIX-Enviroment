#include "../apue.h"
#include <fcntl.h>

#define DATAFILE	"test1.text"
#define BUFFSIZE	4096

char	wrbuf[] = "ABCDEFGHIJ";

int	main(void)
{
	int	fd;
	int	n;
	off_t	ft;
	char	buf[BUFFSIZE];

	if ((fd = open(DATAFILE, O_RDWR | O_APPEND | O_CREAT | O_EXCL)) == -1) 
		if ((fd = open(DATAFILE, O_RDWR | O_APPEND)) == -1)
			err_sys("open file %s error",  DATAFILE);

	if ((write(fd, wrbuf, 10)) != 10)
		err_sys("write error");

	if ((ft = lseek(fd, 0l, SEEK_SET)) == -1)
		err_sys("lseek error");
	if ((n = read(fd, buf, BUFFSIZE)) < 0)
		err_sys("read error");

	printf("%s", buf);

	exit(0);
}
