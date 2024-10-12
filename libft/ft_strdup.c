/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:20:33 by fpapadak          #+#    #+#             */
/*   Updated: 2024/09/23 09:31:35 by fpapadak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*res;

	if (!s)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
/*
#include <stdio.h>
#include <string.h>

int	main(int argc, char **argv)
{
	char	*des;

	if (argc == 2)
	{
		des = ft_strdup(argv[1]);
		printf("%s\n", des);
		des = strdup(argv[1]);
		printf("%s", des);
	}
	return (0);
}*/
