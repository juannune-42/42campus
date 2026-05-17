/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:53:13 by juannune          #+#    #+#             */
/*   Updated: 2026/05/17 13:19:49 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **stack)
{
	t_list	*temp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = *stack;
	*stack = temp;
	ft_printf("sa\n");
}

void	push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (!stack_b || !*stack_b)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = *stack_a;
	*stack_a = temp;
	ft_printf("pa\n");
}

void	rotate_a(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = *stack;
	*stack = (*stack)->next;
	while (second->next)
		second = second->next;
	second->next = first;
	first->next = NULL;
	ft_printf("ra\n");
}

void	reverse_rotate_a(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = *stack;
	while (first->next)
		first = first->next;
	while (second->next != first)
		second = second->next;
	first->next = *stack;
	second->next = NULL;
	*stack = first;
	ft_printf("rra\n");
}
