
#include <unistd.h>

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
	int	first_word_printed;

	first_word_printed = 0;
	if (argc > 1)
	{
		i = 0;
		while (argv[1][i] && is_space(argv[1][i]))
			i++;
		start = i;
		end = i;
		while (argv[1][i] && !is_space(argv[1][i]))
		{
			i++;
			end++;
		}
		while (argv[1][i])
		{
			while (argv[1][i] && is_space(argv[1][i]))
				i++;
			if (!argv[1][i])
				break;
			if (argv[1][i] && first_word_printed)
				write (1, " ", 1);
			while (!is_space(argv[1][i]) && argv[1][i])
			{
				write(1, &argv[1][i], 1);
				i++;
			}
			first_word_printed = 1;
		}
		if (first_word_printed)
			write (1, " ", 1);
		while (argv[1][start] && start < end)
		{
			write (1, &argv[1][start], 1);
			start++;
		}

	}
	write (1, "\n", 1);
}
