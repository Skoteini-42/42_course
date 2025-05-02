/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:52:04 by fpapadak          #+#    #+#             */
/*   Updated: 2025/04/29 13:02:21 by fpapadak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	parse_positive_int(char *arg, int *dest, char *err)
{
	int	val;

	val = ft_atoi(arg);
	if (val < 1)
		return (printf("Error: %s\n", err), 1);
	*dest = val;
	return (0);
}

static int	parse_args(t_table *table, int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (!is_valid_number(argv[i]))
			return (printf("Error: Invalid argument '%s'\n", argv[i]), 1);
	}
	if (parse_positive_int(argv[1], &table->philo_count, PHILO_ERR))
		return (1);
	if (parse_positive_int(argv[2], &table->time_to_die, TIME_DIE_ERR))
		return (1);
	if (parse_positive_int(argv[3], &table->time_to_eat, TIME_EAT_ERR))
		return (1);
	if (parse_positive_int(argv[4], &table->time_to_sleep, TIME_SLEEP_ERR))
		return (1);
	table->must_eat_count = -1;
	if (argc == 6)
	{
		if (parse_positive_int(argv[5], &table->must_eat_count, EAT_COUNT_ERR))
			return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc != 5 && argc != 6)
		return (printf("Error : Invalid number of arguments\n"), 1);
	memset(&table, 0, sizeof(t_table));
	if (parse_args(&table, argc, argv) != 0)
		return (1);
	if (initialize_simulation(&table) != 0)
		return (cleanup(&table, table.forks_initialized,
			table.philos_initialized, 1));
	if (start_simulation(&table) != 0)
		return (cleanup(&table, table.forks_initialized, table.philos_initialized, 1));
	return (cleanup(&table, table.forks_initialized, table.philos_initialized, 0));
}
