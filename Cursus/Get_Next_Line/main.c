#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd1 = open("file1.txt", O_RDONLY);
    int fd2 = open("file2.txt", O_RDONLY);
    char *line;

    // Read alternately FDs maintains each one's state
    while ((line = get_next_line(fd1)) != NULL) {
        printf("File1: %s", line); free(line);
        if ((line = get_next_line(fd2)) != NULL) {
            printf("File2: %s", line); free(line);
        }
    }
    close(fd1);
    close(fd2);
    return (0);
}