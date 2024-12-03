/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:13:30 by fpapadak          #+#    #+#             */
/*   Updated: 2024/09/13 14:06:26 by fpapadak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = 0;
	while (src[l])
		l++;
	if (size < 1)
		return (l);
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (l);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	s[13] = "Hullo there!";
	char	d[13];

	printf("%zu\n", ft_strlcpy(d, s, 13));
	printf("%zu", ft_strlen(strncpy(d, s, 13)));
}*/
