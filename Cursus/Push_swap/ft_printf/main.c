#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int	main()
{
	ft_printf("|%u|", -1);
	printf("|%u|", -1);
	return (0);
}