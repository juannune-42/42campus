/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 03:31:44 by juannune          #+#    #+#             */
/*   Updated: 2026/02/17 03:10:53 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
    int i = 0;
    if (argc != 2)
        return(write(1, "\n", 1));
    while (argv[1][i])
        i++;
    while (i--)
        write(1, &argv[1][i], 1);
    return(write(1, "\n", 1));
}
