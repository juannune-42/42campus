/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 22:14:02 by juannune          #+#    #+#             */
/*   Updated: 2025/07/03 21:44:44 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	basevf(char c, char *base, int l)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i] && i != l)
			return (0);
		i++;
	}
	return (1);
}

void	baselogic(long i, char *base)
{
	char	c;

	c = base[i];
	write(1, &c, 1);
}

void	logic(long nbr, char *base, int l)
{
	long	i;

	if (nbr >= l)
	{
		i = nbr / l;
		logic(i, base, l);
	}
	i = nbr % l;
	baselogic(i, base);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		l;
	long	nb;

	l = 0;
	nb = nbr;
	while (base[l])
	{
		if (!basevf(base[l], base, l))
			return ;
		if (base[l] == '+' || base[l] == '-' || base[l] == ' ' || (base[l] >= 9
				&& base[l] <= 13))
			return ;
		l++;
	}
	if (l == 0 || l == 1)
		return ;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	logic(nb, base, l);
}
