/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 02:20:22 by juannune          #+#    #+#             */
/*   Updated: 2025/11/26 05:37:23 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last = NULL;

	while (*s)
		if (*s++ == (char)c)
			last = s - 1;
	if ((char)c == '\0')
		return ((char *)s);
	if (last)
		return ((char *)last);
	return (NULL);
}
