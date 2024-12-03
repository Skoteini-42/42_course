/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:15:51 by fpapadak          #+#    #+#             */
/*   Updated: 2024/12/03 10:31:24 by fpapadak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stddef.h>
# include <stdint.h>
# include "libft/libft.h"

typedef struct t_stacks
{
	size_t	size_a;
	size_t	size_b;
	int		*stack_a;
	int		*stack_b;
}	t_stacks;

int			main(int argc, char **argv);
size_t		is_valid(char *str);
int			*check_valid_args(int argc, char **argv, t_stacks *stacks);
void		check_args(int argc, char **argv, t_stacks *stacks);
char		*cat_args(int argc, char **argv);
int			count_tokens(const char *str);
int			is_int_str(const char *str);
void		free_stacks(const char *error_msg, t_stacks *s);
void		free_arr(char **str);
int			count_args(int argc, char **argv);
void		check_args(int argc, char **argv, t_stacks *stacks);
void		sa(t_stacks *stacks);
void		sb(t_stacks *stacks);
void		swap(int *stack, int size);
void		ss(t_stacks *stacks);
void		pa(t_stacks *stacks);
void		pb(t_stacks *stacks);
void		ra(t_stacks *stacks);
void		rb(t_stacks *stacks);
void		rr(t_stacks *stacks);
void		rotate(int *stack, size_t size);
void		rra(t_stacks *stacks);
void		rrb(t_stacks *stacks);
void		rrr(t_stacks *stacks);
void		rrotate(int *stack, int size);
int			is_sorted(t_stacks *stacks);
int			find_max(int *array, size_t size);
int			find_min_pos(t_stacks *stacks);
void		sort_stack(t_stacks *stacks);
void		sort_two(t_stacks *stacks);
void		sort_three(t_stacks *stacks);
void		sort_four(t_stacks *stacks);
void		sort_five(t_stacks *stacks);
int			check_bit(int n, int bit_pos);
void		radix_check(t_stacks *stacks, int bit_pos);
void		radix_sort(t_stacks *stacks);
void		assign_indices(int *stack, size_t size);
int			*copy_stack(int *stack, size_t size);
void		sort_stack_array(int *array, size_t size);

#endif
