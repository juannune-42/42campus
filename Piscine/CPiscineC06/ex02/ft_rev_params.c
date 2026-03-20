/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 03:18:52 by juannune          #+#    #+#             */
/*   Updated: 2026/03/20 13:00:32 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	j;

	if (argc == 1)
		return (0);
	while (argc-- > 1)
	{
		j = 0;
		while (argv[argc][j])
			write(1, &argv[argc][j++], 1);
		write(1, "\n", 1);
	}
	return (0);
}
