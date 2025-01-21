/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 09:54:38 by fpapadak          #+#    #+#             */
/*   Updated: 2024/10/26 11:28:40 by fpapadak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_slen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*join_buf(char const *stash, char const *buffer)
{
	char	*joined;
	int		i;
	int		j;

	if (!stash || !buffer)
		return (NULL);
	joined = (char *)malloc(sizeof(char) * (ft_slen(stash)
				+ ft_slen(buffer) + 1));
	if (!joined)
		return (free ((char *)stash), NULL);
	i = 0;
	while (stash[i])
	{
		joined[i] = stash[i];
		i++;
	}
	j = 0;
	while (buffer[j])
		joined[i++] = buffer[j++];
	joined[i] = '\0';
	free ((char *)stash);
	return (joined);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (NULL);
}

char	*clear_stash(char *stash)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\0')
	{
		free (stash);
		return (NULL);
	}
	new_str = (char *)malloc(sizeof(char) * (ft_slen(stash) - i + 1));
	if (!new_str)
		return (free (stash), NULL);
	i++;
	j = 0;
	while (stash[i])
		new_str[j++] = stash[i++];
	new_str[j] = '\0';
	free (stash);
	return (new_str);
}
