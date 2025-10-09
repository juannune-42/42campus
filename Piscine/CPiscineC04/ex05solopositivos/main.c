/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 02:56:09 by juannune          #+#    #+#             */
/*   Updated: 2025/07/03 09:27:14 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_atoi_base(char *str, char *base);

int	main(int argc, char **argv)
{
	char	*str;
	char	*base;

	if (argc != 3)
		return (0);
	str = argv[1];
	base = argv[2];
	printf("%d", ft_atoi_base(str, base));
	return (0);
}
