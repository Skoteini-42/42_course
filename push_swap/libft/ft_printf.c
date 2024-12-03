/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 10:10:28 by fpapadak          #+#    #+#             */
/*   Updated: 2024/11/04 10:01:30 by fpapadak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_pointer(void *ptr)
{
	if (!ptr)
		return (print_string("(nil)"));
	if (print_string("0x") < 0)
		return (-1);
	return (2 + print_hexnumber((unsigned long long)ptr, 'x'));
}

static int	format_specifier(const char specifier, va_list args)
{
	int	spec_len;

	spec_len = 0;
	if (specifier == 'c')
		spec_len = print_char(va_arg(args, int));
	else if (specifier == 's')
		spec_len = print_string(va_arg(args, char *));
	else if (specifier == 'p')
		spec_len = print_pointer(va_arg(args, void *));
	else if (specifier == 'd' || specifier == 'i')
		spec_len = print_number(va_arg(args, int));
	else if (specifier == 'u')
		spec_len = print_unumber(va_arg(args, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		spec_len = print_hexnumber(va_arg(args, unsigned int), specifier);
	else if (specifier == '%')
		spec_len = print_char('%');
	return (spec_len);
}

static int	handle_specifier(const char *format, va_list args, int i)
{
	int	len;

	len = 0;
	if (ft_strchr("cspdiuxX%", format[i + 1]))
	{
		len = format_specifier(format[i + 1], args);
		if (len < 0)
			return (-1);
		return (len);
	}
	else
	{
		if (print_char(format[i + 1]) < 0)
			return (-1);
		len = 1;
	}
	return (len);
}

static int	format_handle(const char *format, va_list args)
{
	int	len;
	int	i;
	int	spec_len;

	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			spec_len = handle_specifier(format, args, i);
			if (spec_len < 0)
				return (-1);
			len = len + spec_len;
			i++;
		}
		else
		{
			if (print_char(format[i]) < 0)
				return (-1);
			len++;
		}
		i++;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		final_len;

	final_len = 0;
	va_start(args, format);
	final_len = format_handle(format, args);
	va_end(args);
	if (final_len < 0)
		return (-1);
	return (final_len);
}
/*
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	char *str = "%c,%p,%s,%d,%i,%u,%X,%x,%%\n";
	int	count;
	int	*ptr = 0;

	count = ft_printf(str, '%', ptr, "Hullo", INT_MIN,
   	INT_MAX, UINT_MAX, 0, 100000);
	printf("%c,%p,%s,%d,%i,%u,%X,%x,%%", '%', ptr, "Hullo", INT_MIN,
   	INT_MAX, UINT_MAX, 0, 100000);
	printf("\n%d\n", count);

	int	count;

	count = ft_printf("%d", INT_MIN);
	printf("count ft_printf %d\n", count);
	count = printf("%d", INT_MIN);
	printf("count printf %d\n", count);
}*/
