#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int fd;
	char *tmp;

	fd = open("test.txt", O_RDONLY);

	while (get_next_line(fd, &tmp) != 0)
	{
		printf("%s", tmp);
	}

	return 0;
}
