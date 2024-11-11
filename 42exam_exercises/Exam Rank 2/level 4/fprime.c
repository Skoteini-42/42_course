
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	i;
	int	nb;

	if (argc == 2)
	{
		nb = atoi(argv[1]);
		if (nb == 1)
			printf("1");
		i = 1;
		while (i <= nb)
		{
			i++;
			if (nb % i == 0)
			{
				printf ("%d", i);
				if (nb == i)
					break;
				printf ("*");
				nb = nb / i;
				i = 1;
			}

		}
	}
	printf ("\n");
}

