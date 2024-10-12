/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:40:42 by fpapadak          #+#    #+#             */
/*   Updated: 2024/09/24 14:42:19 by fpapadak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	sub = (char *)malloc((sizeof(char) * len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (s[i] && i < len)
	{
		sub[i] = s[i + start];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	unsigned int	start = (unsigned int)atoi(argv[2]);
	size_t len = (size_t)atoi(argv[3]);
	char	*res = ft_substr(argv[1], start, len);

	if (argc == 4)
	{
		printf("%s", res);
		free(res);
	}
	return (0);
}*/	
