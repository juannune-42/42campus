/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 02:56:09 by juannune          #+#    #+#             */
/*   Updated: 2026/03/13 12:36:51 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n);

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
	if (argc != 4)
		return (0);
	printf("Comparing \"%s\" ", argv[1]);
	printf("and \"%s\"", argv[2]);
	printf(": %d\n", ft_strncmp(argv[1], argv[2], ft_atoi(argv[3])));
	return (0);
}
