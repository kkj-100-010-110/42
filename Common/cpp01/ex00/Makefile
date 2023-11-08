NAME	=	zombie
CXX		=	c++
CFLAGS	=	-Wall -Werror -Wextra -std=c++98 -pedantic
RM		=	rm -rf
SRCS	=	main.cpp		\
			Zombie.cpp		\
			newZombie.cpp	\
			randomChump.cpp
OBJS	=	$(SRCS:%.cpp=%.o)
all		:	$(NAME)
%.o		: %.cpp
	$(CXX) $(CFLAGS) -o $@ -c $<
$(NAME) : $(OBJS)
	$(CXX) $(CFLAGS) -o $(NAME) $(OBJS)
clean	:
	$(RM) $(OBJS)
fclean	:	clean
	$(RM) $(NAME)
re		:	fclean all
.PHONY	:	all clean fclean re
