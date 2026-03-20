/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 01:48:31 by juannune          #+#    #+#             */
/*   Updated: 2026/03/20 12:48:21 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	temp;
	int	prime;

	temp = nb;
	prime = 1;
	while (--temp > 1)
		if (nb % temp == 0)
			prime = 0;
	if (nb < 2)
		prime = 0;
	return (prime);
}
