/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 14:29:11 by fpapadak          #+#    #+#             */
/*   Updated: 2024/09/25 11:19:36 by fpapadak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dl;
	size_t	sl;
	size_t	j;

	sl = ft_strlen(src);
	dl = ft_strlen(dst);
	i = 0;
	j = dl;
	if (size <= dl)
		return (size + sl);
	else if (size > dl)
	{
		while (src[i] && (dl + i) < (size - 1))
		{
			dst[j] = src[i];
			i++;
			j++;
		}
		dst[j] = '\0';
	}
	return (dl + sl);
}
/*
#include <stdio.h>

int	main(void)
{
	char	dest[20] = "Hullo";
	const char *src = "there";
	size_t	size = 7;
	size_t result_ft;

	result_ft = ft_strlcat(dest, src, size);
    	printf("ft_strlcat result: %zu\n", result_ft);
		ft_strlcat(dest, src, size);
    	printf("ft_strlcat dest: '%s'\n", dest);
}*/
