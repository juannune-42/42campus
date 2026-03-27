/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 02:21:43 by juannune          #+#    #+#             */
/*   Updated: 2026/03/27 13:59:35 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_write(int *array)
{
    char c;
    int i;

    i = 0;
    while(i < 10)
    {
        c = array[i++] + '0';
        write(1, &c, 1);
    }
        write(1, "\n", 1);
}

int ft_is_valid(int *array, int col)
{
    int i;

    i = -1;
    while (++i < col)
    {
        if (array[i] == array[col])
            return (0);
        if (array[i] == array[col] + (col - i) || array[i] == array[col] - (col - i))
            return (0);
    }
    return (1);
}

int ft_logic(int *array, int col)
{
    int count;

    if (col == 10)
    {
        ft_write(array);
        return (1);
    }
    count = 0;
    array[col] = 0;
    while (array[col] < 10)
    {
        if (ft_is_valid(array, col))
            count += ft_logic(array, col + 1);
        array[col]++;
    }
    return (count);
}

int ft_ten_queens_puzzle(void)
{
    int array[10];
    int col;

    col = 0;
    return (ft_logic(array, col));
}
