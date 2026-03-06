/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:15:02 by juannune          #+#    #+#             */
/*   Updated: 2026/03/03 14:00:39 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	ft_str_is_alpha(char *str);

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	printf("%s\n", argv[1]);
	printf("%d", ft_str_is_alpha(argv[1]));
	return (0);
}
