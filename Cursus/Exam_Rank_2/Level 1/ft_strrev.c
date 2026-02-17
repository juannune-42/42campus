/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 15:47:59 by juannune          #+#    #+#             */
/*   Updated: 2026/02/16 16:10:00 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_strrev(char *str)
{
    int i = 0, j = 0;
    char temp;
    while(str[j])
        j++;
    j--;
    while(i < j)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i ++, j--;
    }
    return(str);
}
