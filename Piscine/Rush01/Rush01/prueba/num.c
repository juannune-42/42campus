/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 22:38:43 by juannune          #+#    #+#             */
/*   Updated: 2025/06/22 01:08:18 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		g_array[24][4];
int		g_i = 0;

void	ft_numa(int *num, int *used, int pos)
{
	int	i;

	if (pos == 4)
	{
		i = 0;
		while (i < 4)
		{
			g_array[g_i][i] = num[i];
			i++;
		}
		g_i++;
		return ;
	}
	i = 1;
	while (i <= 4)
	{
		if (!used[i])
		{
			num[pos] = i;
			used[i] = 1;
			ft_numa(num, used, pos + 1);
			used[i] = 0;
		}
		i++;
	}
}

void	ft_num(void)
{
	int	num[4];
	int	used[5];
	int	i;

	i = 0;
	while (i < 5)
	{
		used[i] = 0;
		i++;
	}
	ft_numa(num, used, 0);
}

int	main(void)
{
	ft_num();
	return (0);
}
