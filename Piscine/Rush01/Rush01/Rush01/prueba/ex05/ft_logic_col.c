/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic_col.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 16:53:09 by pablomar          #+#    #+#             */
/*   Updated: 2025/06/22 17:16:39 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	fill_use(int *used);

int		ft_v_borowes(int *line);

int		ft_vf_input4(int board[8][8], int col, int *input);

int	ft_vf_col(int board[8][8], int col, int *input)
{
	int	used[9];
	int	i;
	int	a[8];

	fill_use(used);
	i = 0;
	while (i < 8)
	{
		a[i] = board[i][col];
		if (board[i][col] < 1 || board[i][col] > 8 || used[board[i][col]])
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
