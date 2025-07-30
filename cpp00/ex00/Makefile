NAME = megaphone
FLAGS = -Wall -Werror -Wextra -std=c++98
SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME): $(OBJS)
		c++ -o $@ $^

%.o: %.cpp Makefile
		c++ $(FLAGS) -c $< -o $@

clean :
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re