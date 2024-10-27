/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:19:38 by fpapadak          #+#    #+#             */
/*   Updated: 2024/10/25 13:36:11 by fpapadak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef FD_SIZE
#  define FD_SIZE 1024
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*join_buf(char const *stash, char const *buffer);
char	*ft_strchr(const char *s, int c);
char	*clear_stash(char *stash);

#endif
