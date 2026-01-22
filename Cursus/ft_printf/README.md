This proyect has been created as part of the 42 curriculum by juannune

Description

Instructions

Resources

A README.md file must be provided at the root of your Git repository. Its purpose is
to allow anyone unfamiliar with the project (peers, staff, recruiters, etc.) to quickly
understand what the project is about, how to run it, and where to find more information
on the topic.
The README.md must include at least:
• The very first line must be italicized and read: This project has been created as part
of the 42 curriculum by <login1>[, <login2>[, <login3>[...]]].
• A “Description” section that clearly presents the project, including its goal and a
brief overview.
• An “Instructions” section containing any relevant information about compilation,
installation, and/or execution.
• A “Resources” section listing classic references related to the topic (documen-
tation, articles, tutorials, etc.), as well as a description of how AI was used —
specifying for which tasks and which parts of the project.
➠ Additional sections may be required depending on the project (e.g., usage
examples, feature list, technical choices, etc.).
Any required additions will be explicitly listed below.
• A detailed explanation and justification of the chosen algorithm and data structure
must also be included.
The choice of language is at your discretion.
write in English, but it is not mandatory. :smile 

This proyect has been created as part of the 42 curriculum by juannune.



# Description

# Instructions

# Resources

ft_printf
Description

ft_printf is a custom implementation of the standard C library function printf.
Its goal is to reproduce the behavior of printf for a subset of the most commonly used format specifiers while respecting 42’s Norm and project constraints.​

The project is also an introduction to variadic functions in C (using va_start, va_arg, va_end) and to designing modular, extensible code that can be reused across future 42 projects (e.g., by integrating ft_printf into libft).​
Instructions
Compilation


Expected structure:

    Makefile

    ft_printf.h

    *.c source files (and possibly subfolders)

    Optionally: libft/ with your libft sources and Makefile if used.​

Basic usage:

bash
# Build the library
make

# Clean object files
make clean

# Full clean (objects + library)
make fclean

# Rebuild
make re

The Makefile must:

    Use cc with the flags -Wall -Wextra -Werror.

    Not relink unnecessarily.

    Provide at least the rules: $(NAME), all, clean, fclean, re.​

Linking and usage

To use ft_printf in your program:

bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o test

Example main.c:

c
#include "ft_printf.h"

int main(void)
{
    int len;

    len = ft_printf("Hello %s, number: %d, hex: %x\n", "world", 42, 42);
    ft_printf("Printed %d characters\n", len);
    return (0);
}

Supported conversions

ft_printf must implement the following format specifiers, with behavior mimicking the original printf as closely as possible (excluding buffer management):​

    %c : Prints a single character.

    %s : Prints a NUL-terminated string.

    %p : Prints a void * pointer in hexadecimal, usually with a 0x prefix.

    %d : Prints a signed decimal integer (base 10).

    %i : Same as %d.

    %u : Prints an unsigned decimal integer (base 10).

    %x : Prints an unsigned integer in lowercase hexadecimal (base 16).

    %X : Prints an unsigned integer in uppercase hexadecimal (base 16).

    %% : Prints a percent sign.​

The prototype is:

c
int ft_printf(const char *format, ...);

The return value is the total number of characters written, or a negative value in case of error (following standard printf behavior as closely as the subject and your design allow).​
Algorithm and design
High-level approach

    Parsing loop

        Iterate over the format string character by character.

        When a '%' is encountered, parse the next character as a conversion specifier.

        Otherwise, print the character directly and increase the printed length counter.

    Variadic argument handling

        Use a va_list to access the variable arguments:

            va_start(ap, format);

            va_arg(ap, type);

            va_end(ap);​

    Dispatcher per specifier

        Implement a small dispatcher that, given the specifier (c/s/p/d/i/u/x/X/%), calls the corresponding helper function:

            print_char

            print_string

            print_pointer

            print_signed

            print_unsigned

            print_hex_lower

            print_hex_upper

            print_percent

    Counting printed characters

        Each helper returns the number of characters printed or an error indicator.

        ft_printf accumulates this count and returns the total.

Internal data structures

    The project can be implemented without complex data structures; a simple state machine over the format string is sufficient.

    A small enum or set of functions for each specifier keeps the code modular and extensible for the bonus part (flags, width, precision).​

Error handling

    Check the result of write when printing to stdout.

    Propagate errors up to ft_printf when appropriate, so it can return a negative value.

    Ensure all memory allocated dynamically (if any) is freed before returning.​

Bonus (optional)

If the mandatory part is 100% correct and complete, the project allows implementing extra features:​

    Flags and width:

        - (left-justify)

        0 (zero padding)

        . (precision)

        Minimum field width

    Additional flags:

        # (alternate form, e.g. 0x prefix)

        space ( )

        + (explicit sign)

The recommended approach is to design the core parser with future extension in mind (e.g. a struct storing flags, width, precision, type), but remember: the bonus is evaluated only if the mandatory part is perfect.​
Resources

This section lists classic references and briefly describes how AI was used, as required by the subject.​
Documentation and articles

    C standard library references for printf and variadic functions (stdarg.h).​

    Online tutorials on:

        Variadic functions (va_start, va_arg, va_end).

        Number-to-string conversion in different bases (decimal, hex).​

    42 intranet resources and forum discussions related to ft_printf, project expectations, and common pitfalls.​

Use of AI in this project

    AI was used only for meta-support, not for producing project code:

        To help summarize the official ft_printf subject and extract its key requirements in natural language.​

        To get help drafting and structuring this README.md (sections, wording, explanation of algorithm and design choices).​

    All C code, algorithms, parsing logic, and implementation decisions were written, tested, and debugged manually without copying AI-generated code into the repository, in line with 42’s AI usage rules and the project’s AI instructions.​

You can extend this README with more sections (e.g., Usage examples, Testing strategy, Known limitations) as your implementation evolves.
