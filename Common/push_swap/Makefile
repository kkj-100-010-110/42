# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyeokim <gyeokim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/20 14:25:32 by gyeokim           #+#    #+#              #
#    Updated: 2022/08/30 11:37:48 by gyeokim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP = push_swap
CHECKER = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f
SRCS = srcs
PUSH_SWAP_SRCS = main.c \
	   			 ft_split_atoi.c \
	   			 push_swap_utils.c \
	   			 push_swap.c \
	   			 list_add_remove.c \
	   			 list_create_get_pop.c \
	   			 operations_one.c \
	   			 operations_two.c \
	   			 error.c \
	   			 sorting_few.c

CHECKER_SRCS = 	checker.c \
				ft_split_atoi.c \
				push_swap_utils.c \
				push_swap.c \
				list_add_remove.c \
				operations_one.c \
				operations_two.c \
				list_create_get_pop.c \
				operations_one_b.c \
				operations_two_b.c \
				error.c \
				sorting_few.c \
				get_next_line.c \
				get_next_line_utils.c \
				ft_strncmp.c

PUSH_SWAP_OBJS = $(PUSH_SWAP_SRCS:.c=.o)
CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)

%.o : %.c
		$(CC) $(CFLAGS) -I ./include/ -c $^ -o $@

$(PUSH_SWAP) : $(PUSH_SWAP_OBJS)
		$(CC) $(CFLAGS) $^ -o $@

$(CHECKER) : $(CHECKER_OBJS)
		$(CC) $(CFLAGS) $^ -o $@

all : $(PUSH_SWAP)

clean :
		$(RM) $(PUSH_SWAP_OBJS) $(CHECKER_OBJS)

fclean : clean
		$(RM) $(PUSH_SWAP) $(CHECKER)

re : fclean all

bonus : $(CHECKER)

.PHONY : all clean fclean re bonus
