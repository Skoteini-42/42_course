
#include <unistd.h>

int	ft_atoi(char *res)
{	
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	if (res[i] == '-')
		return (-1);
	while (res[i] >= '0' && res[i] <= '9')
	{
		nb = nb * 10 + res[i] - '0';
		i++;	
	} 
	return (nb);
}

void	ft_putnbr(int nb)
{
	if (nb >= 10)
		ft_putnbr(nb / 10);
	nb = nb % 10 + '0';
	write (1, &nb, 1);
}

int	is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 1)
		return (0);
	while (i < nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	nb;
	int	sum;
	
	sum = 0;
	if (argc != 2 || ft_atoi(argv[1]) <= 0)
	{
		write(1, "0\n", 2);
		return (0);
	}
	nb = ft_atoi(argv[1]);
	while (nb > 0)
	{
		if (is_prime(nb))
			sum = sum + nb;
		nb--;
	}
	ft_putnbr(sum);
	write (1, "\n", 1);
}
