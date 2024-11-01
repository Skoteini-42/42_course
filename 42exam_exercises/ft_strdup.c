
#include <stdlib.h>

char    *ft_strdup(char *src)
{
	int	i;
	size_t	len;
	char	*des;
	
	len = 0;
	if (!src)
		return (NULL);
	while (src[len])
		len++;
	des = (char *)malloc(sizeof(char) * len + 1);
	if (!des)
		return (NULL);
	i = 0;
	while (src[i])
	{
		des[i] = src[i];
		i++;
	}
	des[i] = '\0';
	return (des);
}
/*
#include <stdio.h>

int	main()
{
	char *src = "Hullo there";
	char *des;
	
	des = ft_strdup(src);
	printf("%s", des);
}*/
