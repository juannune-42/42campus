/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 02:56:09 by juannune          #+#    #+#             */
/*   Updated: 2026/03/20 12:51:53 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putnbr(int nb);

int	ft_atoi(char *str)
{
	int	nbr;
	int	sign;

	nbr = 0;
	sign = 1;
	if (*str == '-' && ++*str)
		sign = -1;
	while (*str)
		nbr = 10 * nbr + *str++ - '0';
	return (nbr * sign);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	ft_putnbr(ft_atoi(argv[1]));
	return (0);
}
