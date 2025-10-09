/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 00:54:22 by juannune          #+#    #+#             */
/*   Updated: 2025/06/17 00:54:25 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_number(int *num, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(num[i] + '0');
		i++;
	}
}

void	ft_print_combn(int n)
{
	int	num[10];
	int	i;

	if (n < 1 || n > 9)
		return ;
	i = 0;
	while (i < n)
	{
		num[i] = i;
		i++;
	}
	while (1)
	{
		print_number(num, n);
		i = n - 1;
		while (i >= 0 && num[i] == 10 - n + i)
			i--;
		if (i < 0)
			break ;
		write(1, ", ", 2);
		num[i]++;
		while (i++ < n)
			num[i] = num[i - 1] + 1;
	}
}
