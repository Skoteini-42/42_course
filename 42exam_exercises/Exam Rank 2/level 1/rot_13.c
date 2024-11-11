
#include <unistd.h>

void	convert(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((s[i] >= 'a' && s[i] <= 'm') || (s[i] >= 'A' && s[i] <= 'M'))
			s[i] = s[i] + 13;
		else if ((s[i] >= 'n' && s[i] <= 'z') || (s[i] >= 'N' && s[i] <= 'Z'))
			s[i] = s[i] - 13;
		write (1, &s[i], 1);
		i++;
	}	
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		convert(argv[1]);
	write (1, "\n",1 );
}
