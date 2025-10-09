/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 01:31:13 by juannune          #+#    #+#             */
/*   Updated: 2025/06/22 01:40:03 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

void	ft_putchar(char c);
void	ft_putnbr(int n);
void	print_error(void);
int		parse_input(char *str, int *views);
void	print_solution(int grid[4][4]);

#endif
