/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 10:41:59 by juannune          #+#    #+#             */
/*   Updated: 2025/06/21 10:54:21 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



void	ft_0(char fil[4][4], char col[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			fil[i][j] = '0';
			col[i][j] = '0';
			j++;
		}
		i++;
	}
}

void	ft_fil_col_sum(char fil[4][4], char col[4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (fil[0][i] == '0')
			fil[0][i] = col[i][0];
		if (fil[1][i] == '0')
			fil[1][i] = col[i][1];
		if (fil[2][i] == '0')
			fil[2][i] = col[i][2];
		if (fil[3][i] == '0')
			fil[3][i] = col[i][3];
		i++;
	}
}

void	ft_logica(char *arraycol, char *arrayrow)
{
	int		i;
	char	fil[4][4];
	char	col[4][4];

	i = 0;
	ft_0(fil, col);
	printf("%c %c\n", arraycol[0], arrayrow[0]);
	while (i < 4)
	{
		if (arraycol[i] == '1')
			fil[0][i] = '4';
		else
			fil[0][i] = '0';
		if (arraycol[i + 4] == '1')
			fil[3][i] = '4';
		else
			fil[3][i] = '0';
		if (arrayrow[i] == '1')
			col[0][i] = '4';
		else
			col[0][i] = '0';
		if (arrayrow[i + 4] == '1')
			col[3][i] = '4';
		else
			col[3][i] = '0';
		i++;
	}
	ft_fil_col_sum(fil, col);
	i = 0;
	while (i < 4)
	{
		printf("%c", fil[0][i]);
		i++;
	}
	printf("\n");
	i = 0;
	while (i < 4)
	{
		printf("%c", fil[1][i]);
		i++;
	}
	printf("\n");
	i = 0;
	while (i < 4)
	{
		printf("%c", fil[2][i]);
		i++;
	}
	printf("\n");
	i = 0;
	while (i < 4)
	{
		printf("%c", fil[3][i]);
		i++;
	}
}

void	ft_col_row(char *arraycol, char *arrayrow, char **argv, int i)
{
	int	j;

	j = i / 2;
	if (i < 15)
	{
		arraycol[j] = argv[1][i];
	}
	j = (i - 15) / 2;
	if (i > 15)
	{
		arrayrow[j] = argv[1][i];
	}
}

int	main(int argc, char **argv)
{
	int		i;
	char	arraycol[8];
	char	arrayrow[8];

	i = 0;
	if (argc != 2)
		return (0);
	while (argv[1][i] != '\0')
	{
		if ((i % 2) == 0)
		{
			ft_col_row(arraycol, arrayrow, argv, i);
		}
		i++;
	}
	if (i == 31)
	{
		ft_logica(arraycol, arrayrow);
		return (0);
	}
	return (0);
}
