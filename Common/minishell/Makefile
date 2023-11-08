NAME = minishell
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
LDLIBS = -lreadline
LDFLAGS = -L/Users/ysungwon/.brew/opt/readline/lib
CPPFLAGS = -I/Users/ysungwon/.brew/opt/readline/include
RM = rm -f
SRCS =	main.c \
		builtins.c \
		ft_echo.c \
		ft_cd.c \
		ft_pwd.c \
		ft_export.c \
		ft_unset.c \
		ft_env.c \
		find_env.c \
		init_path.c \
		ft_exit.c \
		split_cmd.c \
		run_pipe.c \
		run_pipe_aux.c \
		signal.c \
		redir_in.c \
		redir_out.c \
		token_utils.c \
		token.c \
		utils1.c \
		utils2.c \
		utils3.c \
		utils4.c \
		del_c.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) $^ $(LDLIBS) $(LDFLAGS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re
