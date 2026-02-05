/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 01:40:01 by juannune          #+#    #+#             */
/*   Updated: 2026/02/03 15:01:19 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int nbr)
{
	if (nbr > 9)
		return (ft_putunsigned(nbr / 10) + ft_putunsigned(nbr % 10));
	return (write(1, &"0123456789"[nbr], 1));
}
