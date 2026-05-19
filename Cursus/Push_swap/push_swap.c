/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 13:24:01 by juannune          #+#    #+#             */
/*   Updated: 2026/05/19 02:15:46 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sorter(t_node **stack_a, t_node **stack_b, int size)
{
	if (!is_stack_sorted(stack_a))
	{
		if (size == 2)
			sort_two(stack_a);
		else if (size == 3)
			sort_three(stack_a);
		else if (size == 4 || size == 5)
			sort_five(stack_a, stack_b, size);
		else
			sort_radix(stack_a, stack_b, size);
	}
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		size;

	if (argc < 2)
		return (0);
	stack_b = NULL;
	stack_a = ft_parser(argc, argv);
	if (!stack_a)
		return (1);
	size = ft_sizer(stack_a);
	ft_indexer(stack_a);
	ft_sorter(&stack_a, &stack_b, size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
