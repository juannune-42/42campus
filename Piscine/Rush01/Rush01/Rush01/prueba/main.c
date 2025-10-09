/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 01:06:15 by juannune          #+#    #+#             */
/*   Updated: 2025/06/22 01:16:32 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_col_row(char *arraycol, char *arrayrow, char **argv, int i)
{
	int	j;

	j = i / 2;
	if (i < 15)
	{
		arraycol[j] = argv[1][i];
	}
	j = (i - 15) / 2;
	if (i > 15)
	{
		arrayrow[j] = argv[1][i];
	}
}

int	main(int argc, char **argv)
{
	int		i;
	char	arraycol[8];
	char	arrayrow[8];

	i = 0;
	if (argc != 2)
		return (0);
	while (argv[1][i] != '\0')
	{
		if ((i % 2) == 0)
		{
			ft_col_row(arraycol, arrayrow, argv, i);
		}
		i++;
	}
	if (i == 31)
	{
		//ft_logica(arraycol, arrayrow);
		return (0);
	}
	return (0);
}
