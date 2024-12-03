/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:39:23 by fpapadak          #+#    #+#             */
/*   Updated: 2024/12/02 10:58:21 by fpapadak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(int *array, size_t size)
{
	int		max;
	size_t	i;

	max = array[0];
	i = 1;
	while (i < size)
	{
		if (array[i] > max)
			max = array[i];
		i++;
	}
	return (max);
}

int	find_min_pos(t_stacks *stacks)
{
	int		min;
	int		pos;
	size_t	i;

	min = stacks->stack_a[0];
	pos = 0;
	i = 1;
	while (i < stacks->size_a)
	{
		if (stacks->stack_a[i] < min)
		{
			min = stacks->stack_a[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

int	is_sorted(t_stacks *stacks)
{
	size_t	i;

	i = 0;
	while (i < stacks->size_a - 1)
	{
		if (stacks->stack_a[i] > stacks->stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	assign_indices(int *stack, size_t size)
{
	int		*sorted_stack;
	size_t	i;
	size_t	j;

	sorted_stack = copy_stack(stack, size);
	if (!sorted_stack)
		return ;
	sort_stack_array(sorted_stack, size);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (stack[i] == sorted_stack[j])
			{
				stack[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	free(sorted_stack);
}
