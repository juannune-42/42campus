# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/13 02:02:24 by juannune          #+#    #+#              #
#    Updated: 2025/12/19 12:14:20 by juannune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
SRC =	ft_putp.c\
		ft_printf.c\
		ft_puthex.c\
		ft_putnbr.c\
		ft_putstr.c\
		ft_putchar.c\
		ft_putunsigned.c
OBJS = $(SRC:.c=.o)
AR = ar rcs
all: $(NAME)
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
clean:
	@$(RM) $(OBJS)
fclean: clean
	@rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
