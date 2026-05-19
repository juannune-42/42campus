/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:52:40 by juannune          #+#    #+#             */
/*   Updated: 2026/05/19 02:09:43 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_indexer(t_node *stack)
{
	t_node	*cur;
	t_node	*cmp;
	int		idx;

	cur = stack;
	while (cur)
	{
		idx = 0;
		cmp = stack;
		while (cmp)
		{
			if (cmp->value < cur->value)
				idx++;
			cmp = cmp->next;
		}
		cur->index = idx;
		cur = cur->next;
	}
}
