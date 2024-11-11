
#include <unistd.h>

int	is_space(char c)
{
	if (c == 32 || (c >= 9 && c<= 13))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;
	int	start;
	int	end;
	int	pos;

	pos = 0;
	if (argc == 2)
	{
		i = 0;
		while (argv[1][i])
			i++;
		i--;
		while (argv[1][i])
		{
			while (!argv[1][i] || is_space(argv[1][i]))
				i--;
			end = i;
			if (i < 0)
				break;
			while (argv[1][i] && !is_space(argv[1][i]))
				i--;
			start = i + 1;
			if (pos)
				write (1, " ", 1);
			while (start <= end)
				write (1, &argv[1][start++], 1);
			pos = 1;
		}
	}
	write (1, "\n", 1);
}
