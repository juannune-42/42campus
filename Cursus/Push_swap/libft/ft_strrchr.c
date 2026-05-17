/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 02:20:22 by juannune          #+#    #+#             */
/*   Updated: 2026/01/28 02:55:03 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*last = NULL;

	while (*str)
		if (*str++ == (char)c)
			last = str - 1;
	if ((char)c == '\0')
		return ((char *)str);
	if (last)
		return ((char *)last);
	return (NULL);
}
