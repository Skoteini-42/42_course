/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_numsets.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:40:33 by fpapadak          #+#    #+#             */
/*   Updated: 2024/12/02 10:59:27 by fpapadak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stacks *stacks)
{
	if (stacks->size_a == 2)
		sort_two(stacks);
	else if (stacks->size_a == 3)
		sort_three(stacks);
	else if (stacks->size_a == 4)
		sort_four(stacks);
	else if (stacks->size_a == 5)
		sort_five(stacks);
	else
	{
		assign_indices(stacks->stack_a, stacks->size_a);
		radix_sort(stacks);
	}
}

void	sort_two(t_stacks *stacks)
{
	if (stacks->stack_a[0] > stacks->stack_a[1])
		sa(stacks);
}

void	sort_three(t_stacks *stacks)
{
	int	*a;

	a = stacks->stack_a;
	if (a[0] < a[1] && a[1] < a[2])
		return ;
	if (a[0] > a[1] && a[1] < a[2] && a[0] < a[2])
		sa(stacks);
	else if (a[0] > a[1] && a[1] > a[2])
	{
		sa(stacks);
		rra(stacks);
	}
	else if (a[0] > a[1] && a[1] < a[2] && a[0] > a[2])
		ra(stacks);
	else if (a[0] < a[1] && a[1] > a[2] && a[0] < a[2])
	{
		sa(stacks);
		ra(stacks);
	}
	else if (a[0] < a[1] && a[1] > a[2] && a[0] > a[2])
		rra(stacks);
}

void	sort_four(t_stacks *stacks)
{
	int	pos;

	pos = find_min_pos(stacks);
	if (pos == 1)
		ra(stacks);
	else if (pos == 2)
	{
		ra(stacks);
		ra(stacks);
	}
	else if (pos == 3)
		rra(stacks);
	if (is_sorted(stacks))
		return ;
	pb(stacks);
	sort_three(stacks);
	pa(stacks);
}

void	sort_five(t_stacks *stacks)
{
	int	pos;
	int	i;

	i = 0;
	while (i < 2)
	{
		pos = find_min_pos(stacks);
		while (pos > 0)
		{
			ra(stacks);
			pos--;
		}
		pb(stacks);
		i++;
	}
	sort_three(stacks);
	pa(stacks);
	pa(stacks);
}
