
#include <stdlib.h>

int	length(int start, int end)
{
	if (end - start < 0)
		return ((end -start) * (-1));
	return (end - start);
}

int     *ft_rrange(int start, int end)
{
	int	*res;
	int	len;
	int	i;

	i = 0;
	len = length(start, end);
	res = (int *)malloc(sizeof(int) * (len + 1));
	if (!res)
		return (NULL);
	while (i < len + 1)
	{
		if (start < end)
			res[i] = end--;
		else
			res[i] = start--;
		i++;
	}
	return (res);
}
