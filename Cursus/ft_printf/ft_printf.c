/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 03:26:49 by juannune          #+#    #+#             */
/*   Updated: 2026/01/06 04:02:13 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// char ft_bonus_conversion(va_list arg, char funct, int *len)
// {
// 	if (funct == ' ')
// 	{
// 		if (++funct == 'd' || funct == 'i')
// 			if (va_arg(arg, int) > -1)
// 				*len += write(1, " ", 1);
// 	}
// 	return (funct);
// }

static void	ft_conversion_specifier(va_list arg, char funct, int *len)
{
	if (funct == '%')
		return(write(1, "%", 1)); //como prueba
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

static void	ft_conversion_flag(va_list arg, char funct, int *len)
{
	if (funct == '-')
		else if (funct == '0') else if (funct == '') else if (funct == '') else if (funct == '-')
}

int	ft_conversion(va_list arg, char funct, int *len)
{
	return (ft_conversion_flag(arg, funct, len) + ft_conversion_width(arg,
			funct, len) + ft_conversion_presicion(arg, funct, len)
		+ ft_conversion_specifier(arg, funct, len))
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
			len += ft_conversion(arg, *str++, &len);
		else
			len += write(1, str++, 1);
	}
	va_end(arg);
	return (len);
}
