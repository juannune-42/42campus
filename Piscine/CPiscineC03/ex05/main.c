/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 02:56:09 by juannune          #+#    #+#             */
/*   Updated: 2026/03/20 12:52:33 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

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
	printf("Dest: %s\n", argv[1]);
	printf("Src: %s\n", argv[2]);
	printf("size: %s\n", argv[3]);
	printf("Result: %d\n", ft_strlcat(argv[1], argv[2], ft_atoi(argv[3])));
	printf("Dest: %s\n", argv[1]);
}
