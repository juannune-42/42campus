/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 10:41:59 by juannune          #+#    #+#             */
/*   Updated: 2025/06/22 13:35:29 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	logic(int board[4][4], int x, int y, int *input);

void	ft_fill_board(int board[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
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
	while (argv[i] && j < 16)
	{
		if (argv[i] >= '1' && argv[i] <= '4')
		{
			input[j] = argv[i] - '0';
			j++;
		}
		else if (argv[i] != ' ')
			return (0);
		i++;
	}
	if (j == 16 && argv[i] == '\0')
		return (1);
	return (0);
}

void	print_board(int board[4][4])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = board[i][j] + '0';
			write(1, &c, 1);
			if (j < 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	board[4][4];
	int	input[16];
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_fill_board(board);
	if (argc != 2 || check_input(argv[1], input) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (logic(board, 0, 0, input) == 1)
		print_board(board);
	else
		write(1, "Error\n", 6);
	return (0);
}
