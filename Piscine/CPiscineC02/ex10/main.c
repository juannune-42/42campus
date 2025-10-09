/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:15:02 by juannune          #+#    #+#             */
/*   Updated: 2025/06/24 16:37:45 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

int	main(void)
{
	char			dest[] = "salut, comment tu vas ?";
	char			src[] = "salut";
	unsigned int	size;

	size = 24;
	printf("%s\n", dest);
	printf("%s\n", src);

	printf("%d\n", ft_strlcpy(dest, src, size));
	printf("%s\n", dest);
	return (0);
}
