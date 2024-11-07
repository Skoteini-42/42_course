
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	a;
	int	b;

	if (argc == 3)
	{
		a = atoi(argv[1]);
		b = atoi(argv[2]);
		if (a > 0 && b > 0)
		{
			while (a != b)
			{
				if (a > b)
					a = a - b;
				else
					b = b - a;
			}
		}
		printf ("%d", a);
	}
	printf("\n");
}
