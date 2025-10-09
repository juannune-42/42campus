/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:39:13 by juannune          #+#    #+#             */
/*   Updated: 2025/07/03 12:34:10 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_non_printable_to_hexadecimal(int str, char *hexa)
{
	char	*hex;

	hex = "0123456789abcdef";
	hexa[0] = hex[str / 16];
	hexa[1] = hex[str % 16];
}

void	ft_putstr_non_printable(char *str)
{
	char	hexa[2];

	hexa[0] = 0;
	hexa[1] = 0;
	while (*str)
	{
		if (*str < ' ' || *str == 127)
		{
			write(1, "\\", 1);
			ft_non_printable_to_hexadecimal(*str, hexa);
			write(1, &hexa[0], 1);
			write(1, &hexa[1], 1);
		}
		else
		{
			write(1, &*str, 1);
		}
		str++;
	}
}
