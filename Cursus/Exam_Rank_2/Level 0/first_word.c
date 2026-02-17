/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 03:00:52 by juannune          #+#    #+#             */
/*   Updated: 2026/02/13 03:01:34 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (write(1, "\n", 1));
	while (*argv[1] == ' ' || *argv[1] == '\t')
		argv[1]++;
	while (*argv[1] && *argv[1] != ' ' && *argv[1] != '\t')
		write(1, argv[1]++, 1);
	return (write(1, "\n", 1));
}
