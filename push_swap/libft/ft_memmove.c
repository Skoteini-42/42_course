/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 10:36:07 by fpapadak          #+#    #+#             */
/*   Updated: 2024/09/25 09:32:52 by fpapadak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (dest <= src)
		ft_memcpy(d, s, n);
	else if (dest > src)
	{
		while (n > 0)
		{
			d[n - 1] = s[n - 1];
			--n;
		}
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	s1[13] = Hullo there!"";
	char	d1[7];

	ft_memmove(d1, s1, 6);
	printf("%s\n", d1);
	memmove(d1, s1, 6);
	printf("%s", d1);
}*/
