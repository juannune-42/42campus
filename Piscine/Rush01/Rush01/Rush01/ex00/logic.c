/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 01:30:51 by juannune          #+#    #+#             */
/*   Updated: 2025/06/22 16:21:28 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_v_boxes(int *perc)
{
	int	i;
	int	a;
	int	v;

	a = 0;
	v = 0;
	i = 0;
	while (i < 4)
	{
		if (perc[i] > a)
		{
			a = perc[i];
			v++;
		}
		i++;
	}
	return (v);
}

void	fill_use(int *used)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		used[i] = 0;
		i++;
	}
}

int	ft_vf_input12(int board[4][4], int x, int *input)
{
	int	rev[4];
	int	i;
	int	j;

	i = 3;
	j = 0;
	while (i >= 0)
	{
		rev[j] = board[x][i];
		j++;
		i--;
	}
	if (ft_v_boxes(rev) != input[12 + x])
		return (0);
	return (1);
}

int	ft_vf_input4(int board[4][4], int y, int *input)
{
	int	rev[4];
	int	i;
	int	j;

	i = 3;
	j = 0;
	while (i >= 0)
	{
		rev[j] = board[i][y];
		j++;
		i--;
	}
	if (ft_v_boxes(rev) != input[4 + y])
		return (0);
	return (1);
}
