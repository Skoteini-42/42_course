/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:38:32 by fpapadak          #+#    #+#             */
/*   Updated: 2024/12/02 11:12:05 by fpapadak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_arr(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	count_tokens(const char *str)
{
	int		num_tokens;
	char	**tokens;

	num_tokens = 0;
	tokens = ft_split(str, ' ');
	if (!tokens)
		return (0);
	while (tokens[num_tokens])
		num_tokens++;
	free_arr(tokens);
	return (num_tokens);
}

int	count_args(int argc, char **argv)
{
	char	*str;
	size_t	num_tokens;

	str = cat_args(argc, argv);
	num_tokens = count_tokens(str);
	free(str);
	return (num_tokens);
}
