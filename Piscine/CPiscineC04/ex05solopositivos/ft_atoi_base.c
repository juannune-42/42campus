/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 01:43:47 by juannune          #+#    #+#             */
/*   Updated: 2025/07/03 18:58:35 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

unsigned int	numbasetonumb(char str, char *base, int basel, int strl)
{
	int	numb;
	int	j;

	j = 0;
	numb = 0;
	while (base[j])
	{
		if (str == ' ' || str == '\t' || str == '\n' || str == '\v'
			|| str == '\f' || str == '\r')
			break ;
		if (str == base[j])
		{
			numb = j;
			while (strl != 0)
			{
				numb = numb * basel;
				strl--;
			}
			if (str < 0)
				numb = -numb;
		}
		j++;
	}
	return (numb);
}

int	strlength(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i])
	{
		i++;
		j++;
	}
	return (j);
}

int	vfstrbase(char *str, char *base)
{
	int	vfnumb;
	int	i;
	int	l;

	i = 0;
	while (str[i])
	{
		l = 0;
		vfnumb = 0;
		while (base[l])
		{
			if (str[i] < 0)
				if (str[i] == base[l])
					vfnumb = 1;
			l++;
		}
		if (vfnumb == 0)
			return (0);
		i++;
	}
	return (l);
}

int	basevf(char c, char *base, int l)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i] && i != l)
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	strl;
	int	i;
	int	numb;

	numb = 0;
	i = 0;
	while (base[i])
	{
		if (!basevf(base[i], base, i))
			return (0);
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ')
			return (0);
		i++;
	}
	if (!vfstrbase(str, base) || vfstrbase(str, base) == 1)
		return (0);
	strl = strlength(str);
	i = 0;
	while (strl)
	{
		numb += numbasetonumb(str[i], base, vfstrbase(str, base), strl - 1);
		i++;
		strl--;
	}
	return (numb);
}
