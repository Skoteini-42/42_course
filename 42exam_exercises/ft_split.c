
#include <stdlib.h>

int	is_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	count_words(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while(str[i])
	{
		while (is_space(str[i]))
			i++;
		if (str[i])
			count++;
		while (str[i] && !is_space(str[i]))
			i++;
	}
	return (count);
}

char	*extract_word(char *str)
{
	char *word;
	int	i;
	int	len;

	len = 0;
	while (str[len] && !is_space(str[len]))
		len++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char **ft_split(char *str)
{
	char	**res;
	int	word_count;
	int	i;

	word_count = count_words(str);
	res = (char **)malloc(sizeof(char *) *(word_count + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		while (*str && is_space(*str))
			str++;
		res[i] = extract_word(str);
		if (!res[i])
			return (NULL);
		while (*str && !is_space(*str))
			str++;
		i++;
	}
	res[i] = '\0';
	return (res);
}
