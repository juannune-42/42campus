/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:07:55 by juannune          #+#    #+#             */
/*   Updated: 2025/12/10 21:04:49 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
void	ft_putstr(char *str);

int	main(int argc, char **argv)
{
	if(argc == 2)
		ft_putstr(argv[1]);
	return (0);
}
