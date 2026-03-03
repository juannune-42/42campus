/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:07:55 by juannune          #+#    #+#             */
/*   Updated: 2026/03/03 13:28:21 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *stab, int size);

int	ft_atoi(char *str)
{
	int	nbr;
	int	sign;

	nbr = 0;
	sign = 1;
	if (*str == '-' && ++str)
		sign = -1;
	while (*str)
		nbr = nbr * 10 + *str++ - '0';
	return (nbr * sign);
}

int	main(int argc, char **argv)
{
	int	i;
	int	size;
	int	tab[100];

	if (argc < 2)
		return (0);
	i = 0;
	while (++i < argc)
		tab[i- 1] = ft_atoi(argv[i]);
	size = i - 1;
	ft_sort_int_tab(tab, size);
	i = 0;
	while (i < size)
		printf("%d ", tab[i++]);
	return (0);
}
//	int	tab[argc];
//	int	tab[] = {0};