# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/18 11:38:51 by fpapadak          #+#    #+#              #
#    Updated: 2024/12/18 11:39:09 by fpapadak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
FLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a
MLX_DIR = minilibx-linux/
MLX = $(MLX_DIR)libmlx.a
INCLUDE = -I. -I$(LIBFT_DIR) -I$(MLX_DIR)

SRC = so_long.c general_utils.c game.c map_init.c map_init_utils.c render.c \
      handlers.c map_validation.c

OBJ = $(SRC:.c=.o)

all: make_lib make_mlx $(NAME)

%.o: %.c	Makefile so_long.h
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

make_lib:
	$(MAKE) -C $(LIBFT_DIR)

make_mlx:
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) -L$(LIBFT_DIR) -L$(MLX_DIR) -lmlx -lft -lX11 -lXext -lm

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -rf $(NAME)
	rm -rf $(LIBFT)
	rm -rf $(MLX)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re
