/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:15:02 by juannune          #+#    #+#             */
/*   Updated: 2025/06/24 08:41:30 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);

int	main(/*int argc, char **argv*/ void)
{
	int		i;
	char	a[] = "hola";
	char	b[] = "r";

	i = 0;
	while (a[i] != '\0')
	{
		i++;
	}
	printf("src:%s\n", a);
	printf("%d\ndest:%s", i, ft_strncpy(a, b, i));
	return (0);
	/*int i;
		if (argc != 3)
			return (1);
		i = 0;
	while (argv[2][i] != '\0')
			i++;
		printf("src: %s %s\n", argv[1], argv[2]);
	printf("%d\n", i);
	printf("dest: %s\n", ft_strncpy(argv[1], argv[2], i));
	return (0);*/
}
