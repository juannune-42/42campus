/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 11:24:53 by juannune          #+#    #+#             */
/*   Updated: 2025/06/30 12:41:05 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	destl;
	unsigned int	srcl;
	unsigned int	i;
	unsigned int	j;

	destl = 0;
	while (dest[destl] && destl < size)
		destl++;
	srcl = 0;
	while (src[srcl])
		srcl++;
	if (destl == size)
		return (size + srcl);
	i = destl;
	j = 0;
	while (src[j] && i + 1 < size)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (destl + srcl);
}
