/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 10:41:59 by juannune          #+#    #+#             */
/*   Updated: 2025/06/21 10:54:21 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_lib_num(int permutations[4][6][4], int i, int j, int l)
{
	if (l == 0)
	{
		permutations[i][j][l] = i + 1;
	}
	if (l % 2 != 0)
	{
		//permutations[i][j][l] = 0;
	}
	if (l % 2 == 0)
	{
		//permutations[i][j][l] = 0;
	}
	printf("%d ", permutations[i][j][l]);
}

void	ft_lib(void)
{
	int	i;
	int	j;
	int	l;
	int	permutations[4][6][4];

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 6)
		{
			l = 0;
			while (l < 4)
			{
                printf("hola/");
				//ft_lib_num(permutations, i, j, l);
				l++;
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	char	arraycol[8];
	char	arrayrow[8];

	i = 0;
	// if (argc != 2)
	// return (0);
	ft_lib();
	// while (argv[1][i] != '\0')
	{
	}
	return (0);
}
