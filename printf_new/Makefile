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
HEADERS = ft_printf.h libft/libft.h
INCLUDE = -I. -I$(LIBFT_DIR)
SRCS = ft_printf.c ft_printf_utils.c
OBJS = ${SRCS:.c=.o}

LIBFT_SRCS = libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_isalnum.c \
             libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c libft/ft_isprint.c \
             libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_memmove.c \
             libft/ft_memset.c libft/ft_strchr.c libft/ft_strdup.c libft/ft_strjoin.c \
             libft/ft_strlen.c libft/ft_strncmp.c libft/ft_strnstr.c libft/ft_strrchr.c \
             libft/ft_substr.c

LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)

all : $(NAME)

$(NAME):	$(OBJS) $(LIBFT)
		cp $(LIBFT) $(NAME)
		ar rcs $(NAME) $(OBJS)

$(LIBFT):	$(LIBFT_OBJS)
		$(MAKE) -C $(LIBFT_DIR)
		ar rcs $(LIBFT) $(LIBFT_OBJS)

%.o: %.c	$(HEADERS) Makefile
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean :
		rm -f $(OBJS)
		$(MAKE) clean -C $(LIBFT_DIR)

fclean : clean
		rm -f $(NAME)
		$(MAKE) fclean -C $(LIBFT_DIR)

re : fclean all

.PHONY : all clean fclean re
