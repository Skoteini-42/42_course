
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
			if (i < 0) 
				break;
			end = i;
			while (i >= 0 && !is_space(argv[1][i]))
				i--;
			start = i + 1;
			if (first_word_printed)
				write (1, " ", 1);
			write (1, &argv[1][start], end -start + 1);
			first_word_printed = 1;				
		}
	}
	write (1, "\n", 1);
}
