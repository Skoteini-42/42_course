/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:41:23 by fpapadak          #+#    #+#             */
/*   Updated: 2024/12/02 11:04:05 by fpapadak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stacks *stacks)
{
	if (stacks->size_a > 1 && stacks->stack_a[0] != stacks->stack_a[1])
	{
		ft_printf("ra\n");
		rotate(stacks->stack_a, stacks->size_a);
	}
}

void	rb(t_stacks *stacks)
{
	if (stacks->size_b > 1)
	{
		ft_printf("rb\n");
		rotate(stacks->stack_b, stacks->size_b);
	}
}

void	rr(t_stacks *stacks)
{
	if (stacks->size_a > 1 || stacks->size_b > 1)
	{
		ft_printf("rr\n");
		rotate(stacks->stack_a, stacks->size_a);
		rotate(stacks->stack_b, stacks->size_b);
	}
}

void	rotate(int *stack, size_t size)
{
	int		tmp;
	size_t	i;

	if (size < 2)
		return ;
	tmp = stack[0];
	i = 0;
	while (i < size - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[size - 1] = tmp;
}
