/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 04:02:00 by juannune          #+#    #+#             */
/*   Updated: 2026/02/14 04:09:50 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
    if(argc != 2)
        return(write(1, "\n", 1));
    while (*argv[1])
    {
        if (*argv[1] >= 'A' && *argv[1] <= 'Z')
            write(1, "_", 1), *argv[1] += 32;
        write(1, argv[1]++, 1);
    }    
    return(write(1, "\n", 1));   
}
