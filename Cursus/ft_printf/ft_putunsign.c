/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 01:40:01 by juannune          #+#    #+#             */
/*   Updated: 2025/12/13 02:03:27 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsinged(unsigned int nbr)
{
	if (nbr > 9)
		return (ft_putunsigned(nbr / 10) + ft_putunsigned(nbr % 10));
	return (write(1, &"0123456789"[nbr], 1));
}
