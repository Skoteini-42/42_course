#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

void	putstr(char *s, int *len)
{
	int i = 0;

	if (!s)
		s = "(null)";
	while (s[i])
	{
		*len += write(1, &s[i], 1);
		i++;
	}
}

void	putnum(long long int n, unsigned int base, int *len)
{
	if (n < 0)
	{
		n = n * (-1);
		*len += write(1, "-", 1);
	}
	if (n >= base)
		putnum((n / base), base, len);
	*len += write(1, &"0123456789abcdef"[n % base], 1);
}

int	ft_printf(char *fmt, ...)
{
	va_list	ptr;
	int	len = 0;
	int	i = 0;

	va_start(ptr, fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%' && ((fmt[i + 1] == 's') || (fmt[i + 1] == 'd')
			|| (fmt[i + 1] == 'x')))
		{
			i++;
			if (fmt[i] == 's')
				putstr(va_arg(ptr, char *), &len);
			if (fmt[i] == 'd')
				putnum((long long int)va_arg(ptr, int), 10, &len);
			if (fmt[i] == 'x')
				putnum((long long int)va_arg(ptr, unsigned int), 16, &len);
		}
		else
			len += write(1, &fmt[i], 1);
		i++;	
	}
	return (va_end(ptr), len);
}
