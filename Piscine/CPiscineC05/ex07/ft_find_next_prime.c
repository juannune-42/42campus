/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 02:03:24 by juannune          #+#    #+#             */
/*   Updated: 2026/10/15 11:26:39 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb)
{
	int	i;

	if (nb < 2)
		return (2);
	while (nb)
	{
		i = 2;
		while (i < nb)
			if (nb % i++ == 0)
				break ;
		if (i == nb)
			return (i);
		nb++;
	}
	return (0);
}
