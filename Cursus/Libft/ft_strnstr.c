/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 06:00:26 by juannune          #+#    #+#             */
/*   Updated: 2025/11/26 05:32:15 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = -1;
	while (haystack[++i] && i < len)
	{
		j = -1;
		while (needle[++j] && haystack[i + j] && haystack[i + j] == needle[j]
			&& j + i < len);
		if (needle[j] == '\0')
			return ((char *)haystack + i);
	}
	return (NULL);
}
