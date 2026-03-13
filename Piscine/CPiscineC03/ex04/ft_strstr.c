/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 11:02:20 by juannune          #+#    #+#             */
/*   Updated: 2026/03/13 13:00:07 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	if (!*to_find)
		return (str);
	i = -1;
	while (str[++i])
	{
		j = -1;
		while (to_find[++j] && str[i + j] == to_find[j])
			;
		if (!to_find[j])
			return (&str[i]);
	}
	return (0);
}
// if (!*to_find) return str;
// for (int i = 0; str[i]; i++)
//     for (int j = 0; to_find[j] && str[i+j] == to_find[j]; j++)
//         if (!to_find[j]) return str + i;
