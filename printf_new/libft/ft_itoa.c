/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:09:04 by fpapadak          #+#    #+#             */
/*   Updated: 2024/10/09 13:52:11 by fpapadak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	ft_count(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	fill_string(char *str, long nb, int len)
{
	while (--len >= 0)
	{
		str[len] = nb % 10 + 48;
		nb = nb / 10;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		sign;
	long	nb;

	nb = n;
	sign = 0;
	if (nb < 0)
	{
		sign = 1;
		nb = -nb;
	}
	len = ft_count(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	fill_string(str, nb, len);
	if (sign)
		str[0] = '-';
	return (str);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%s", ft_itoa(-2147483648));
}*/
