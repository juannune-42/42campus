/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 01:48:31 by juannune          #+#    #+#             */
/*   Updated: 2025/07/04 01:57:45 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;
	int	temp;
	int	prime;

	i = 2;
	temp = nb - 1;
	prime = 1;
	while (temp > 1)
	{
		if (nb % temp == 0)
			prime = 0;
		temp--;
	}
	if (nb < 2)
		prime = 0;
	return (prime);
}
