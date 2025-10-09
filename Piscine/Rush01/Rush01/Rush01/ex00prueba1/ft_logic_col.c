/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic_col.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablomar <pablomar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 16:53:09 by pablomar          #+#    #+#             */
/*   Updated: 2025/06/22 16:53:10 by pablomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_auxiliar.h"

int	ft_vf_col(int board[4][4], int col, int *input)
{
	int	used[5];
	int	i;
	int	a[4];

	fill_use(used);
	i = 0;
	while (i < 4)
	{
		a[i] = board[i][col];
		if (board[i][col] < 1 || board[i][col] > 4 || used[board[i][col]])
			return (0);
		used[board[i][col]] = 1;
		i++;
	}
	if (ft_v_borowes(a) != input[col])
		return (0);
	if (ft_vf_input4(board, col, input) == 0)
		return (0);
	return (1);
}
