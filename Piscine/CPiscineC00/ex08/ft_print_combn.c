/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 00:54:22 by juannune          #+#    #+#             */
/*   Updated: 2025/12/05 17:23:47 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_number(int *num, int n)
{
	while (n--)
		write(1, (char []){*num++ + '0'}, 1);
}

void	rec_comb(int n, int pos, int start, int *num)
{
	if (pos == n)
	{
		print_number(num, n);
		if (num[0] != 10 - n)
			write(1, ", ", 2);
		return ;
	}
	while (start <= 9)
	{
		num[pos] = start;
		rec_comb(n, 1 + pos, ++start, num);
	}
}

void	ft_print_combn(int n)
{
	int	num[9];

	if (n < 1 || n > 9)
		return ;
	rec_comb(n, 0, 0, num);
}

/*
void	ft_print_combn(int n)
{
	int	num[9];
	int	i;

	if (n < 1 || n > 9)
		return ;
	i = -1;
	while (++i < n)
		num[i] = i;
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
		while (++i < n)
			num[i] = num[i - 1] + 1;
	}
}
*/
