/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 18:20:24 by juannune          #+#    #+#             */
/*   Updated: 2025/06/16 18:20:28 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2c(char a, char b, char c, char d)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, " ", 1);
	write(1, &c, 1);
	write(1, &d, 1);
	if (!(a == '9' && b == '8' && c == '9' && d == '9'))
		write(1, ",  ", 2);
}

void	ft_print_comb2b(char a, char b, char c, char d)
{
	int	i;
	int	k;

	i = a * 10 + b;
	k = c * 10 + d;
	if (!(i >= k))
		ft_print_comb2c(a, b, c, d);
}

void	ft_print_comb2a(char a, char b)
{
	char	c;
	char	d;

	c = '0';
	while (c <= '9')
	{
		d = '0';
		while (d <= '9')
		{
			ft_print_comb2b(a, b, c, d);
			d++;
		}
		c++;
	}
}

void	ft_print_comb2(void)
{
	char	a;
	char	b;

	a = '0';
	while (a <= '9')
	{
		b = '0';
		while (b <= '9')
		{
			ft_print_comb2a(a, b);
			b++;
		}
		a++;
	}
}
