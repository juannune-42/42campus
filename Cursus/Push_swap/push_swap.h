/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 03:10:56 by juannune          #+#    #+#             */
/*   Updated: 2026/05/05 03:51:46 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <limits.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

//Operations
void	swap_a(t_list **a);
void	swap_b(t_list **b);

void	push_a(t_list **b, t_list **a);
void	push_b(t_list **a, t_list **b);

void	rotate_a(t_list **b);
void	rotate_b(t_list **a);

void	reverse_rotate_b(t_list **b);
void	reverse_rotate_a(t_list **a);


void	swap(t_list **a, t_list **b);
void	rotate(t_list **a, t_list **b);
void	reverse_rotate(t_list **a, t_list **b);

//
t_list	ft_parser(int argc, char **argv);
int		ft_sizer(t_list *stack_a);
void	ft_indexer(t_list *stack_a);
void	free_stack(t_list **stack);

void	sort_two(t_list **stack_a);
void	sort_three(t_list **stack_a);
void	sort_five(t_list **stack_a, t_list **stack_b, int size);
void	sort_radix(t_list **stack_a, t_list **stack_b, int size);

#endif
