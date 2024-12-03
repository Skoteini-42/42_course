/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:39:07 by fpapadak          #+#    #+#             */
/*   Updated: 2024/12/02 11:11:35 by fpapadak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_numeric(const char *c)
{
	if (*c == '-' || *c == '+')
		c++;
	if (*c == '\0')
		return (0);
	while (*c)
	{
		if (*c < '0' || *c > '9')
			return (0);
		c++;
	}
	return (1);
}

static int	is_overflow(const char *c)
{
	int	sign;
	int	value;
	int	nb;

	sign = 1;
	value = 0;
	if (*c == '-')
	{
		sign = -1;
		c++;
	}
	else if (*c == '+')
		c++;
	while (*c >= '0' && *c <= '9')
	{
		nb = *c - '0';
		if ((sign == 1 && (value > INT_MAX / 10
					|| (value == INT_MAX / 10 && nb > INT_MAX % 10)))
			|| (sign == -1 && (value > INT_MAX / 10
					|| (value == INT_MAX / 10 && nb > -(INT_MIN % 10)))))
			return (1);
		value = value * 10 + nb;
		c++;
	}
	return (0);
}

int	is_int_str(const char *str)
{
	char	**array;
	int		i;
	int		value;

	array = ft_split(str, ' ');
	i = 0;
	if (!array)
		return (0);
	while (array[i])
	{
		value = ft_atoi(array[i]);
		if (!is_numeric(array[i]) || is_overflow(array[i]))
		{
			free_arr(array);
			return (0);
		}
		i++;
	}
	free_arr(array);
	return (1);
}
