/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:39:13 by juannune          #+#    #+#             */
/*   Updated: 2026/03/06 13:42:10 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_non_printable_to_hexadecimal(int str, char *hexa)
{
	char	*hex;

	hex = "0123456789abcdef";
	hexa[1] = hex[str / 16];
	hexa[2] = hex[str % 16];
	return (hexa);
}

void	ft_putstr_non_printable(char *str)
{
	char	hexa[3];

	hexa[0] = '\\';
	while (*str)
	{
		if (*str < ' ' || *str == 127)
			write(1, ft_non_printable_to_hexadecimal(*str, hexa), 3);
		else
			write(1, str, 1);
		str++;
	}
}
