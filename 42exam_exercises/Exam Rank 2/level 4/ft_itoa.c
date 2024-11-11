
#include <stdlib.h>

int	ft_count(long nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
		i++;
	while (nb)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char    *ft_itoa(int nbr)
{
	char	*res;
	int	len;
	int	sign;
	long	nb;

	nb = nbr;
	sign = 0;
	if (nb < 0)
	{
		sign = 1;
		nb = -nb;
	}
	len = ft_count(nb) + sign;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	while (--len >= 0)
	{
		res[len] = nb % 10 + '0';
		nb = nb / 10;
	}
	if (sign)
		res[0] = '-';
	return (res);

}

#include <stdio.h>

int	main()
{
	printf("%s\n", ft_itoa(214783647));
}

