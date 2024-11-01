
#include <unistd.h>
#include <stdlib.h>

int	is_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;
	int	start;
	int	end;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i])
			i++;
		i--;
		while (i >= 0)
		{
			while (i >= 0 && is_space(argv[1][i]))
				i--;
			end = i + 1;
			while (i >= 0 && !is_space(argv[1][i]))
				i--;
			start = i + 1;
			while (start < end)
			{
				write (1, &argv[1][start], 1);
				start++;
			}
			if (i >= 0)
				write (1, " ", 1);
		}
	}
	write (1, "\n",1 );
}
