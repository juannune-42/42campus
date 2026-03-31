/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 12:07:58 by juannune          #+#    #+#             */
/*   Updated: 2026/03/31 13:28:04 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max);

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
	int	size;
	int	*range;

	if (argc != 3)
		return (0);
	range = 0;
	size = ft_atoi(argv[2]) - ft_atoi(argv[1]);
	ft_ultimate_range(&range, ft_atoi(argv[1]), ft_atoi(argv[2]));
	while (size--)
		printf("array[%d]: %d\n", size, range[size]);
	return (0);
}
