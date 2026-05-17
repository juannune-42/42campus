*This project has been created as part of the 42 curriculum by juannune.*
***
# ft_printf

## Description
The goal of **ft_printf** function is to recreate the standard C **printf()** from **<stdio.h>** using variadic functions "**va_list**". It handles specifiers (cspdiuxX%) and bonus flags (-0.# +, width, precision) via direct **write** calls, returning printed chars count.

## Instructions
```
make        # Build the library, aoutputs **libftprintf.a**
make clean  # Clean objects files
make fclean # Full clean (objects + library)
make re     # Rebuild
./test;
```

# Basic Usage
for example, let's create a basic main.c file.
```
//Include the header
#include "ft_printf.h"

int main(void)
{
    // call the function
    ft_printf("Testing ft_printf!");
    return (0);
}
```
Compile the **main.c** file with the ft_printf library and run the program:
```
cc -Wall -Wextra -Werror main.c libft_printf.a -o test
```

## Algorithm and Design Choices
ft_printf iterates through the format string character by character using a loop. When a '%' is found, it parses flags (e.g., -, 0, #, +, width, precision), then identifies the specifier (c, s, p, d, i, u, x, X, %) and dispatches to handler functions via va_list (va_start, va_arg, va_end).

- **Variadics handling**: va_list stores variable args after the format string; va_arg advances the pointer by specifier type size (e.g., int for %d, char* for %s). Justification: Matches man 3 va_start for efficient, stack-based access without fixed args.
- **Parsing**: State machine-like loop checks '%' then flags/specifier sequentially. No data structures (arrays/trees) needed; simple char checks suffice for efficiency and low overhead. Handles bonuses by applying padding/precision before write().
- **Printing**: Direct write(1, ...) calls for chars/strings; recursive helpers for numbers (e.g., base conversion for x/X/u). Counter passed by pointer to track total chars returned. Justification: Mimics printf's int return for error checking; avoids stdio for speed/control.

This design prioritizes minimalism, correctness over libc printf, and extensibility for bonuses.


## Resources
* [**Gitbook**](https://42-cursus.gitbook.io/guide/1-rank-01/ft_printf)
* [**man 3 printf**](https://man7.org/linux/man-pages/man3/printf.3.html) (format specifiers/flags)
* [**man 3 va_start**](https://manpages.debian.org/testing/manpages-es-dev/va_start.3) va_arg va_end (variadics)
* [**42 subject PDF**](https://cdn.intra.42.fr/pdf/pdf/189888/en.subject.pdf) (mandatory vs bonus scope)
***

##### Use of AI in this project

    AI was used only for meta-support, not for producing project code:

        To help summarize the official ft_printf subject and extract its key requirements in natural language.​

        To get help drafting and structuring this README.md (sections, wording, explanation of algorithm and design choices).​

    All C code, algorithms, parsing logic, and implementation decisions were written, tested, and debugged manually without copying AI-generated code into the repository, in line with 42’s AI usage rules and the project’s AI instructions.​
