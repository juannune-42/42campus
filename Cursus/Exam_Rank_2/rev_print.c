/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 03:31:44 by juannune          #+#    #+#             */
/*   Updated: 2026/02/13 04:04:02 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc != 2)
        return(write(1, "\n", 1));
    while (*argv[1]++);
    argv[1]-= 2;
    while (*argv[1])
        write(1, argv[1]--, 1);
    return(write(1, "\n", 1));
}
