
#include <unistd.h>

int	is_space(char c)
{
	if (c == 32 || (c >= 9 && c<= 13))
		return (1);
	return (0);
}

void	capitalizer(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		if ((str[i] >= 'a' && str[i] <= 'z' && is_space(str[i - 1])) || (str[0] >= 'a' && str[0] >= 0))
			str[i] = str[i] - 32;
		write (1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			capitalizer(argv[i]);
			write (1, "\n", 1);
			i++;
		}
	}
	else
		write (1, "\n", 1);
}
