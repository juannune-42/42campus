/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 12:07:58 by juannune          #+#    #+#             */
/*   Updated: 2026/03/31 13:26:38 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strdup(char *src);

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	printf("src: %s\n", argv[1]);
	printf("dup: %s\n", ft_strdup(argv[1]));
}
