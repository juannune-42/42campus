*This project has been created as part of the 42 curriculum by juannune.*
***
# Get_Next_Line

## Description
**Get Next Line (GNL)** is a core 42 Network project that implements a C function to read lines from any *file descriptor* (files, stdin), returning each complete line with its *newline character* ('\n') except the last line if it lacks one. Repeated calls maintain state via static variables, enabling efficient line-by-line reading without reloading the entire file.

#### Main objectives:
- Handle efficient reading from any *file descriptor* (files, stdin).
- Use **static** variables to maintain state between calls.
- Implement optimized auxiliary utilities.
- Manage dynamic memory without leaks.
- Work with any **BUFFER_SIZE** defined at compilation.

**GNL** introduces key concepts such as static variables, buffer management, and efficient memory handling in C.

## Instructions
```bash
# Mandatory compilation with 42 flags and BUFFER_SIZE variable
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 *.c

# Examples with different buffer sizes
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 *.c
cc -Wall -Wextra -Werror -D BUFFER_SIZE=9999 *.c
```

#### Basic Use (mandatory):
```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("archivo.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

#### Bonus use (multiple FDs simultaneous)
```c
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
```
>Note to always free memory returned by get_next_line().

## Algorithm and Design Choices

#### Mandatory algorithm (a static variable):
```
1. Read BUFFER_SIZE bytes from fd using read()
2. If read() returns 0 (EOF) -> return NULL
3. If read() returns -1 (error) -> return NULL
4. Search '\n' in buffer using ft_strchr
5. If finds '\n': extract line, save rest in static
6. If not: accumulate in static, reread
7. EOF without  '\n': returns last line
```

#### Bonus algorithm (multiple FDs):
```
1. Static char *stash[OPEN_MAX]; // Array for each FD (0-1024)
2. If stash[fd] exists and has '\n': extract line from stash[fd]
3. Read BUFFER_SIZE -> concatenate to stash[fd] if not empty
4. Search '\n' in complete stash[fd] using ft_strchr
5. If finds '\n': extract line, save the rest in static
6. If not: accumulate in static, reread
7. EOF without '\n': returns last line
```

#### Bonus design justification:
- Only one static variable: static char *stash[OPEN_MAX] manages all FDs.
- Efficiency: Just read when stash[fd] is empty or without '\n'. 
- Scalability: Supports up to  1024 FDs simultaneously (OPEN_MAX).
- Memory: free(stash[fd]) when each FD finishes completely.

#### Files structure
```
# Mandatory
get_next_line.c             -> Main function (1 FD)
get_next_line.h             -> Prototypes
get_next_line_utils.c       -> Basic utilities

# Bonus
get_next_line_bonus.c       -> Multi-FD function
get_next_line_bonus.h       -> Bonus prototypes
get_next_line_utils_bonus.c -> Optimized utilities
```

## Resources

#### Official documentation
- [read(2)](https://man7.org/linux/man-pages/man2/read.2.html)
- [malloc(3)](https://man7.org/linux/man-pages/man3/malloc.3.html)
- static variables in C

#### Useful references
- 42 gitbook
- 42 Norminette
- Conditional compilation -D
- OPEN_MAX Fds limits

## Use of AI
AI was used only for:
- Conceptual aid about static variables and multi-FD management.
- Norminette validation, flags and compilation instructions.
- Structuring of this README.md.
- No source code, algorithms and solutions were AI generated .
