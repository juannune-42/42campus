/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 22:14:02 by juannune          #+#    #+#             */
/*   Updated: 2026/03/20 12:51:40 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	basevf(char c, char *base, int len)
{
	int	i;

	i = -1;
	while (base[++i])
		if (c == base[i] && i != len)
			return (0);
	return (1);
}

void	baselogic(long i, char *base)
{
	write(1, &base[i], 1);
}

void	logic(long nbr, char *base, int len)
{
	if (nbr >= len)
		logic(nbr / len, base, len);
	baselogic(nbr % len, base);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		len;
	long	nb;

	len = -1;
	nb = nbr;
	while (base[++len])
		if (!basevf(base[len], base, len) || base[len] == '+'
			|| base[len] == '-' || base[len] == ' ' || (base[len] >= 9
				&& base[len] <= 13))
			return ;
	if (len == 0 || len == 1)
		return ;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	logic(nb, base, len);
}
