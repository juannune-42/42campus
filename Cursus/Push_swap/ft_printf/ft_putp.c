/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 01:55:31 by juannune          #+#    #+#             */
/*   Updated: 2025/12/16 18:18:40 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putp(void *addr)
{
	if (!addr)
		return (write(1, "(nil)", 5));
	return (write(1, "0x", 2) + ft_puthex((unsigned long long)addr,
			"0123456789abcdef"));
}
