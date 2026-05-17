# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juannune <juannune@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/08 13:46:17 by juannune          #+#    #+#              #
#    Updated: 2026/05/17 14:32:21 by juannune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

CC     = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = 	sizer.c \
		utils.c \
		parser.c \
		sorter.c \
		indexer.c \
		push_swap.c \
		operations.c \
        operations_a.c \
		operations_b.c \
		parser_utils.c \
		sorter_radix.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR     = libft
FTPRINTF_DIR  = ft_printf

LIBFT = $(LIBFT_DIR)/libft.a
FTPRINTF = $(FTPRINTF_DIR)/libftprintf.a

HEADER = push_swap.h

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR) bonus

$(FTPRINT):
	@make -C $(FTPRINTF_DIR)

$(NAME): $(LIBFT) $(FTPRINT) $(OBJS)
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(FTPRINTF_DIR) $(OBJS)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)
	@make -C $(LIBFT_DIR) clean
	@make -C $(FTPRINTF_DIR) clean

fclean: clean
	$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(FTPRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re