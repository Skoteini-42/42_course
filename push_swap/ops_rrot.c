/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rrot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:41:31 by fpapadak          #+#    #+#             */
/*   Updated: 2024/12/02 11:02:27 by fpapadak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stacks *stacks)
{
	ft_printf("rra\n");
	rrotate(stacks->stack_a, stacks->size_a);
}

void	rrb(t_stacks *stacks)
{
	ft_printf("rrb\n");
	rrotate(stacks->stack_b, stacks->size_b);
}

void	rrr(t_stacks *stacks)
{
	ft_printf("rrr\n");
	rrotate(stacks->stack_a, stacks->size_a);
	rrotate(stacks->stack_b, stacks->size_b);
}

void	rrotate(int *stack, int size)
{
	int		tmp;
	size_t	i;

	if (size < 2)
		return ;
	i = size - 1;
	tmp = stack[size - 1];
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = tmp;
}
