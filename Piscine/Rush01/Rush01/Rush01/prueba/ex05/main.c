/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 16:52:56 by pablomar          #+#    #+#             */
/*   Updated: 2025/06/22 17:55:44 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		logic(int board[8][8], int row, int col, int *input);

void	ft_fill_board(int board[8][8])
{
	int	i;
	int	j;

	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 8)
		{
			board[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	check_input(char *argv, int *input)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[i] && j < 32)
	{
		if (argv[i] >= '1' && argv[i] <= '8')
		{
			input[j] = argv[i] - '0';
			j++;
		}
		else if (argv[i] != ' ')
			return (0);
		i++;
	}
	if (j == 32 && argv[i] == '\0')
		return (1);
	return (0);
}

void	print_board(int board[8][8])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 8)
		{
			c = board[i][j] + '0';
			write(1, &c, 1);
			if (j < 7)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	board[8][8];
	int	input[32];
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_fill_board(board);
	if (argc != 2 || check_input(argv[1], input) == 0)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (logic(board, 0, 0, input) == 1)
		print_board(board);
	else
		write(1, "Error\n", 6);
	return (1);
}
