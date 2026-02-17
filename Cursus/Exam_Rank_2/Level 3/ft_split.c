#include <stdlib.h>
char    **ft_split(char *str)
{
    int wc = 1, i = 0, j = 0;
    if (!*str)
        return (NULL);
    while(str[i])
    {
        if (str[i] != ' ' || str[i] != '\t' || str[i] != '\n')
            wc += 1;
        i++;
    }
    char **array = malloc(sizeof(char *) * wc);
    if (!array)
        return (NULL);
    i = 0;
    while(array[i])
    {
        j = 0;
        while (*str)
            array[i][j++] = *str++;
    }
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 22:56:24 by juannune          #+#    #+#             */
/*   Updated: 2026/01/28 02:57:12 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(const char *str, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (*str != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*str == c)
			in_word = 0;
		str++;
	}
	return (count);
}

static char	*word_dup(const char *str, size_t len)
{
	char	*word;

	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	ft_memcpy(word, str, len);
	word[len] = '\0';
	return (word);
}

static void	free_array(char **array, size_t j)
{
	while (j > 0)
		free(array[--j]);
	free(array);
}

static int	fill_array(char **array, const char *str, char c)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] == '\0')
			break ;
		start = i;
		while (str[i] && str[i] != c)
			i++;
		array[j] = word_dup(str + start, i - start);
		if (!array[j])
			return (free_array(array, j), -1);
		j++;
	}
	array[j] = NULL;
	return (0);
}

char	**ft_split(char const *str, char c)
{
	char	**array;

	if (!str)
		return (NULL);
	array = (char **)ft_calloc(word_count(str, c) + 1, sizeof(char *));
	if (!array)
		return (NULL);
	if (fill_array(array, str, c) == -1)
		return (NULL);
	return (array);
}

