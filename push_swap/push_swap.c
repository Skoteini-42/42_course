/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:38:04 by fpapadak          #+#    #+#             */
/*   Updated: 2024/12/03 09:58:00 by fpapadak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
	{
		ft_printf("Error\n");
		exit (1);
	}
	ft_memset(stacks, 0, sizeof(t_stacks));
	check_args(argc, argv, stacks);
	if (!is_sorted(stacks))
		sort_stack(stacks);
	free_stacks("", stacks);
	return (0);
}
