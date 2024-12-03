/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:46:12 by fpapadak          #+#    #+#             */
/*   Updated: 2024/12/02 11:55:21 by fpapadak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	if (!s)
		return ;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	tab[13] = "Hullo there!";
	int	i = 0;
	
	ft_bzero(tab, 5);
	while (i < 13)
	{
		if (tab[i] == 0)
			printf("\\0");
		else
			printf("%c", tab[i]);
		i++;	
	}
	printf("\n");
}*/
