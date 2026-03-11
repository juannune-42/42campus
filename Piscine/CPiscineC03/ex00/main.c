/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 02:56:09 by juannune          #+#    #+#             */
/*   Updated: 2026/03/11 13:28:53 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strcmp(char *s1, char *s2);

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (0);
	printf("Comparing \"%s\" ", argv[1]);
	printf("and \"%s\"", argv[2]);
	printf(": %d\n", ft_strcmp(argv[1], argv[2]));
	return (0);
}
