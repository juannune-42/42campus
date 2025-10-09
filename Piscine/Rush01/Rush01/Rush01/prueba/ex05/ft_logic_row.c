/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic_row.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 16:53:03 by pablomar          #+#    #+#             */
/*   Updated: 2025/06/22 17:16:20 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	fill_use(int *used);

int		ft_v_borowes(int *line);

int		ft_vf_input12(int board[8][8], int row, int *input);

int	ft_vf_row(int board[8][8], int row, int *input)
{
	int	used[9];
	int	i;

	fill_use(used);
	i = 0;
	while (i < 8)
	{
		if (board[row][i] < 1 || board[row][i] > 8 || used[board[row][i]])
			return (0);
		used[board[row][i]] = 1;
		i++;
	}
	if (ft_v_borowes(board[row]) != input[16 + row])
		return (0);
	if (ft_vf_input12(board, row, input) == 0)
		return (0);
	return (1);
}
