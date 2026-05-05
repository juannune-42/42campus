*This project has been created as part of the 42 curriculum by juannune.*
***
# PUSH_SWAP

## Index
1. Project Description
2. Instructions
3. Approach

---

## Project Description

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

Steps to install, compile and run the program.

### Installation
- Clone the repository -> git clone <URL_DEL_REPOSITORIO>
- cd push_swap
- Compile the program -> make.
- Run the program by passing a list of arguments:

	Example:

	1.		./push_swap 3 2 5 1 4

	2.		ARG=$(shuf -i 1-10000 -n 500 | tr '\n' ' ')
	
			./push_swap $ARG

---

## Approach

I used different functions for the cases with 2, 3 and 4 or 5 arguments. For more than 5 arguments, I used the radix sort algorithm with indexing. This approach uses the allowed operations.

void	sort_two(t_list **a)
{
	int	first;
	int	second;

	first = *(int *)(*a)-> content;
	second = *(int *)(*a)-> next -> content;
	if (first > second)
		sa(a);
}

void	sort_three(t_list **a)
{
	int	first;
	int	second;
	int	third;

	first = *(int *)(*a)-> content;
	second = *(int *)(*a)-> next -> content;
	third = *(int *)(*a)-> next -> next -> content;
	if (first > second && first < third)
		sa(a);
	else if (first > second && first > third && second < third)
		ra(a);
	else if (first > third && first < second)
		rra(a);
	else if (first < second && first < third && second > third)
	{
		sa(a);
		ra(a);
	}
	else if (first > second && first > third && second > third)
	{
		sa(a);
		rra(a);
	}
}

void	push_smallest_to_b(t_list **a, t_list **b)
{
	t_list	*tmp;
	int		min;
	int		pos;

	tmp = *a;
	min = *(int *)tmp->content;
	pos = 0;
	while (tmp)
	{
		if (*(int *)tmp->content < min)
		{
			min = *(int *)tmp->content;
			pos = 0;
		}
		tmp = tmp->next;
		pos++;
	}
	while (*(int *)(*a)->content != min)
	{
		if (pos <= ft_lstsize(*a) / 2)
			ra(a);
		else
			rra(a);
	}
	pb(a, b);
}

void	sort_five(t_list **a)
{
	t_list	*b;
	int		size;

	b = NULL;
	size = ft_lstsize(*a);
	if (size == 4)
	{
		push_smallest_to_b(a, &b);
		sort_three(a);
		pa(a, &b);
	}
	else if (size == 5)
	{
		push_smallest_to_b(a, &b);
		push_smallest_to_b(a, &b);
		sort_three(a);
		if (*(int *)(b->content) < *(int *)(b->next->content))
			sb(&b);
		pa(a, &b);
		pa(a, &b);
	}
}

void	radix_sort(t_list **a, int *nums, size_t size)
{
	t_list	*b;
	size_t	i;
	size_t	j;

	if (!a || !*a || size < 2)
		return ;
	b = NULL;
	sort_array(nums, size);
	i = 0;
	while (i < (size_t)max_bits(size))
	{
		j = 0;
		while (j < size)
		{
			if ((get_index(nums, size, *(int *)(*a)->content) >> i) & 1)
				ra(a);
			else
				pb(a, &b);
			j++;
		}
		while (b)
			pa(a, &b);
		i++;
	}
}