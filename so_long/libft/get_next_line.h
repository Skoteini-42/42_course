/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 09:54:49 by fpapadak          #+#    #+#             */
/*   Updated: 2024/10/25 09:53:38 by fpapadak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

char	*get_next_line(int fd);
size_t	ft_slen(const char *s);
char	*join_buf(char const *stash, char const *buffer);
char	*ft_strchr(const char *s, int c);
char	*clear_stash(char *stash);

#endif
