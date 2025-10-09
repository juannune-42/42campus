/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:07:55 by juannune          #+#    #+#             */
/*   Updated: 2025/06/23 15:11:16 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_sort_int_tab(int *stab, int size);

int	main(void)
{
	int	i;
	int	tab[] = {-5, 1, 45, -21, 3};
	int	size;

	size = 5;
	i = 0;
	while (i < size)
	{
		printf("%d ", tab[i]);
		i++;
	}
	ft_sort_int_tab(tab, size);
	i = 0;
	printf("\n");
	while (i < size)
	{
		printf("%d ", tab[i]);
		i++;
	}
	return (0);
}
