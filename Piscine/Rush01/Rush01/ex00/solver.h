/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 01:31:01 by juannune          #+#    #+#             */
/*   Updated: 2025/06/22 01:39:11 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVER_H
# define SOLVER_H

int		solve(int grid[4][4], int row, int col, int *views);
int		is_valid_row(int grid[4][4], int row, int *views);
int		is_valid_col(int grid[4][4], int col, int *views);
int		count_visible(int *line);
void	get_col(int grid[4][4], int col, int *out);

#endif
