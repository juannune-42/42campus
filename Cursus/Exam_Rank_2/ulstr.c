/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 02:58:38 by juannune          #+#    #+#             */
/*   Updated: 2026/02/14 03:06:45 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc != 2)
        return(write(1, "\n", 1));
    while(*argv[1])
    {
        if      (*argv[1] >= 'a' && *argv[1] <= 'z')
            *argv[1] -= 32;
        else if (*argv[1] >= 'A' && *argv[1] <= 'Z')
            *argv[1] += 32;
        write(1, argv[1]++, 1);
    }
    return(write(1, "\n", 1));
}
