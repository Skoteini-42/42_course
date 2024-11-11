int     valid(char ch, int base);

int	ft_atoi_base(const char *str, int str_base)
{
	int	i;
	int	nb;
	int	sign;

	i = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
		i++;
	nb = 0;
	while (str[i] && valid(str[i], str_base))
	{
		nb = nb * str_base;
		if (str[i] >= '0' && str[i] <= '9')
			nb = nb + (str[i] - '0');
		else if (str[i] >= 'a' && str[i] <= 'f')
			nb = nb + (str[i] - 'a' + 10);
		else if (str[i] >= 'A' && str[i] <= 'F')
			nb = nb + (str[i] - 'A' + 10);
		i++;
	}
	return (nb * sign);
}

int	valid(char ch, int base)
{
	char	*lbase = "0123456789abcdef";
	char	*ubase = "0123456789ABCDEF";
	int	i;

	i = 0;
	while (i < base)
	{
		if (ch == lbase[i] || ch == ubase[i])
			return (1);
		i++;
	}
	return (0);
}

#include <stdio.h>

int	main()
{
	printf ("%d", ft_atoi_base("2A", 16));
}
