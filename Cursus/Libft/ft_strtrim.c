/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 00:21:46 by juannune          #+#    #+#             */
/*   Updated: 2025/11/12 00:30:53 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_start(const char *s1, const char *set)
{
	size_t	i;

	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	return (i);
}

static size_t	get_end(const char *s1, const char *set)
{
	size_t	j;

	j = ft_strlen(s1);
	if (j == 0)
		return (0);
	j--;
	while (j > 0 && ft_strchr(set, s1[j]))
		j--;
	if (ft_strchr(set, s1[j]))
		return (0);
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	start;
	size_t	end;
	size_t	len;
	size_t	k;

	if (!s1 || !set)
		return (NULL);
	start = get_start(s1, set);
	end = get_end(s1, set);
	if (start > end || s1[start] == '\0')
		return (ft_strdup(""));
	len = end - start + 1;
	trimmed = (char *)ft_calloc(len + 1, sizeof(char));
	if (!trimmed)
		return (NULL);
	k = 0;
	while (k < len)
	{
		trimmed[k] = s1[start + k];
		k++;
	}
	return (trimmed);
}
