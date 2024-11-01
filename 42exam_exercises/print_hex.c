
#include <unistd.h>

void	base_hex(unsigned int nb)
{	
	char *digits = "0123456789abcdef";

	if (nb >= 16)
		base_hex(nb / 16);
	nb = digits[nb % 16];
	write (1, &nb, 1);
}

unsigned int	ft_atoi(char *s)
{
	unsigned int	i;
	unsigned int	nb;

	i = 0;
	nb = 0;
	while (s[1] && (s[i] >= '0' && s[i] <= '9'))
	{
		nb = nb * 10 + s[i] - '0';
		i++;
	}
	return (nb);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		base_hex(ft_atoi(argv[1]));
	write (1, "\n", 1);
}

