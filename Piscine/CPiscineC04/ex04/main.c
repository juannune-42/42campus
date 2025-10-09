/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 02:56:09 by juannune          #+#    #+#             */
/*   Updated: 2025/07/01 22:33:22 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void ft_putnbr_base(int nbr, char *base);

int	main(int argc, char **argv)
{
	int a;
	if (argc != 3)
		return (0);
	
	a = atoi(argv[1]);
	ft_putnbr_base(a, argv[2]);
	return (0);
}
