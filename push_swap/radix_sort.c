/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:39:51 by fpapadak          #+#    #+#             */
/*   Updated: 2024/12/02 11:00:13 by fpapadak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_bit(int n, int bit_pos)
{
	int	bit;

	bit = (n >> bit_pos) & 1;
	return (bit);
}

void	radix_check(t_stacks *stacks, int bit_pos)
{
	size_t	count;
	size_t	size;

	count = 0;
	size = stacks->size_a;
	while (count < size)
	{
		if (check_bit(stacks->stack_a[0], bit_pos) == 1)
			ra(stacks);
		else
			pb(stacks);
		count++;
	}
	while (stacks->size_b > 0)
		pa(stacks);
}

void	radix_sort(t_stacks *stacks)
{
	int	max_nb;
	int	bit_pos;

	if (is_sorted(stacks))
		return ;
	max_nb = find_max(stacks->stack_a, stacks->size_a);
	bit_pos = 0;
	while ((max_nb >> bit_pos) != 0)
	{
		radix_check(stacks, bit_pos);
		bit_pos++;
	}
}
