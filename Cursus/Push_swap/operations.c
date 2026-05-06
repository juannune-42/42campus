/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:53:13 by juannune          #+#    #+#             */
/*   Updated: 2026/05/06 16:00:36 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack, char type)
{
	t_list	*temp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = *stack;
	*stack = temp;
	ft_print("s%c\n", type);
}
void	push(t_list **reciver, t_list **giver, char type)
{
	t_list	*temp;

	if (!giver || !*giver)
		return ;
	temp = *reciver;
	*reciver = *giver;
	(*reciver)->next = *temp;
	*giver = (*giver)->next;
	ft_print("p%c\n", type);
}

void	rotate(t_list **stack, char type)
{
	t_list	*temp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	temp = *stack;
	temp->next = NULL;
	while ((*stack)->next != NULL)
		*stack = (*stack)->next;
	(*stack)->next = temp;
	ft_print("r%c\n", type);
}
