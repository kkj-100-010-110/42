# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyeokim <gyeokim@student.42seoul.k>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 21:35:48 by gyeokim           #+#    #+#              #
#    Updated: 2022/05/24 02:36:31 by gyeokim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c \
	   specifier.c \
	   read_line.c \
	   ft_putchar_n.c \
	   ft_putper.c \
	   ft_putstr_n.c \
	   ft_putint.c \
	   ft_putuint.c \
	   ft_putptr.c \
	   ft_convert_hex.c \
	   ft_putchar.c \
	   ft_toupper.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rc $@ $^

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME) 

re : fclean all

.PHONY : all clean fclean re
