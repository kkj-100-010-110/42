# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyeokim <gyeokim@student.42seoul.k>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/01 16:24:39 by gyeokim           #+#    #+#              #
#    Updated: 2022/07/02 18:18:10 by gyeokim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = pipex

SRCS = main.c \
	   pipex.c \
	   pipex_utils.c \
	   ft_split.c \
	   ft_strlen.c \
	   ft_strncmp.c \
	   ft_strjoin.c \
	   ft_strdup.c \
	   ft_substr.c

OBJS=$(SRCS:.c=.o)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
