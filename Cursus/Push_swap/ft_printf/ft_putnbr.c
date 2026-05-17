/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 00:44:39 by juannune          #+#    #+#             */
/*   Updated: 2025/12/13 02:03:41 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nbr)
{
	if (nbr == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nbr < 0)
		return (write(1, "-", 1) + ft_putnbr(-nbr));
	else if (nbr > 9)
		return (ft_putnbr(nbr / 10) + ft_putnbr(nbr % 10));
	return (write(1, &"0123456789"[nbr], 1));
}
