#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
# include "get_next_line.h"
# include <stdio.h>
 
int main ()
{
    int fd;
    int ret;
    int i;
    
    char *line;
    fd = open("to_open.txt", O_RDONLY);
    i = 0;
    line = "test";
    while (line)
    {
        line = get_next_line(fd);
        printf("buffer size: |%d|   line: |%s|      loop : |%d| \n", BUFFER_SIZE, line, i);
        printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
        i++;
        free(line);
    }
    line = NULL;
    free(line);
    close(fd);
    system("leaks a.out");
}
