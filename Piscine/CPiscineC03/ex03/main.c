/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 02:56:09 by juannune          #+#    #+#             */
/*   Updated: 2025/06/30 10:53:23 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb);

int	main(void)
{
	char	src1[] = " mundo";
	char	src2[] = "!";
	char	src3[] = " ¿Cómo estás?";
	int		nb;

	char dest[100] = "hola"; // Array con espacio suficiente
	nb = 5;
	printf("Antes: %s\n", dest);
	ft_strncat(dest, src1, nb);
	printf("Después de src1: %s\n", dest);
	ft_strncat(dest, src2, nb);
	printf("Después de src2: %s\n", dest);
	ft_strncat(dest, src3, nb);
	printf("Después de src3: %s\n", dest);
	return (0);
}
