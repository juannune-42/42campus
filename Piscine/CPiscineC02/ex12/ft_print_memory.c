/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:39:01 by juannune          #+#    #+#             */
/*   Updated: 2025/06/30 09:34:11 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_address(unsigned long addr)
{
	char	*hex_digits;
	char	address_str[17];
	int		i;

	hex_digits = "0123456789abcdef";
	i = 15;
	while (i >= 0)
	{
		address_str[i] = hex_digits[addr & 0xF];
		addr >>= 4;
		i--;
	}
	write(1, address_str, 16);
	write(1, ":", 1);
	write(1, " ", 1);
}

void	print_hex(unsigned char c)
{
	char	*hex_digits;
	char	hex_byte[2];

	hex_digits = "0123456789abcdef";
	hex_byte[0] = hex_digits[c / 16];
	hex_byte[1] = hex_digits[c % 16];
	write(1, hex_byte, 2);
}

void	print_char(unsigned char c)
{
	if (c >= ' ' && c <= '~')
		write(1, &c, 1);
	else
		write(1, ".", 1);
}

void	logic(unsigned char *ptr, unsigned int i, unsigned int size)
{
	unsigned int	j;

	print_address((unsigned long)(ptr + i));
	j = 0;
	while (j < 16)
	{
		if (i + j < size)
			print_hex(ptr[i + j]);
		else
			write(1, "  ", 2);
		if (j % 2 == 1 && j < 15)
			write(1, " ", 1);
		j++;
	}
	write(1, " ", 1);
	j = 0;
	while (j < 16 && i + j < size)
	{
		print_char(ptr[i + j]);
		j++;
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char	*ptr;
	unsigned int	i;

	ptr = (unsigned char *)addr;
	i = 0;
	if (size == 0)
		return (addr);
	while (i < size)
	{
		logic(ptr, i, size);
		i += 16;
	}
	return (addr);
}
