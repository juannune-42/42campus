/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 01:30:51 by juannune          #+#    #+#             */
/*   Updated: 2025/06/22 01:38:44 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"
#include "utils.h"

void	get_col(int grid[4][4], int col, int *out)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		out[i] = grid[i][col];
		i++;
	}
}

int	count_visible(int *line)
{
	int	max;
	int	visible;
	int	i;

	max = 0;
	visible = 0;
	i = 0;
	while (i < 4)
	{
		if (line[i] > max)
		{
			max = line[i];
			visible++;
		}
		i++;
	}
	return (visible);
}

int	is_valid_row(int grid[4][4], int row, int *views)
{
	int	used[5];
	int	i;
	int	rev[4];
	int	j;

	i = 0;
	while (i < 5)
	{
		used[i] = 0;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (grid[row][i] < 1 || grid[row][i] > 4 || used[grid[row][i]])
			return (0);
		used[grid[row][i]] = 1;
		i++;
	}
	if (count_visible(grid[row]) != views[8 + row])
		return (0);
	j = 0;
	i = 3;
	while (i >= 0)
	{
		rev[j] = grid[row][i];
		j++;
		i--;
	}
	if (count_visible(rev) != views[12 + row])
		return (0);
	return (1);
}

int	is_valid_col(int grid[4][4], int col, int *views)
{
	int	used[5];
	int	colarr[4];
	int	i;
	int	rev[4];
	int	j;

	i = 0;
	while (i < 5)
	{
		used[i] = 0;
		i++;
	}
	get_col(grid, col, colarr);
	i = 0;
	while (i < 4)
	{
		if (colarr[i] < 1 || colarr[i] > 4 || used[colarr[i]])
			return (0);
		used[colarr[i]] = 1;
		i++;
	}
	if (count_visible(colarr) != views[col])
		return (0);
	j = 0;
	i = 3;
	while (i >= 0)
	{
		rev[j] = colarr[i];
		j++;
		i--;
	}
	if (count_visible(rev) != views[4 + col])
		return (0);
	return (1);
}

int	solve(int grid[4][4], int row, int col, int *views)
{
	int	next_row;
	int	next_col;
	int	num;
	int	valid;

	if (row == 4)
		return (1);
	next_row = row;
	next_col = col + 1;
	if (col == 3)
	{
		next_row = row + 1;
		next_col = 0;
	}
	num = 1;
	while (num <= 4)
	{
		grid[row][col] = num;
		valid = 1;
		if (col == 3 && !is_valid_row(grid, row, views))
			valid = 0;
		if (row == 3 && !is_valid_col(grid, col, views))
			valid = 0;
		if (valid && solve(grid, next_row, next_col, views))
			return (1);
		num++;
	}
	grid[row][col] = 0;
	return (0);
}
