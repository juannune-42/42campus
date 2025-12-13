/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 00:38:36 by juannune          #+#    #+#             */
/*   Updated: 2025/12/13 02:01:45 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long long nbr, char *strhex)
{
	if (nbr > 15)
		return (ft_puthex(nbr / 16, strhex) + ft_puthex(nbr % 16, strhex));
	return (write(1, &strhex[nbr], 1));
}
