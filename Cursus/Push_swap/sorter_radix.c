/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_radix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 13:46:31 by juannune          #+#    #+#             */
/*   Updated: 2026/05/19 02:03:24 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_radix(t_node **a, t_node **b, int size)
{
	int	i;
	int	j;
	int	max_bits;

	i = 0;
	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*a)->index >> i) & 1) == 0)
				push_b(a, b);
			else
				rotate_a(a);
			j++;
		}
		while (*b)
			push_a(a, b);
		i++;
	}
}
