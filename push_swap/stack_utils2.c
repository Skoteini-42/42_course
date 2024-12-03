/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:39:36 by fpapadak          #+#    #+#             */
/*   Updated: 2024/12/03 10:32:07 by fpapadak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stacks(const char *error_msg, t_stacks *s)
{
	if (s)
	{
		if (s->stack_a)
			free(s->stack_a);
		if (s->stack_b)
			free(s->stack_b);
		free(s);
	}
	if (ft_strlen(error_msg) > 0)
		ft_printf("%s", error_msg);
	exit(error_msg[0] != '\0');
}

void	stacks_init(t_stacks *s, int *stack_a, size_t size)
{
	size_t	i;

	i = 0;
	s->size_a = 0;
	if (stack_a)
		s->size_a = size;
	s->size_b = 0;
	s->stack_a = (int *)malloc(sizeof(int) * size);
	s->stack_b = (int *)malloc(sizeof(int) * size);
	if (!s->stack_a || !s->stack_b)
		free_stacks("Error\n", s);
	if (stack_a)
	{
		while (i < size)
		{
			s->stack_a[i] = stack_a[i];
			i++;
		}
		free(stack_a);
	}
}

void	check_args(int argc, char **argv, t_stacks *stacks)
{
	int		*stack_a;
	size_t	stack_size_a;

	stack_a = check_valid_args(argc, argv, stacks);
	stack_size_a = count_args(argc, argv);
	stacks_init(stacks, stack_a, stack_size_a);
}

int	*copy_stack(int *stack, size_t size)
{
	int		*sorted_stack;
	size_t	i;

	sorted_stack = malloc(sizeof(int) * size);
	if (!sorted_stack)
		return (NULL);
	i = 0;
	while (i < size)
	{
		sorted_stack[i] = stack[i];
		i++;
	}
	return (sorted_stack);
}

void	sort_stack_array(int *array, size_t size)
{
	size_t	i;
	size_t	j;
	int		tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
