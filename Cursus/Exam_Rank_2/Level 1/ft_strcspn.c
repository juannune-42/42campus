/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 04:53:01 by juannune          #+#    #+#             */
/*   Updated: 2026/02/17 04:02:03 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i;
	for	(i = 0; s[i]; i++)
		for (size_t	j = 0; reject[j]; j++)
			if (s[i] == reject[j])
				return (i);
	return (i);
}
