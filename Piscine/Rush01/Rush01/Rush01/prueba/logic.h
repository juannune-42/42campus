/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 01:31:01 by juannune          #+#    #+#             */
/*   Updated: 2025/06/22 13:05:23 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		logic(int grid[4][4], int row, int col, int *views);
int		is_valid_row(int grid[4][4], int row, int *views);
int		is_valid_col(int grid[4][4], int col, int *views);
