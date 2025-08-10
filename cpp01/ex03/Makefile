NAME = unnecessary_violence
FLAGS = -Wall -Werror -Wextra -MMD -std=c++98
SRCS = main.cpp \
	Weapon.cpp \
	HumanA.cpp \
	HumanB.cpp

OBJS_DIR = obj
OBJS = $(addprefix $(OBJS_DIR)/,$(SRCS:.cpp=.o))
DEPS = $(OBJS:.o=.d)

all : $(NAME)

$(NAME): $(OBJS)
	c++ -o $@ $^

$(OBJS_DIR)/%.o: %.cpp Makefile
	@mkdir -p $(@D)
	c++ $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS_DIR)
	rm -f $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re