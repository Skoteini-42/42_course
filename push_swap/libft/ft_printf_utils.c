/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:42:41 by fpapadak          #+#    #+#             */
/*   Updated: 2024/10/14 14:22:59 by fpapadak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char ch)
{
	if (write(1, &ch, 1) < 0)
		return (-1);
	return (1);
}

int	print_string(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (print_string("(null)"));
	while (*str)
	{
		if (print_char(*str++) < 0)
			return (-1);
		len++;
	}
	return (len);
}

int	print_unumber(unsigned int nb)
{
	int	nb_len;

	nb_len = 0;
	if (nb < 10)
	{
		if (print_char(nb + '0') < 0)
			return (-1);
		nb_len = 1;
	}
	else
	{
		nb_len = nb_len + print_unumber(nb / 10);
		if (print_char((nb % 10) + '0') < 0)
			return (-1);
		nb_len++;
	}
	return (nb_len);
}

int	print_number(int nb)
{
	int	nb_len;

	nb_len = 0;
	if (nb <= -2147483648)
		return (print_string("-2147483648"));
	if (nb < 0)
	{
		if (print_char('-') < 0)
			return (-1);
		nb_len++;
		nb = -nb;
	}
	return (nb_len + print_unumber((unsigned int)nb));
}

int	print_hexnumber(unsigned long long nb, char f)
{
	int	nb_len;

	nb_len = 0;
	if (nb >= 16)
		nb_len = nb_len + print_hexnumber(nb / 16, f);
	if (nb % 16 < 10)
	{
		if (print_char(nb % 16 + '0') < 0)
			return (-1);
	}
	else
	{
		if (f == 'x' && print_char((nb % 16) - 10 + 'a') < 0)
			return (-1);
		else if (f == 'X' && print_char((nb % 16) - 10 + 'A') < 0)
			return (-1);
	}
	return (nb_len + 1);
}
