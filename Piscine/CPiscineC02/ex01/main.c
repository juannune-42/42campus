/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:15:02 by juannune          #+#    #+#             */
/*   Updated: 2026/03/03 13:55:48 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);

int	main(int argc, char **argv)
{
	int	i;

	if (argc != 3)
		return (1);
	i = 0;
	while (argv[1][i])
		i++;
	printf("dest: %s\n", argv[1]);
	printf("src: %s\n", argv[2]);
	printf("%d\n", i);
	printf("dest: %s\n", ft_strncpy(argv[1], argv[2], i));
	return (0);
}
