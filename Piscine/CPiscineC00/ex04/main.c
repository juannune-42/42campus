/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 14:42:59 by juannune          #+#    #+#             */
/*   Updated: 2025/12/05 15:46:06 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>

void	ft_is_negative(int n);

int	main(int argc, char **argv)
{
	if (argc > 1)
		while (*++argv)
			ft_is_negative(atoi(*argv));
	return (0);
}
