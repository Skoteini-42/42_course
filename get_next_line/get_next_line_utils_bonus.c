/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:18:41 by fpapadak          #+#    #+#             */
/*   Updated: 2024/10/25 13:40:15 by fpapadak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
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
	joined = (char *)malloc(sizeof(char) * (ft_strlen(stash)
				+ ft_strlen(buffer) + 1));
	if (!joined)
		return (NULL);
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
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
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
