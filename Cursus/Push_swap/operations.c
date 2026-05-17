/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 12:41:59 by juannune          #+#    #+#             */
/*   Updated: 2026/05/17 14:10:32 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_swap(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (stack_a && *stack_a && (*stack_a)->next)
		swap_a(stack_a);
	if (stack_b && *stack_b && (*stack_b)->next)
		swap_b(stack_b);
	ft_printf("ss\n");
}

void	rotate_rotate(t_list **stack_a, t_list **stack_b)
{
	t_list	*first;
	t_list	*second;

	if (stack_a && *stack_a && (*stack_a)->next)
		rotate_a(stack_a);
	if (stack_b && *stack_b && (*stack_b)->next)
		rotate_b(stack_b);
	ft_printf("rr\n");
}

static void	reverse_rotate_both(t_list **stack_a, t_list **stack_b)
{
	t_list	*first;
	t_list	*second;

	if (stack_a && *stack_a && (*stack_a)->next)
		reverese_rotate_a(stack_a);
	if (stack_b && *stack_b && (*stack_b)->next)
		reverse_rotate_b(stack_b);
	ft_printf("rrr\n");
}
