/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 22:49:36 by juannune          #+#    #+#             */
/*   Updated: 2025/07/04 01:24:31 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb);

int	main(int argc, char **argv)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	num = 0;
	while (argv[1][i] == ' ' || argv[1][i] == '\t' || argv[1][i] == '\n'
		|| argv[1][i] == '\v' || argv[1][i] == '\f' || argv[1][i] == '\r')
		i++;
	while (argv[1][i] == '+' || argv[1][i] == '-')
	{
		if (argv[1][i] == '-')
			sign = -sign;
		i++;
	}
	while (argv[1][i] >= '0' && argv[1][i] <= '9')
	{
		num = num * 10 + (argv[1][i] - '0');
		i++;
	}
	if (argc != 2)
		return (0);
	printf("%d", ft_sqrt(sign * num));
	return (0);
}
