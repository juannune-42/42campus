/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 03:46:09 by juannune          #+#    #+#             */
/*   Updated: 2026/01/31 04:02:26 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void	ft_putchar_terminal(char c);
void	ft_putchar_test_file(char c);

int	main(void)
{
	ft_putchar_terminal('T');
	ft_putchar_test_file('H');
	return (0);
}

void	ft_putchar_terminal(char c)
{
	write(1, &c, 1);
}

void	ft_putchar_test_file(char c)
{
	int	fd;

	fd = open("test.txt", O_RDWR);
	if (fd > 0)
		write(fd, &c, 1);
	else
		write(2, "test.txt not found.\n", 20);
}
