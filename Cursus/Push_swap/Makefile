# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juannune <juannune@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/08 13:46:17 by juannune          #+#    #+#              #
#    Updated: 2026/05/17 13:56:23 by juannune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

CC     = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = push_swap.c \
		parser.c \
		parser_utils.c \
		utils.c \
    	size.c \
		indexer.c \
    	operations_a.c \
		operations_b.c \
		operations.c \
		sorter.c \
		sorter_radix.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR     = libft
FTPRINTF_DIR  = ft_printf

LIBFT = $(LIBFT_DIR)/libft.a
FTPRINTF = $(FTPRINTF_DIR)/libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	@make -C $(FTPRINTF_DIR)
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(FTPRINTF_DIR) $(OBJS) \
		$(LIBFT_DIR)/libft.a $(FTPRINTF_DIR)/libftprintf.a -o $(NAME)

clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(FTPRINTF_DIR) clean
	@rm -f $(OBJS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@make -C $(FTPRINTF_DIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re