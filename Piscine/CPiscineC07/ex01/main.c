/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 12:07:58 by juannune          #+#    #+#             */
/*   Updated: 2026/03/31 13:27:59 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	*ft_range(int min, int max);

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
	int	range;

	if (argc != 3)
		return (0);
	range = ft_atoi(argv[2]) - ft_atoi(argv[1]);
	while (range--)
		printf("array[%d]: %d\n", range, ft_range(ft_atoi(argv[1]),
				ft_atoi(argv[2]))[range]);
	return (0);
}
