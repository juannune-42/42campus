/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:52:40 by juannune          #+#    #+#             */
/*   Updated: 2026/05/17 13:15:22 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_indexer(t_list *stack)
{
	t_list	*cur;
	t_list	*cmp;
	int		idx;

	while (stack)
	{
		idx = 0;
		cmp = stack;
		while (cmp)
		{
			if (cmp->value < stack->value)
				idx++;
			cmp = cmp->next;
		}
		stack->index = idx;
		stack = stack->next;
	}
}
