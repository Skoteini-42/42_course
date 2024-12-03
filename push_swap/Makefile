# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 10:16:56 by fpapadak          #+#    #+#              #
#    Updated: 2024/12/02 11:53:43 by fpapadak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDE = -I. -I$(LIBFT_DIR)

SRCS = push_swap.c check_args1.c check_args2.c arg_utils.c ops_push.c ops_swap.c \
      ops_rot.c ops_rrot.c sort_small_numsets.c stack_utils1.c \
      stack_utils2.c radix_sort.c

LIBFT_SRCS = libft/ft_atoi.c libft/ft_bzero.c libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isdigit.c \
			 libft/ft_isprint.c libft/ft_itoa.c libft/ft_memchr.c libft/ft_memcmp.c \
			 libft/ft_memcpy.c libft/ft_memmove.c libft/ft_memset.c libft/ft_putchar_fd.c \
			 libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_putstr_fd.c libft/ft_split.c \
			 libft/ft_strchr.c libft/ft_strdup.c libft/ft_strjoin.c libft/ft_strlcat.c \
			 libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_strmapi.c libft/ft_strncmp.c \
			 libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_substr.c libft/ft_tolower.c \
			 libft/ft_toupper.c libft/ft_printf.c libft/ft_printf_utils.c

OBJS = $(SRCS:.c=.o)

LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)

%.o: %.c	Makefile push_swap.h libft/libft.h
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

${NAME}: $(OBJS) $(LIBFT)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) -L $(LIBFT_DIR) -lft

$(LIBFT): $(LIBFT_OBJS)
	ar rcs  $(LIBFT) $(LIBFT_OBJS)

$(LIBFT_DIR)/%.o: $(LIBFT_DIR)/%.c $(LIBFT_DIR)/libft.h
	$(CC) $(FLAGS) -I$(LIBFT_DIR) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)
	make -C  $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C  $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
