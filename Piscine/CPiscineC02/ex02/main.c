/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:15:02 by juannune          #+#    #+#             */
/*   Updated: 2025/06/24 15:38:11 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	ft_str_is_alpha(char *str);

int	main(void)
{
	char	str[] = "";
	printf("%s\n", str);
	printf("%d", ft_str_is_alpha(str));
	return (0);
}
