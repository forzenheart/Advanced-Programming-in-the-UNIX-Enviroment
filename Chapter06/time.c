#include "../apue.h"
#include <time.h>

int	main(void)
{
	//time_t	tt;

	printf("sizeof time_t = %ld\n", sizeof(time_t));
	long int	maxtime = 0x7FFFFFFF + 1;
	printf("maxtime =	%ld\n"
		"maxyear =	%ld\n", maxtime, maxtime / 31622400 + 1970);
	exit(0);
}
