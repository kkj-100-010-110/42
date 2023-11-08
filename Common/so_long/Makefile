NAME = so_long
CC = gcc
OBJS = $(SRCS:%.c=%.o)
CFLAGS = -Wall -Wextra -Werror
SRCS = so_long_utils.c		\
	  so_long.c				\
	  so_long_map_check.c	\
	  so_long_key.c			\
	  so_long_image.c		\
	  get_next_line.c		\
	  get_next_line_utils.c	

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(CLIB) $(SRCS) -o $(NAME) -lmlx -framework OpenGL -framework AppKit -lz

%.o :%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re :
	make fclean
	make all

.PHONY : all bonus clean fclean re
