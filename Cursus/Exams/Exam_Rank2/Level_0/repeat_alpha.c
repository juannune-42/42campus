/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 03:49:11 by juannune          #+#    #+#             */
/*   Updated: 2026/02/17 03:05:37 by juannune         ###   ########.fr       */
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
        if (c >= 'a' && c <= 'z')   i += c - 'a';
        if (c >= 'A' && c <= 'Z')   i += c - 'A';
        while (i--)
            write(1, &c, 1);
    }
    return (write(1, "\n", 1), 0);
}

// #include <unistd.h>

// int main(int argc, char **argv)
// {
//     char *abc = "abcdefghijklmnopqrstuvwxyz";
//     int i = 0;
//     if (argc != 2)
//         return(write(1, "\n", 1));
//     while(*argv[1])
//     {
//         while(abc[i] && *argv[1] != abc[i] && *argv[1] != abc[i] - 32) i++;
//         if (i > 25) i = 0;
//         while(i--)
//             write(1, argv[1], 1);
//         write(1, argv[1]++, 1);
//     }
//     return(write(1, "\n", 1));
// }
