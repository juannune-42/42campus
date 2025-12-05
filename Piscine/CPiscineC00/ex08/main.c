/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 14:42:59 by juannune          #+#    #+#             */
/*   Updated: 2025/12/05 16:10:49 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_print_combn(int b);

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_print_combn(atoi(argv[1]));
	return (0);
}
