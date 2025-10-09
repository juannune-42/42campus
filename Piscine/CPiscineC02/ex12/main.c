/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:15:02 by juannune          #+#    #+#             */
/*   Updated: 2025/06/25 17:31:55 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_print_memory(void *addr, unsigned int size);

int	main(void)
{
	char	str[] = "Bonjour les aminches\t\v\rc\n est fou\ntout\tce qu on peut faire avec\n\t\tprint_memory\t\t\n\nlol\nlol\t ";

	ft_print_memory(str, sizeof(str));
	return (0);
}
/*#include <unistd.h>

void	print_address(unsigned long addr)
{
	char	hex_digits[] = "0123456789abcdef";
	char	address_str[17];
	int		i;

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
	char	hex_digits[] = "0123456789abcdef";
	char	hex_byte[2];

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

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char	*ptr;
	unsigned int	i;
	unsigned int	j;

	ptr = (unsigned char *)addr;
	i = 0;
	if (size == 0)
		return (addr);
	while (i < size)
	{
		print_address((unsigned long)(ptr + i));
		// Imprimir contenido hexadecimal
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
		// Imprimir caracteres
		j = 0;
		while (j < 16 && i + j < size)
		{
			print_char(ptr[i + j]);
			j++;
		}
		write(1, "\n", 1);
		i += 16;
	}
	return (addr);
}

// Función main para probar
int	main(void)
{
	char	str[] = "Bonjour les aminches\t\n\v\rcoucou\ftout\tce qu on peut faire avec\n\nprint_memory\n\n\rlol.lol\r \0";

	ft_print_memory(str, sizeof(str));
	return (0);
}
*/