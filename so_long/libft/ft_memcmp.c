/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:32:42 by fpapadak          #+#    #+#             */
/*   Updated: 2024/09/25 09:45:00 by fpapadak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*src;

	dest = (unsigned char *)s1;
	src = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (dest[i] != src[i])
			return (dest[i] - src[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*d = "Hullo";
	char	*s = "Hullo";
	size_t	x = 5;

	printf("%d\n", ft_memcmp(d, s, x));
	printf("%d", memcmp(d, s, x));
}*/
