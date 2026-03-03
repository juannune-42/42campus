/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 22:46:55 by juannune          #+#    #+#             */
/*   Updated: 2026/03/03 11:41:36 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nbr)
{
	if (nbr == -2147483648)
		write(1, "-2147483648", 11);
	else if (nbr < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-nbr);
	}
	else
	{
		if (nbr >= 10)
			ft_putnbr(nbr / 10);
		write(1, (char []){nbr % 10 + '0'}, 1);
	}
}
