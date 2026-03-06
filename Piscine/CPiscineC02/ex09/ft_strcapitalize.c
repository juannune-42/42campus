/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:49:33 by juannune          #+#    #+#             */
/*   Updated: 2026/03/06 11:57:08 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alphanumb(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0'
			&& c <= '9'))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	new_str;

	i = 0;
	new_str = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		if ((str[i] >= 'a' && str[i] <= 'z') && !new_str)
			str[i] -= 32;
		if (ft_str_is_alphanumb(str[i]))
			new_str = 1;
		else
			new_str = 0;
		i++;
	}
	return (str);
}
