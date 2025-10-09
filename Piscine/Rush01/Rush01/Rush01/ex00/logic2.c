/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 01:30:51 by juannune          #+#    #+#             */
/*   Updated: 2025/06/22 16:20:52 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	fill_use(int *used);

int		ft_v_boxes(int *line);

int		ft_vf_input4(int board[4][4], int y, int *input);

int	ft_vf_y(int board[4][4], int y, int *input)
{
	int	used[5];
	int	i;
	int	a[4];

	fill_use(used);
	i = 0;
	while (i < 4)
	{
		a[i] = board[i][y];
		if (board[i][y] < 1 || board[i][y] > 4 || used[board[i][y]])
			return (0);
		used[board[i][y]] = 1;
		i++;
	}
	if (ft_v_boxes(a) != input[y])
		return (0);
	if (ft_vf_input4(board, y, input) == 0)
		return (0);
	return (1);
}
