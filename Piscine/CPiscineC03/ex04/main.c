/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 02:56:09 by juannune          #+#    #+#             */
/*   Updated: 2025/06/30 11:32:34 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find);

int	main(void)
{
	char	*str = "Hola mundo, esto es una prueba!";
	char	*to_find = "mundo";
	char	*result;

	result = ft_strstr(str, to_find);
	if (result)
		printf("Encontrado: '%s'\n", result);
	else
		printf("No encontrado.\n");
	return (0);
}
