/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:38:49 by fpapadak          #+#    #+#             */
/*   Updated: 2024/12/02 11:06:24 by fpapadak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*cat_args(int argc, char **argv)
{
	char	*concat_str;
	char	*arg_spaced;
	char	*tmp;
	int		i;

	concat_str = NULL;
	i = 1;
	while (i < argc)
	{
		arg_spaced = ft_strjoin(argv[i], "  ");
		if (!arg_spaced)
			return (free(concat_str), NULL);
		if (!concat_str)
			concat_str = arg_spaced;
		else
		{
			tmp = concat_str;
			concat_str = ft_strjoin(concat_str, arg_spaced);
			free(tmp);
			free(arg_spaced);
		}
		i++;
	}
	return (concat_str);
}

static int	*str_to_array(const char *str, size_t num_tokens)
{
	char	**tokens;
	size_t	i;
	int		*array;

	tokens = ft_split(str, ' ');
	i = 0;
	if (!tokens)
		return (NULL);
	array = (int *)malloc(sizeof(int) * num_tokens);
	if (!array)
		return (free_arr(tokens), NULL);
	while (i < num_tokens)
	{
		array[i] = ft_atoi(tokens[i]);
		i++;
	}
	free_arr(tokens);
	return (array);
}

static int	check_duplicates(const int *array, size_t length)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!array || length <= 0)
		return (1);
	while (i < length - 1)
	{
		j = i + 1;
		while (j < length)
		{
			if (array[i] == array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static char	*check_valid_int(int argc, char **argv, t_stacks *stacks)
{
	char	*str;

	if (argc < 2)
		return (free_stacks("", stacks), NULL);
	str = cat_args(argc, argv);
	if (!str)
		return (free_stacks("Error\n", stacks), NULL);
	if (!is_int_str(str))
		return (free_stacks("Error\n", stacks), NULL);
	return (str);
}

int	*check_valid_args(int argc, char **argv, t_stacks *stacks)
{
	char	*str;
	size_t	num_tokens;
	int		*array;

	str = check_valid_int(argc, argv, stacks);
	num_tokens = count_tokens(str);
	array = str_to_array(str, num_tokens);
	free(str);
	if (!str)
		free_stacks("Error\n", stacks);
	if (!array || check_duplicates(array, num_tokens))
	{
		free(array);
		free_stacks("Error\n", stacks);
	}
	return (array);
}
