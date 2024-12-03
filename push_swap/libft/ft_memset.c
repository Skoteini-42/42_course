/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:05:21 by fpapadak          #+#    #+#             */
/*   Updated: 2024/09/20 10:08:48 by fpapadak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	if (!s)
		return (NULL);
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (s);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	tab[13] = "Hullo there!";
	ft_memset(tab, 'z', 4);
	printf("%s\n", tab);
	memset(tab, 'z', 4);
	printf("%s", tab);

}*/
