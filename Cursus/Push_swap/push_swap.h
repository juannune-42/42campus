/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 03:10:56 by juannune          #+#    #+#             */
/*   Updated: 2026/05/20 16:00:24 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

/* parser */
t_node				*ft_parser(int argc, char **argv);
void				free_split(char **split);
int					is_number(const char *s);
int					has_duplicate(t_node *stack, int value);
int					append_number(t_node **stack, const char *str);

/* utils*/
void				free_stack(t_node **stack);
int					ft_sizer(t_node *stack);
int					is_stack_sorted(t_node **stack);
long				ft_atol(const char *str);

/* indexer*/
void				ft_indexer(t_node *stack);

/* operations */
void				swap_a(t_node **stack);
void				swap_b(t_node **stack);
void				swap_swap(t_node **stack_a, t_node **stack_b);
void				push_a(t_node **a, t_node **b);
void				push_b(t_node **a, t_node **b);
void				rotate_a(t_node **stack);
void				rotate_b(t_node **stack);
void				rotate_rotate(t_node **a, t_node **b);
void				reverse_rotate_a(t_node **stack);
void				reverse_rotate_b(t_node **stack);
void				reverse_rotate_both(t_node **a, t_node **b);

/* sorter */
void				sort_two(t_node **a);
void				sort_three(t_node **a);
void				sort_five(t_node **a, t_node **b, int size);
void				sort_radix(t_node **a, t_node **b, int size);

#endif
