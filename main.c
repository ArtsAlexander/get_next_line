#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	int fd;
	char *tmp;
	int ret;

	fd = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
	}

	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &tmp);
		printf("R %d | %s\n", ret, tmp);
		free(tmp);
		tmp = NULL;
	}
	return 0;
}
