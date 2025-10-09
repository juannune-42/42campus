/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 02:56:09 by juannune          #+#    #+#             */
/*   Updated: 2025/06/30 10:57:14 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strcmp(char *s1, char *s2);

int	main(void)
{
	char	*a;
	char	*b;
	char	*c;
	char	*d;
	char	*e;

	a = "hola";
	b = "hola";
	c = "holA";
	d = "holá";
	e = "";
	printf("Comparando \"%s\" y \"%s\": %d\n", a, b, ft_strcmp(a, b));
	printf("Comparando \"%s\" y \"%s\": %d\n", a, c, ft_strcmp(a, c));
	printf("Comparando \"%s\" y \"%s\": %d\n", a, d, ft_strcmp(a, d));
	printf("Comparando \"%s\" y \"%s\": %d\n", a, e, ft_strcmp(a, e));
	printf("Comparando \"%s\" y \"%s\": %d\n", a, f, ft_strcmp(a, f));
	printf("Comparando \"%s\" y \"%s\": %d\n", f, f, ft_strcmp(f, f));
	return (0);
}
