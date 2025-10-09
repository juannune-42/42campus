/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 16:52:40 by pablomar          #+#    #+#             */
/*   Updated: 2025/06/22 17:50:23 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_vf_row(int board[8][8], int row, int *input);

int	ft_vf_col(int board[8][8], int col, int *input);

int	ft_vf(int board[8][8], int row, int col, int *input)
{
	if (col == 7 && ft_vf_row(board, row, input) == 0)
		return (0);
	if (row == 7 && ft_vf_col(board, col, input) == 0)
		return (0);
	return (1);
}

int	logic(int board[8][8], int row, int col, int *input)
{
	int	new_row;
	int	new_col;
	int	i;
	int	vf;

	i = 1;
	if (row == 8)
		return (1);
	new_row = row;
	new_col = col + 1;
	if (col == 7)
	{
		new_row = row + 1;
		new_col = 0;
	}
	while (i <= 8)
	{
		board[row][col] = i;
		vf = ft_vf(board, row, col, input);
		if (vf == 1 && logic(board, new_row, new_col, input) == 1){
			return (1);}
		i++;
	}
	board[row][col] = 0;
	return (0);
}
