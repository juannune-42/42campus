/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 03:10:56 by juannune          #+#    #+#             */
/*   Updated: 2026/05/17 14:09:09 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}					t_list;

/* parser */
t_list				*ft_parser(int argc, char **argv);

/* utils*/
void				free_stack(t_list **stack);
int					ft_sizer(t_list *stack);
int					is_stack_sorted(t_list *stack);
long				ft_atol(const char *str);

/* indexer*/

/* operations */
void				swap_a(t_list **stack);
void				swap_b(t_list **stack);
void				swap_swap(t_list **stack_a, t_list **stack_b);
void				push_a(t_list **a, t_list **b);
void				push_b(t_list **a, t_list **b);
void				rotate_a(t_list **stack);
void				rotate_b(t_list **stack);
void				rotate_rotate(t_list **a, t_list **b);
void				reverse_rotate_a(t_list **stack);
void				reverse_rotate_b(t_list **stack);
void				reverse_rotate_both(t_list **a, t_list **b);

/* sorter */
void				sort_two(t_list **a);
void				sort_three(t_list **a);
void				sort_five(t_list **a, t_list **b, int size);
void				sort_radix(t_list **a, t_list **b, int size);
void				ft_sorter(t_list **a, t_list **b, int size);

#endif
