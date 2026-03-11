/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 04:26:48 by juannune          #+#    #+#             */
/*   Updated: 2026/03/11 13:50:16 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;

	i = -1
	while (dest[-i] != '\0');
	while (*src && j < nb)
		dest[i++] = *src++;
	dest[i] = '\0';
	return (dest);
}
