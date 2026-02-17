/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizz_buzz.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 03:32:43 by juannune          #+#    #+#             */
/*   Updated: 2026/02/17 02:35:15 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putnbr(int i)
{
	if (i > 9)    putnbr(i / 10);
	write(1, &"0123456789"[i% 10], 1);
}

int	main(void)
{
	for (int i = 1; i < 101; i++)
	{
        if (!(i % 15)) write(1, "fizzbuzz", 8);
		else if (!(i % 5)) write(1, "buzz", 4);
		else if (!(i % 3)) write(1, "fizz", 4);
		else    putnbr(i);
		write(1, "\n", 1);
	}
	return (0);
}
