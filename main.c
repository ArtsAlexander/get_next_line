#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

int        main(int ac, char **av)
{
    char    *line;
    int        nb_line;
    int        fd;

    if (ac < 1)
        return (0);
    nb_line = 1;
    if ((fd = open(av[1], O_RDONLY)) == -1)
        printf("le fichier n'existe pas.");
    line = NULL;
    int ret = 0;
    while ((ret = get_next_line(fd, &line)) > 0 && nb_line)
    {
        printf("return-value[%d]: %s\n", ret, line);
        free(line);
        line = NULL;
        nb_line++;
    }
    printf("return-value[%d]: %s\n", ret, line);
    free(line);
    line = NULL;
}
