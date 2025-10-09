/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
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

void	print_permutation(int *perm)
{
	for (int i = 0; i < 4; i++)
		printf("%d ", perm[i]);
	printf("\n");
}

void	generate_permutations(int *perm, int *used, int pos)
{
	int i;
	if (pos == 4)
	{
		print_permutation(perm);
		return ;
	}
	i = 1;
	while (i <= 4)
	{
		if (!used[i])
		{
			perm[pos] = i;
			used[i] = 1;
			generate_permutations(perm, used, pos + 1);
			used[i] = 0; // backtrack
		}
		i++;
	}
}

int	main(void)
{
	int perm[4];
	int used[5] = {0}; // índice 0 no se usa para simplificar
	generate_permutations(perm, used, 0);
	return (0);
}
