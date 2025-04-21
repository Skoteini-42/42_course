NAME = philo

C_DIR = src
C_FILES = main.c \
arg_utils.c \
cleanup.c \
init.c \
simulation.c \
sim_utils.c \
mutex.c \
mutex_utils.c \
philosopher_actions.c \
monitor_utils.c

O_DIR = obj
OBJS = $(addprefix $(O_DIR)/,$(C_FILES:.c=.o))

H_DIR = inc
H_FILES = philo.h
HEADERS = $(addprefix $(H_DIR)/,$(H_FILES))

CFLAGS = -Wall -Wextra -Werror -pthread
INCLUDES = -I$(H_DIR)

all: $(NAME)

$(O_DIR)/%.o: $(C_DIR)/%.c Makefile $(HEADERS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(O_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re