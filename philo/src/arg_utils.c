#include "philo.h"

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

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	is_valid_number(char *str)
{
	int		i;
	long	n;

	i = 0;
	n = 0;
	if (str[i] == '\0' || str[i] == '-')
		return (0);
	if (str[i] == '+' && str[i + 1] != '\0')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		n = n * 10 + (str[i] - '0');
		if (num > INT_MAX)
			return (0);
		i++;
	}
	if (n >= 1)
		return (1);
	else
		return (0);
}
