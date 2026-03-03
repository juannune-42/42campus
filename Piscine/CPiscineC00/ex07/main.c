/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 14:42:59 by juannune          #+#    #+#             */
/*   Updated: 2026/03/03 11:10:49 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_putnbr(int b);

int	main(int argc, char **argv)
{
	if (argc > 1)
		while (*++argv)
			ft_putnbr(atoi(*argv));
	return (0);
}
