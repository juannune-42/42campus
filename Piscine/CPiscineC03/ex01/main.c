/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 02:56:09 by juannune          #+#    #+#             */
/*   Updated: 2025/06/30 10:52:25 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n);

int	main(void)
{
	char			*a;
	char			*b;
	char			*c;
	char			*e;
	char			*f;
	unsigned int	n;

	a = "hola";
	b = "hola";
	c = "holA";
	char *d = "holá"; // Caracter extendido
	e = "holb";
	f = "";
	n = 2;
	printf("Comparando \"%s\" y \"%s\": %d\n", a, b, ft_strncmp(a, b, n));
	printf("Comparando \"%s\" y \"%s\": %d\n", a, c, ft_strncmp(a, c, n));
	printf("Comparando \"%s\" y \"%s\": %d\n", a, d, ft_strncmp(a, d, n));
	printf("Comparando \"%s\" y \"%s\": %d\n", a, e, ft_strncmp(a, e, n));
	printf("Comparando \"%s\" y \"%s\": %d\n", a, f, ft_strncmp(a, f, n));
	printf("Comparando \"%s\" y \"%s\": %d\n", f, f, ft_strncmp(f, f, n));
	return (0);
}
