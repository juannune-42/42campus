/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:57:21 by juannune          #+#    #+#             */
/*   Updated: 2026/05/17 13:35:08 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_list **a)
{
	if ((*a)->value > (*a)->next->value)
		swap_a(a);
}

void	sort_three(t_list **a)
{
	int	x;
	int	y;
	int	z;

	x = (*a)->value;
	y = (*a)->next->value;
	z = (*a)->next->next->value;
	if (x > y && y < z && x > z)
		swap_a(a);
	else if (x > y && y > z)
	{
		swap_a(a);
		reverse_rotate_a(a);
	}
	else if (x > y && y > z && x < z)
		rotate_a(a);
	else if (x < y && y > z && x < z)
	{
		swap_a(a);
		rotate_a(a);
	}
	else if (x < y && y > z && x > z)
		reverse_rotate_a(a);
}

void	sort_five(t_list **a, t_list **b, int size)
{
	int	pushed;
	int	min;

	pushed = 0;
	while (pushed < size - 3)
	{
		min = 0;
		while ((*a)->index != min)
			rotate_a(a);
		push_b(a, b);
		pushed++;
		min++;
	}
	sort_three(a);
	while (pushed--)
		push_a(a, b);
}
