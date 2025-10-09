/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 02:56:09 by juannune          #+#    #+#             */
/*   Updated: 2025/06/30 10:52:31 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcat(char *dest, char *src);

int	main(void)
{
	char	src1[] = " mundo";
	char	src2[] = "!";
	char	src3[] = " ¿Cómo estás?";

	char dest[100] = "hola"; // Array con espacio suficiente
	printf("Antes: %s\n", dest);
	ft_strcat(dest, src1);
	printf("Después de src1: %s\n", dest);
	ft_strcat(dest, src2);
	printf("Después de src2: %s\n", dest);
	ft_strcat(dest, src3);
	printf("Después de src3: %s\n", dest);
	return (0);
}
