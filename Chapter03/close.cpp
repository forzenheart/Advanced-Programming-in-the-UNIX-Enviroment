#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int
main()
{
	int	n;

	if ((n = close(STDOUT_FILENO))  ==  0)
		printf("error\n");
	return 0;
}
