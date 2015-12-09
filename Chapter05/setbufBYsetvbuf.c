#include "../apue.h"
#include <stdio.h>

void	MySetbuf(FILE *restrict fp, char *restrict buf)
{
	if (buf == NULL) {
		if ((setvbuf(fp, _IONBF)) != 0)
			err_sys("setbuf _IONBF err");
	} else {
		if ((setvbuf(fp, buf, _IOFBF, BUFSIZ )) != 0)
			err_sys("setbuf _IOFBF err");
	}
}
