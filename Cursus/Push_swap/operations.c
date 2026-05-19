/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 12:41:59 by juannune          #+#    #+#             */
/*   Updated: 2026/05/19 02:25:59 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_swap(t_node **stack_a, t_node **stack_b)
{
	if (stack_a && *stack_a && (*stack_a)->next)
		swap_a(stack_a);
	if (stack_b && *stack_b && (*stack_b)->next)
		swap_b(stack_b);
	ft_printf("ss\n");
}

void	rotate_rotate(t_node **stack_a, t_node **stack_b)
{
	if (stack_a && *stack_a && (*stack_a)->next)
		rotate_a(stack_a);
	if (stack_b && *stack_b && (*stack_b)->next)
		rotate_b(stack_b);
	ft_printf("rr\n");
}

void	reverse_rotate_both(t_node **stack_a, t_node **stack_b)
{
	if (stack_a && *stack_a && (*stack_a)->next)
		reverse_rotate_a(stack_a);
	if (stack_b && *stack_b && (*stack_b)->next)
		reverse_rotate_b(stack_b);
	ft_printf("rrr\n");
}
