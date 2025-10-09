/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 01:30:51 by juannune          #+#    #+#             */
/*   Updated: 2025/06/22 16:26:29 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	fill_use(int *used);

int		ft_v_boxes(int *line);

int		ft_vf_input12(int board[4][4], int x, int *input);

int	ft_vf_x(int board[4][4], int x, int *input)
{
	int	used[5];
	int	i;

	fill_use(used);
	i = 0;
	while (i < 4)
	{
		if (board[x][i] < 1 || board[x][i] > 4 || used[board[x][i]])
			return (0);
		used[board[x][i]] = 1;
		i++;
	}
	if (ft_v_boxes(board[x]) != input[8 + x])
		return (0);
	if (ft_vf_input12(board, x, input) == 0)
		return (0);
	return (1);
}
