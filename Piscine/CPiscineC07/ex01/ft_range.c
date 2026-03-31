/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 12:27:34 by juannune          #+#    #+#             */
/*   Updated: 2026/03/31 13:26:09 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	range;
	int	*arr;

	if (min >= max)
		return (NULL);
	range = max - min;
	arr = malloc(range * sizeof(int));
	while (range--)
		arr[range] = min + range;
	return (arr);
}
