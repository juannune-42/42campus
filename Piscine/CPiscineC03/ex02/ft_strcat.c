/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 03:39:26 by juannune          #+#    #+#             */
/*   Updated: 2026/03/11 13:43:00 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	i = -1;
	while (dest[++i]);
	while (*src)
		dest[i++] = *src++;
	dest[i] = '\0';
	return (dest);
}
