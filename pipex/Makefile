# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/23 15:29:36 by fpapadak          #+#    #+#              #
#    Updated: 2025/01/20 15:18:18 by fpapadak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a
INCLUDE = -I. -I$(LIBFT_DIR)

SRC = pipex.c utils.c cmd.c execute.c

OBJ = $(SRC:.c=.o)

all: make_libft $(NAME)

%.o:%.c		Makefile pipex.h
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

make_libft:
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) -L$(LIBFT_DIR) -lft

clean:
	rm -rf $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	rm -rf $(LIBFT)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re
