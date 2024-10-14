# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/03 09:25:27 by fpapadak          #+#    #+#              #
#    Updated: 2024/10/14 12:18:21 by fpapadak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDE = ft_printf.h \
		  libft/libft.h
SRCS = ft_printf.c ft_printf_utils.c
OBJS = ${SRCS:.c=.o}

all : $(NAME)

$(NAME):	$(OBJS) $(LIBFT)
		@
		cp $(LIBFT) $(NAME)
		ar rcs $(NAME) $(OBJS)

$(LIBFT):
		$(MAKE) -C $(LIBFT_DIR)

%.o: %.c	$(INCLUDE) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean :
		rm -f $(OBJS)
		$(MAKE) clean -C $(LIBFT_DIR)

fclean : clean
		rm -f $(NAME)
		$(MAKE) fclean -C $(LIBFT_DIR)

re : fclean all

.PHONY : all clean fclean re
