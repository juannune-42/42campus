/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:07:55 by juannune          #+#    #+#             */
/*   Updated: 2025/12/10 20:31:14 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	ft_div_mod(int a, int b, int *div, int *mod);

int	main(int argc, char **argv)
{
	int	div;
	int	mod;

	if (argc == 3)
	{
		ft_div_mod(atoi(argv[1]), atoi(argv[2]), &div, &mod);
		printf("div /: %d\nmod %%: %d", div, mod);
	}
	return (0);
}
