/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 03:26:49 by juannune          #+#    #+#             */
/*   Updated: 2025/11/29 04:04:46 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_printf(const char *c)
{
	while (*c)
		write(1, c++, 1);
	return (0);
}

int	main(void)
{
	char	*c;

	c = "hola mundo";
	ft_printf(c);
	return (0);
}
