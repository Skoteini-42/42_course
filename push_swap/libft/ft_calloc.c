/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:15:28 by fpapadak          #+#    #+#             */
/*   Updated: 2024/09/24 14:58:59 by fpapadak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*str;

	str = (void *)malloc(nmemb * size);
	if (!str)
		return (NULL);
	ft_memset(str, 0, nmemb * size);
	return (str);
}
/*
#include <stdio.h>

int	main(void)
{
	void	*tab;
	int	i = 0;

	while (i < 4)
	{

		tab = calloc(4 ,1);
		printf("%c\n", ((char *)tab)[i] + 48);
		tab = ft_calloc(4, 1);
		printf("%c\n", ((char *)tab)[i] + 48);
		i++;
	}
	free(tab);	
}*/
