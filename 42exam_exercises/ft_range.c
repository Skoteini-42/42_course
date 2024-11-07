
#include <stdlib.h>

int	length(int start, int end)
{
	if (end - start < 0)
		return ((end - start) * (-1));
	return (end - start);
}

int     *ft_range(int start, int end)
{
	int	*res;
	int	i;
	int	len;

	i = 0;
	len = length(start, end);
	res = (int *)malloc(sizeof(int) * ((len) + 1));
	while (i < len + 1)
	{
		if (start < end)
			res[i] = start++;
		else
			res[i] = start--;
		i++;
	}
	return (res);
}
