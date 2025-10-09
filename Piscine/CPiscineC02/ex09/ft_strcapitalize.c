/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:49:33 by juannune          #+#    #+#             */
/*   Updated: 2025/07/01 12:15:00 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_alphanumvf(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int		i;
	int		new_str;

	i = 0;
	new_str = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'a' && str[i] <= 'z') && !new_str)
			str[i] -= 32;
		if ((str[i] >= 'A' && str[i] <= 'Z') && new_str)
			str[i] += 32;
		if (ft_alphanumvf(str[i]))
			new_str = 1;
		else
		{
			new_str = 0;
		}
		i++;
	}
	return (str);
}
