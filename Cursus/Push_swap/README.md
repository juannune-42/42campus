*This project has been created as part of the 42 curriculum by juannune.*
***
# PUSH_SWAP

## Index
1. Project Description
2. Instructions
3. Approach
4. Resources

---

## Description

Push_swap is a core 42 Network project that consists of developing a program that sorts a series of unique integers using two stacks and a limited set of operations.

The program receives integers as arguments and outputs a sequence of instructions to sort the numbers in Stack A.

These are all the operations we can use:
- **sa** (swap a): Swap the first two elements at the top of Stack A.  
    Do nothing if there is only one element or none.
- **sb** (swap b): Swap the first two elements at the top of Stack B.
- **ss** : **sa** and **sb** at the same time.
- **pa** (push a): Take the first element at the top of Stack B and push it at the top of Stack A.  
    Do nothing if Stack B is empty.
- **pb** (push b): Take the first element at the top of Stack A and push it at top of Stack B.  
    Do nothing if Stack A is empty.
- **ra** (rotate a): Shift up all elements of Stack A by one.  
    The first element becomes the last one.
- **rb** (rotate b): Shift up all elements of Stack B by one.  
    The first element becomes the last one.
- **rr** : **ra** and **rb** at the same time.
- **rra** (reverse rotate a): Shift down all elements of Stack A by one.  
    The last element becomes the first one.
- **rrb** (reverse rotate b): Shift down all elements of Stack B by one.
- **rrr** : **rra** and **rrb** at the same time.
---

## Instructions

Steps to install, compile, and run the program.

### Installation
- Clone the repository -> git clone <URL_DEL_REPOSITORIO>
- cd push_swap
### Compilation
- make				# Compiles the `push_swap` executable.
- make clean		# Removes object files (.o).
- make fclean		# Removes the object files and the executable.
- make re			# Recompiles the project from scratch.
### Execution
- Run the program by passing a list of arguments:

	Example:

	1.		./push_swap 3 2 5 1 4

    2.		shuf -i 0-9999 -n 100 > args.txt;./push_swap $(cat args.txt) > bench.txt | ./checker_linux $(cat args.txt); wc -l < bench.txt
---

## Approach

This project uses different strategies depending on the size of the input:

- **2 numbers**: a simple comparison is enough. If the two values are out of order, `sa` is used.
- **3 numbers**: the program handles all possible cases explicitly and applies the smallest valid combination of operations to sort the stack.
- **4 or 5 numbers**: the smallest values are pushed to stack **B**, the remaining values in stack **A** are sorted, and then the saved values are pushed back into **A** in the correct order.
- **More than 5 numbers**: the program uses an indexed **Radix Sort** approach. Each value is first assigned an index based on its position in the sorted order, then the algorithm sorts the stack bit by bit using only the allowed operations.

For larger inputs, Radix Sort is well suited to `push_swap` because it works efficiently with indexed values and can be adapted to two stacks using bitwise logic:

1. Each number is replaced by its sorted index.
2. Starting from the least significant bit, each index is checked bit by bit.
3. If the current bit is `0`, the value is pushed to stack **B** with `pb`.
4. If the current bit is `1`, stack **A** is rotated with `ra`.
5. After one full pass, all values in **B** are pushed back to **A** with `pa`.
6. The process is repeated until all relevant bits have been processed.

This approach keeps the implementation simple, deterministic, and efficient for medium and large input sizes.

## Resources

### Documentation
    - [Radix Sort wikipedia page.](https://en.wikipedia.org/wiki/Radix_sort)
    - [Push_swap Guide.](https://web.archive.org/web/20250305201542/https://42-cursus.gitbook.io/guide/rank-02/push_swap)

### IA Usage
AI assistance was used to support the development of this project in a few specific areas:

- **Refactoring**: reviewing and improving the parsing logic and `ft_atol` implementation.
- **Debugging**: helping identify memory management issues in error handling paths, especially around `ft_split`, stack cleanup, and invalid input cases.
- **Algorithm understanding**: clarifying how Radix Sort works when applied to two stacks using indexed values and bitwise operations.
- **Documentation**: improving the structure, clarity, and wording of the README.