/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 02:46:42 by juannune          #+#    #+#             */
/*   Updated: 2026/02/14 02:54:43 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc != 4 || argv[2][1] || argv[3][1])
        return(write(1, "\n", 1));
    while(*argv[1])
    {
        if (*argv[1] == *argv[2])
            *argv[1] = *argv[3];
        write(1, argv[1]++, 1);
    }
    return(write(1, "\n", 1));    
}
