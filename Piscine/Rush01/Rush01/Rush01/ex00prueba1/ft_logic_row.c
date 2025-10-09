/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic_row.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablomar <pablomar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 16:53:03 by pablomar          #+#    #+#             */
/*   Updated: 2025/06/22 16:53:04 by pablomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_auxiliar.h"

int	ft_vf_row(int board[4][4], int row, int *input)
{
	write(1, "hola", 4);
	int	used[5];
	int	i;

	fill_use(used);
	i = 0;
	while (i < 4)
	{
		if (board[row][i] < 1 || board[row][i] > 4 || used[board[row][i]])
			return (0);
		used[board[row][i]] = 1;
		i++;
	}
	if (ft_v_borowes(board[row]) != input[8 + row])
		return (0);
	if (ft_vf_input12(board, row, input) == 0)
		return (0);
	return (1);
}
