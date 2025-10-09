/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 01:30:51 by juannune          #+#    #+#             */
/*   Updated: 2025/06/22 15:11:35 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_vf_x(int board[4][4], int x, int *input);

int	ft_vf_y(int board[4][4], int y, int *input);

int	ft_vf(int board[4][4], int x, int y, int *input)
{
	if (y == 3 && ft_vf_x(board, x, input) == 0)
		return (0);
	if (x == 3 && ft_vf_y(board, y, input) == 0)
		return (0);
	return (1);
}

int	logic(int board[4][4], int x, int y, int *input)
{
	int	new_x;
	int	new_y;
	int	i;
	int	vf;

	i = 1;
	if (x == 4)
		return (1);
	new_x = x;
	new_y = y + 1;
	if (y == 3)
	{
		new_x = x + 1;
		new_y = 0;
	}
	while (i <= 4)
	{
		board[x][y] = i;
		vf = ft_vf(board, x, y, input);
		if (vf == 1 && logic(board, new_x, new_y, input) == 1)
			return (1);
		i++;
	}
	board[x][y] = 0;
	return (0);
}
