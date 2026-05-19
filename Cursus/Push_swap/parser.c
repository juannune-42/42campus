/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 14:05:42 by juannune          #+#    #+#             */
/*   Updated: 2026/05/19 02:02:50 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	parse_one_arg(char *str, t_node **stack_a)
{
	char	**args;
	int		j;

	args = ft_split(str, ' ');
	if (!args || !*args)
	{
		free_split(args);
		ft_putendl_fd("Error", 2);
		return (0);
	}
	j = 0;
	while (args[j])
	{
		if (!append_number(stack_a, args[j]))
		{
			free_split(args);
			ft_putendl_fd("Error", 2);
			return (0);
		}
		j++;
	}
	free_split(args);
	return (1);
}

t_node	*ft_parser(int argc, char **argv)
{
	t_node	*stack_a;
	int		i;

	stack_a = NULL;
	i = 1;
	while (i < argc)
	{
		if (!parse_one_arg(argv[i], &stack_a))
		{
			free_stack(&stack_a);
			return (NULL);
		}
		i++;
	}
	return (stack_a);
}
