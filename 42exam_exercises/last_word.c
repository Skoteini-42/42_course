
#include <unistd.h>

int	is_space(char c)
{
	if (c == 32 || (c >=9 && c <= 13))
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
			i++;
		i--;
		while (argv[1][i] && is_space(argv[1][i]))
			i--;
		while (argv[1][i] && !is_space(argv[1][i]))
			i--;
		i++;
		while(argv[1][i] && !is_space(argv[1][i]))
		{
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write (1, "\n",1 );
}
