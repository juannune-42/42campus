/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:15:02 by juannune          #+#    #+#             */
/*   Updated: 2026/03/06 12:53:09 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

unsigned int	ft_atoui(char *str)
{
	unsigned int	nbr;
	unsigned int	sign;

	sign = 1;
	nbr = 0;
	if (*str == '-' && ++str)
		sign = -1;
	while (*str)
		nbr = nbr * 10 + *str++ - '0';
	return (nbr * sign);
}

int	main(int argc, char **argv)
{
	unsigned int	size;

	if (argc != 4)
		return (0);
	size = ft_atoui(argv[3]);
	printf("dst: %s\n", argv[1]);
	printf("src: %s\n", argv[2]);
	printf("size: %s\n", argv[3]);
	printf("src size: %d\n", ft_strlcpy(argv[1], argv[2], size));
	printf("%s", argv[1]);
	return (0);
}
