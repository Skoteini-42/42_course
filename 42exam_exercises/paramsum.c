
#include <unistd.h>

void	ft_putnbr(int nb)
{
	if (nb >= 10)
		ft_putnbr (nb / 10);
	nb = nb % 10 + '0';
	write (1, &nb, 1);
}

int	main(int argc, char **argv)
{	
	(void) argv;
	ft_putnbr(argc - 1);
	write (1, "\n", 1);
	return (0);	
}
