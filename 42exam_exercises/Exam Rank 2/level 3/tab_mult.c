
#include <unistd.h>

void	ft_putnbr(int nb)
{
	if (nb >= 10)
		ft_putnbr(nb /10);
	nb = nb % 10 + '0';
	write (1, &nb, 1);
}

int	ft_atoi(char *s)
{
	int	nb;
	int	i;

	nb = 0;
	i = 0;
	while (s[i] && (s[i] >= '0' && s[i] <= '9'))
	{
		nb = nb * 10 + s[i] - '0';
		i++;
	}
	return (nb);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		write (1, &s[i++], 1);
}

int	main(int argc, char **argv)
{
	int	i;
	int	nb;

	if (argc == 2)
	{
		nb = ft_atoi(argv[1]);
		i = 1;
		while (i < 10)
		{
			ft_putnbr(i);
			ft_putstr(" x ");
			ft_putnbr(nb);
			ft_putstr(" = ");
			ft_putnbr(i * nb);
			ft_putstr("\n");
			i++;
		}
	}
	else	
		write (1, "\n", 1);
}


