/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 02:28:32 by juannune          #+#    #+#             */
/*   Updated: 2026/05/06 02:49:37 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_process_args(char **args, t_stack **stack_a)
{
	long	n;
	int		i;

	i = 0;
	while (args[i])
	{
		n = ft_atol(args[i], stack_a, args);
		if (ft_check_duplicates(*stack_a, (int)n))
		{
			ft_free_matrix(args);
			ft_error_exit(stack_a, NULL);
		}
		ft_stack_add_back(stack_a, ft_stack_new((int)n));
		i++;
	}
}

t_list  *ft_parser(int argc, char **argv)
{
    t_list  *stack_a;
    char    **args;
    int     i;

    stack_a = NULL;
    i = 0;
    while (++i < argc)
    {
        args = ft_split(argv[i], ' ');
        if (!args || !*args)
            if (args)
                free_split(args);
        ft_process_args(args, stack_a);
        free_split(array);
    }
    return (stack_a);
}
