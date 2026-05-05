# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/14 14:59:00 by vcodrean          #+#    #+#              #
#    Updated: 2025/11/29 03:35:47 by juannune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CCFLAGS = -Wall -Wextra -Werror
RM = rm -rf

MY_SOURCES =	ft_atoi.c\
				ft_itoa.c\
				ft_bzero.c\
                ft_split.c\
				ft_strdup.c\
				ft_strlen.c\
				ft_strchr.c\
				ft_calloc.c\
				ft_substr.c\
				ft_memset.c\
				ft_memchr.c\
				ft_memcmp.c\
				ft_memcpy.c\
				ft_memmove.c\
				ft_toupper.c\
				ft_tolower.c\
				ft_isdigit.c\
				ft_isalnum.c\
				ft_isalpha.c\
				ft_isascii.c\
				ft_isprint.c\
				ft_strrchr.c\
                ft_strmapi.c\
				ft_strlcpy.c\
				ft_strlcat.c\
				ft_strjoin.c\
				ft_strtrim.c\
				ft_strncmp.c\
				ft_strnstr.c\
                ft_striteri.c\
				ft_putstr_fd.c\
				ft_putnbr_fd.c\
				ft_putchar_fd.c\
				ft_putendl_fd.c

MY_SOURCES_BONUS =    ft_lstnew.c\
                      ft_lstmap.c\
                      ft_lstsize.c\
                      ft_lstlast.c\
                      ft_lstiter.c\
                      ft_lstclear.c\
                      ft_lstdelone.c\
                      ft_lstadd_back.c\
                      ft_lstadd_front.c

OBJS = $(MY_SOURCES:.c=.o)
OBJS_BONUS = $(MY_SOURCES_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar crs $(NAME) $(OBJS)

bonus: $(OBJS) $(OBJS_BONUS)
	@ar rcs $(NAME) $(OBJS) $(OBJS_BONUS)

%.o: %.c
	@$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	@$(RM) $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
