/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:08:58 by fpapadak          #+#    #+#             */
/*   Updated: 2024/09/23 14:16:14 by fpapadak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	ft_atoi(const char *nptr)
{
	int					i;
	unsigned long long	n;

	i = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-')
		i = i * (-1);
	if (*nptr == '+' || *nptr == '-')
		nptr++;
	n = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		n = (n * 10) + (*nptr - '0');
		if (n > LLONG_MAX && i == 1)
			return (-1);
		if (n > LLONG_MAX && i == -1)
			return (0);
		nptr++;
	}
	return (n * i);
}
/*
#include <stdio.h>

int	main(int argc, char **argv)
{	
	if (argc == 2)
	{
		printf("%d\n", ft_atoi(argv[1]));
		printf("%d", atoi(argv[1]));
	}
	return (0);
}*/
