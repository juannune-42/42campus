/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 14:42:59 by juannune          #+#    #+#             */
/*   Updated: 2026/02/27 11:19:19 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	array[3];

	array[0] = '/';
	while (array[0]++ < '7')
	{
		array[1] = array[0];
		while (array[1]++ < '8')
		{
			array[2] = array[1];
			while (array[2]++ < '9')
			{
				write(1, array, 3);
				if (!(array[0] == '7'))
					write(1, ", ", 2);
			}
		}
	}
}
// {
// 	char	array[4];
// 	while (array[0]++ < '7' && (array[1] = array[0]))
// 		while (array[1]++ < '8' && (array[2] = array[1]))
// 			while (array[2]++ < '9')
// 				if (write(1, array, 3) && !(array[0] == '7'))
// 					write(1, ", ", 2);
// }
