
#include <unistd.h>

int	is_capital(char c)
{	
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i])
		{
			if (is_capital(argv[1][i]))
			{
				argv[1][i] = argv[1][i] + 32;
				write (1, "_", 1);
			}
			write (1, &argv[1][i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
}

