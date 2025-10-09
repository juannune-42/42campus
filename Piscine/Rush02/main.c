/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 17:57:55 by juannune          #+#    #+#             */
/*   Updated: 2025/06/29 21:51:06 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

unsigned int *scrumblearray(unsigned int *input, int l, int resto)
{
	int i;
	unsigned int	*newinput;
	int c;

	newinput = (unsigned int *)malloc(l * sizeof(unsigned int));
	i = 0;
	while (i < l)
	{
		newinput[i] = input[i + resto];
		i++;
	}
	i = 0;
	while (i < l)
	{
		input[i] = newinput[i];
		i++;
	}
	/*i = 0;
	while(i < l)
	{
		c = input[i] + '0';
		write(1, "*", 1);
		write(1, &c, 1);
		write(1, "*", 1);
		i++;
	}
	write(1, "//", 2);*/
	free(newinput);
	return (input);
}
void	printnum(char *buffer, int i)
{
	i += 3;
	while (buffer[i] != '\n')
	{
		if (buffer[i] != ' ')
			write(1, &buffer[i], 1);
		i++;
	}
}

int	strlenargv(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	vf_arg(const char *argv, unsigned int *input)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] > '/' && argv[i] < ':')
		{
			input[i] = argv[i] - '0';
			// write(1, &argv[i], 1);
		}
		else
			return (0);
		i++;
	}
	return (1);
}

int	strchradec(unsigned int input, char *buffer, int next)
{
	int	i;

	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == input + '0')
		{
			if (buffer[i + 1] == next + '0')
				return (i);
		}
		i++;
	}
	return (0);
}

int	strchra(unsigned int input, char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == input + '0')
			return (i);
		i++;
	}
	return (0);
}
int	strchrahundred(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '1')
		{
			j = 0;
			while (buffer[i + 1] == '0')
			{
				j++;
				i++;
			}
			if (j == 2)
				return (i - 1);
		}
		i++;
	}
	return(0);
}

int	strchracent(char *buffer, int len)
{
	int	i;
	int	j;

	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '1')
		{
			j = 0;
			while (buffer[i] != ':')
			{
				if (buffer[i] == '0')
					j++;
				i++;
			}
			if (j == len * 3)
				return (i - 1);
		}
		i++;
	}
	return (0);
}

void	logic2(unsigned int *input, char *buffer)
{
	if (input[0] != 0)
	{
		if (input[0] == 1)
		{
			printnum(buffer, strchradec(input[0], buffer, input[1]));
			return;
		}
		else
		{
			printnum(buffer, strchradec(input[0], buffer, 0));
			if (input[1] != 0)
				write(1, "-", 1);
		}
	}
	if (input[1] != 0)
		printnum(buffer, strchra(input[1], buffer));
	if (input[1] + input[0] == 0)
		printnum(buffer, strchra(input[1], buffer));
}

void	logic3(unsigned int *input, char *buffer, int len)
{
	if (input[0] != 0)
	{
		printnum(buffer, strchra(input[0], buffer));
		write(1, " ", 1);
		printnum(buffer, strchrahundred(buffer));
		if (input[1] != 0)
			write(1, " ", 1);
	}
	if (input[1] != 0)
	{
		if (input[1] == 1)
		{
			printnum(buffer, strchradec(input[1], buffer, input[2]));
			return;
		}	
		else
		{
			printnum(buffer, strchradec(input[1], buffer, 0));
			if (input[2] != 0)
				write(1, "-", 1);
		}
	}
	if (input[2] != 0)
		printnum(buffer, strchra(input[2], buffer));
	if (input[2] == 0 && input[0] + input[1] == 0)
		printnum(buffer, strchra(input[2], buffer));
}

void	logic(unsigned int *input, char *buffer, int l)
{
	if (l == 1)
		printnum(buffer, strchra(input[0], buffer));
	if (l == 2)
		logic2(input, buffer);
	if (l == 3)
		logic3(input, buffer, l);
}

void	logicult(unsigned int *input, char *buffer, int l)
{
	int		resto;
	int		div;
	char	c;

	resto = l % 3;
	div = l / 3;
	if (resto == 0)
		resto = 3;
	/*c = resto + '0';
	write(1, &c, 1);
	c = div + '0';
	write(1, &c, 1);
	write(1, "/", 1);*/
	if (input[0] + input[1] +input [2] != 0)
	{
		logic(input, buffer, resto);
		write(1, " ", 1);
		if (div == 1)
		{
			if (resto == 3)
			{
				printnum(buffer, strchracent(buffer, div - 1));
			}
			else
			{
				printnum(buffer, strchracent(buffer, div));
			}
		}
	}
	if (div - 1 > 0)
	{
		if (input[3] + input[4] +input [5] != 0)
		{
			write(1, ", ", 2);
			logicult(scrumblearray(input, l, resto), buffer, l - resto);
		}
		if (input[3] + input[4] +input [5] == 0)
		{
			logicult(scrumblearray(input, l, resto), buffer, l - resto);
		}
	}
}

int	main(int argc, char **argv)
{
	char	buffer[1024];
	unsigned int		*input;
	int		numbytes;
	int		l;
	int		fd;

	/*if (argc == 1)
	{
		input = read(STDIN_FILENO, buffer, input - 1);
		if (input > 0) {
			buffer[input] = '\0';
		} else {
			write(2, "Error\n", 6);
		}
	}*/
	numbytes = 0;
	if (argc > 3)
		return (0);
	if (argc == 2)
	{
		l = strlenargv(argv[1]);
		input = (unsigned int *)malloc(l * sizeof(unsigned int));
		if (!vf_arg(argv[1], input))
		{
			write(2, "Errorvf", 7);
			return (0);
		}
		fd = open("numbers.dict", O_RDONLY);
		if (fd == -1)
			write(2, "Erroropen", 10);
		while ((numbytes = read(fd, buffer, 1024)) > 0)
		{
			buffer[numbytes] = '\0';
			if (l == 1)
				printnum(buffer, strchra(input[0], buffer));
			if (l == 2)
				logic2(input, buffer);
			if (l == 3)
				logic3(input, buffer, l/3);
			if (l > 3)
				logicult(input, buffer, l);
			close(fd);
		}
		free(input);
		return (0);
	}
}