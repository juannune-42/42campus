/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 12:27:34 by juannune          #+#    #+#             */
/*   Updated: 2026/04/02 13:46:12 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int ft_len(int size, char **strs, char *sep)
{
	int	i;
	int j;
	int total;
	
	i = 0;
	total = 0;
	while ()
	{
		j = 0;
		while(strs[i + j] == sep[j])
		{
			if (sep[j] == '\0')
			{
				i += j;
				--size;
			}
			j++;
		}
		if (!size)
			break;
		if (&strs != newstr)
			(*newstr)[i - j] = strs[i];
		i++;
	}
	return (i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char *newstr;

	if (size == 0)
	{
		newstr = malloc(1);
		if (!newstr)
			return (NULL);
		*newstr = '\0';
		return (newstr);
	}
	newstr = malloc(ft_logic(size, *strs, sep) * sizeof(char));
	if (!newstr)
		return (NULL);
	ft_copy(size, *strs, sep, newstr);
	*strs = newstr;
	return (*strs);
}

/* ******************************************************* */                                                                            */
#include <stdlib.h>

static int	ft_len(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	total;

	total = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			j++;
		total += j;
		if (i < size - 1)
		{
			j = 0;
			while (sep[j])
				j++;
			total += j;
		}
		i++;
	}
	return (total + 1);  // + '\0'
}

static void	ft_copy(int size, char **strs, char *sep, char *newstr)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			newstr[k++] = strs[i][j++];
		if (i < size - 1)
		{
			j = 0;
			while (sep[j])
				newstr[k++] = sep[j++];
		}
		i++;
	}
	newstr[k] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*newstr;

	if (size == 0)
	{
		newstr = malloc(1);
		if (!newstr)
			return (NULL);
		*newstr = '\0';
		return (newstr);
	}
	newstr = malloc(ft_len(size, strs, sep));
	if (!newstr)
		return (NULL);
	ft_copy(size, strs, sep, newstr);
	return (newstr);
}
