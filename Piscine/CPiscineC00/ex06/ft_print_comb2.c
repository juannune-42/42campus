/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 18:20:24 by juannune          #+#    #+#             */
/*   Updated: 2025/12/01 22:09:15 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(char *array)
{
	write(1, array, 5);
	if (!(array[0] == '9' && array[1] == '8' && array[3] == '9'
			&& array[4] == '9'))
		write(1, ",  ", 2);
}

void	ft_print_comb2(void)
{
	char	array[5];

	array[2] = ' ';
	array[0] = '/';
	while (array[0]++ < '9')
	{
		array[1] = '/';
		while (array[1]++ < '9')
		{
			array[3] = '/';
			while (array[3]++ < '9')
			{
				array[4] = '/';
				while (array[4]++ < '9')
					if ((array[0] - '0') * 10 + (array[1] - '0') < (array[3]
							- '0') * 10 + (array[4] - '0'))
						ft_print(array);
			}
		}
	}
}
