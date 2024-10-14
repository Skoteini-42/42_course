/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:35:32 by fpapadak          #+#    #+#             */
/*   Updated: 2024/09/24 14:49:30 by fpapadak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*pos;

	if (!s)
		return (NULL);
	pos = 0;
	while (*s)
	{
		if (*s == c)
			pos = (char *)s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	if (pos)
		return (pos);
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int	main(int argc, char **argv)
{
	if (argc == 3)
	{	
		printf("%s\n", ft_strrchr(argv[1], argv[2][0]));
		printf("%s", strrchr(argv[1], argv[2][0]));
	}
	return (0);	
}*/
