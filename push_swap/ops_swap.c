/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:40:55 by fpapadak          #+#    #+#             */
/*   Updated: 2024/12/02 11:01:24 by fpapadak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stacks *stacks)
{
	ft_printf("sa\n");
	swap(stacks->stack_a, stacks->size_a);
}

void	sb(t_stacks *stacks)
{
	ft_printf("sb\n");
	swap(stacks->stack_b, stacks->size_b);
}

void	ss(t_stacks *stacks)
{
	ft_printf("ss\n");
	swap(stacks->stack_a, stacks->size_a);
	swap(stacks->stack_b, stacks->size_b);
}

void	swap(int *stack, int size)
{
	int	tmp;

	if (size < 2)
		return ;
	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
}
