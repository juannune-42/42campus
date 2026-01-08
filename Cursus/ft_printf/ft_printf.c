/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 03:26:49 by juannune          #+#    #+#             */
/*   Updated: 2026/01/08 04:05:36 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_conversion(va_list arg, char funct, int *len)
{
	if (funct == '%')
		*len += write(1, "%", 1);
	else if (funct == 'c')
		*len += ft_putchar((char)va_arg(arg, int));
	else if (funct == 's')
		*len += ft_putstr(va_arg(arg, char *));
	else if (funct == 'p')
		*len += ft_putp(va_arg(arg, void *));
	else if (funct == 'd' || funct == 'i')
		*len += ft_putnbr(va_arg(arg, int));
	else if (funct == 'u')
		*len += ft_putunsigned(va_arg(arg, unsigned int));
	else if (funct == 'x')
		*len += ft_puthex(va_arg(arg, unsigned int), "0123456789abcdef");
	else if (funct == 'X')
		*len += ft_puthex(va_arg(arg, unsigned int), "0123456789ABCDEF");
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		len;

	va_start(arg, str);
	len = 0;
	while (*str)
	{
		if (*str == '%' && *++str)
			ft_conversion(arg, *str++, &len);
		else
			len += write(1, str++, 1);
	}
	va_end(arg);
	return (len);
}
