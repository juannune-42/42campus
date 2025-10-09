/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:40:03 by juannune          #+#    #+#             */
/*   Updated: 2025/06/23 16:01:03 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcpy(char *dest, char *src);

int	main(int argc, char **argv)
{
	if(argc !=3)
		return (1);
	printf("src:%s\n", argv[1]);
	printf("dest:%s", ft_strcpy(argv[1], argv[2]));
	return (0);
}
