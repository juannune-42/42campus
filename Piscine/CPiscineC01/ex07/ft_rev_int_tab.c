/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:52:03 by juannune          #+#    #+#             */
/*   Updated: 2025/06/23 15:35:11 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	tab_rev;
	int	i;

	i = 0;
	while (i < size / 2)
	{
		tab_rev = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = tab_rev;
		i++;
	}
}
