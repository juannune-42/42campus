/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 04:08:54 by juannune          #+#    #+#             */
/*   Updated: 2026/02/17 03:19:28 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
    int i;
    char c;

    if (argc != 2)
        return (write(1, "\n", 1), 0);
    while ((c = *argv[1]++))
    {
        i = 1;
        if      ((c >= 'a' && c <= 'm') || (c >= 'A' && c <= 'M'))
            c += 13;
        else if ((c >= 'n' && c <= 'z') || (c >= 'N' && c <= 'Z'))
            c -= 13;
        write(1, &c, 1);
    }
    return (write(1, "\n", 1), 0);
}

// int main(int argc, char **argv)
// {
//     char *abc = "abcdefghijklmnopqrstuvwxyz";
//     int i;
//     if (argc != 2)
//         return(write(1, "\n", 1));
//     while(*argv[1])
//     {
//         i = 0;
//         while(abc[i] && *argv[1] != abc[i] && *argv[1] != abc[i] - 32) i++;
//         if (i < 13)
//             *argv[1] += 13;
//         if (i > 12 && i < 26)
//             *argv[1] -= 13;
//         write(1, argv[1]++, 1);
//     }
//     return(write(1, "\n", 1));
// }
