/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 12:46:30 by juannune          #+#    #+#             */
/*   Updated: 2026/05/20 16:01:39 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	is_number(const char *s)
{
	int	i;

	if (!s || !*s)
		return (0);
	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicate(t_node *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	append_number(t_node **stack, const char *str)
{
	long	n;
	t_node	*node;
	t_node	*tmp;

	if (!is_number(str))
		return (0);
	n = ft_atol(str);
	if (n < INT_MIN || n > INT_MAX || has_duplicate(*stack, (int)n))
		return (0);
	node = malloc(sizeof(t_node));
	if (!node)
		return (0);
	node->value = (int)n;
	node->index = -1;
	node->next = NULL;
	if (!*stack)
		*stack = node;
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
	return (1);
}
