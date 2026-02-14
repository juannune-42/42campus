/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 04:13:05 by juannune          #+#    #+#             */
/*   Updated: 2026/02/14 04:47:17 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int ft_atoi(const char *str)
{
    int sign = 1, result = 0;
    if (*str == '-')
        sign = -1, str++;
    while(*str)
        result = result * 10 + (*str++ - '0');
    return(result * sign);
}

int main(int argc, char **argv)
{
    int a, b;
    if (argc != 4)
        return (write(1, "\n", 1));
    a = ft_atoi(argv[1]);
    b = ft_atoi(argv[3]);
    switch(*argv[2])
    {
        case '+':
            printf("%d", a+b);
            break;
        case '-':
            printf("%d", a-b);
            break;
        case '*':
            printf("%d", a*b);
            break;
        case '/':
            printf("%d", a/b);
            break;
        case '%':
            printf("%d", a%b);
            break;
    }
    return (printf("\n"));
}
