/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:15:02 by juannune          #+#    #+#             */
/*   Updated: 2026/03/11 12:27:50 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_print_memory(void *addr, unsigned int size);

int	main(int argc, char **argv)
{
	int	i;

	if (argc != 2)
		return (0);
	i = 0;
	while (argv[1][i])
		i++;
	ft_print_memory(argv[1], i);
	return (0);
}
// Bonjour les aminches\t\v\rc\n est fou\ntout\tce
// qu on peut faire avec\n\t\tprint_memory\t\t\n\nlol\nlol\t
