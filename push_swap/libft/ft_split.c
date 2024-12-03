/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:27:00 by fpapadak          #+#    #+#             */
/*   Updated: 2024/09/23 14:05:35 by fpapadak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(const char *s, char sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == sep)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != sep)
			i++;
	}
	return (count);
}

static char	*extract(const char *s, char sep)
{
	char	*string;
	int		i;
	int		l;

	l = 0;
	while (s[l] && s[l] != sep)
		l++;
	string = (char *)malloc(sizeof(char) * (l + 1));
	if (!string)
		return (NULL);
	i = 0;
	while (i < l)
	{
		string[i] = s[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

static char	*add(const char *s, char sep, int i, char **tab)
{
	tab[i] = extract(s, sep);
	if (!tab[i])
	{
		while (i > 0)
		{
			i--;
			free(tab[i]);
		}
		free(tab);
		return (NULL);
	}
	return (tab[i]);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		word;
	char	**final_array;

	if (!s)
		return (NULL);
	word = count(s, c);
	final_array = (char **)malloc(sizeof(char *) * (word + 1));
	if (!final_array)
		return (NULL);
	i = 0;
	while (i < word)
	{
		while (*s && *s == c)
			s++;
		final_array[i] = add(s, c, i, final_array);
		if (!final_array[i])
			return (NULL);
		while (*s && *s != c)
			s++;
		i++;
	}
	final_array[i] = NULL;
	return (final_array);
}
/*
#include <stdio.h>

int	main(void)
{
	char	**str;
	int	i = 0;

	str = ft_split("Hullo.there.mate.", '.');
	while (str[i])
	{
		printf("%s", str[i]);
		i++;
	}
	free(str);	
}*/
