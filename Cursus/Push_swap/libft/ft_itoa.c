/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 23:01:38 by juannune          #+#    #+#             */
/*   Updated: 2025/11/27 04:38:40 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(long nbr)
{
	int	count;

	count = (nbr <= 0);
	if (nbr <= 0)
		nbr = -nbr;
	while (nbr > 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

static void	fill_number_str(char *str, long num, int len)
{
	while (num > 0)
	{
		str[--len] = (num % 10) + '0';
		num /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	long	num;

	str = (char *)malloc(int_len(n) + 1);
	if (!str)
		return (NULL);
	str[int_len(n)] = '\0';
	num = n;
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	else if (num == 0)
	{
		str[0] = '0';
		return (str);
	}
	fill_number_str(str, num, int_len(n));
	return (str);
}
