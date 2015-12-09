#include "../apue.h"

int	main(void)
{
	int	c;

	while ((c = getc(stdin)) != EOF) 
		if (putc(c, stdout) == EOF)
			err_sys("output err");

	if (ferror(stdin))
		err_sys("input err");

	exit(0);
}
