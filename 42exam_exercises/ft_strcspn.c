
#include <stddef.h>

size_t  ft_strcspn(const char *s, const char *reject)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (reject[j])
		{
			if (s[i] == reject[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}
/*
#include <stdio.h>
#include <string.h>

int	main()
{
	char *s = "Hullo there";
	char *d = "uuu";

	printf ("%zu\n", ft_strcspn(s, d));
	printf ("%zu\n", strcspn(s, d));
}*/
