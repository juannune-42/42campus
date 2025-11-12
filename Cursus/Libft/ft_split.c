/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 22:56:24 by juannune          #+#    #+#             */
/*   Updated: 2025/11/11 23:03:18 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(const char *s, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*word_dup(const char *s, size_t len)
{
	char	*word;

	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	ft_memcpy(word, s, len);
	word[len] = '\0';
	return (word);
}

static void	free_array(char **array, size_t j)
{
	while (j > 0)
		free(array[--j]);
	free(array);
}

static int	fill_array(char **array, const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		array[j] = word_dup(s + start, i - start);
		if (!array[j])
			return (free_array(array, j), -1);
		j++;
	}
	array[j] = NULL;
	return (0);
}

char	**ft_split(char const*s, char c)
{
	char	**array;

	if (!s)
		return (NULL);
	array = (char **)ft_calloc(word_count(s, c) + 1, sizeof(char *));
	if (!array)
		return (NULL);
	if (fill_array(array, s, c) == -1)
		return (NULL);
	return (array);
}
