/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_auxiliar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablomar <pablomar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 16:53:18 by pablomar          #+#    #+#             */
/*   Updated: 2025/06/22 16:53:20 by pablomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_v_borowes(int *perc)
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

int	ft_vf_input12(int board[4][4], int row, int *input)
{
	int	rev[4];
	int	i;
	int	j;

	i = 3;
	j = 0;
	while (i >= 0)
	{
		rev[j] = board[row][i];
		j++;
		i--;
	}
	if (ft_v_borowes(rev) != input[12 + row])
		return (0);
	return (1);
}

int	ft_vf_input4(int board[4][4], int col, int *input)
{
	int	rev[4];
	int	i;
	int	j;

	i = 3;
	j = 0;
	while (i >= 0)
	{
		rev[j] = board[i][col];
		j++;
		i--;
	}
	if (ft_v_borowes(rev) != input[4 + col])
		return (0);
	return (1);
}
