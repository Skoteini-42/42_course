# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/19 15:04:32 by fpapadak          #+#    #+#              #
#    Updated: 2024/09/24 14:28:29 by fpapadak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_isalpha.c\
       ft_isdigit.c\
       ft_isalnum.c\
       ft_isascii.c\
       ft_isprint.c\
       ft_strlen.c\
       ft_memset.c\
       ft_bzero.c\
       ft_memcpy.c\
       ft_memmove.c\
       ft_strlcpy.c\
       ft_strlcat.c\
       ft_toupper.c\
       ft_tolower.c\
       ft_strchr.c\
       ft_strrchr.c\
       ft_strncmp.c\
       ft_memchr.c\
       ft_memcmp.c\
       ft_strnstr.c\
       ft_atoi.c\
       ft_calloc.c\
       ft_strdup.c\
       ft_substr.c\
       ft_strjoin.c\
       ft_strtrim.c\
       ft_split.c\
       ft_itoa.c\
       ft_strmapi.c\
       ft_striteri.c\
       ft_putchar_fd.c\
       ft_putstr_fd.c\
       ft_putendl_fd.c\
       ft_putnbr_fd.c\
	   ft_lstnew.c\
	   ft_lstadd_front.c\
	   ft_lstsize.c\
	   ft_lstlast.c\
	   ft_lstadd_back.c\

OBJS = ${SRCS:.c=.o}
BONUS_OBJS = ${BONUS_SRCS.c=.o}

all: $(NAME)

$(NAME):	$(OBJS) Makefile libft.h
	ar rc $(NAME) $(OBJS)

bonus : $(OBJS) $(BONUS_OBJS)
	ar rc $(NAME) $(OBJS) $(BONUS_OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all bonus clean fclean re
