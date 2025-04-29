/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:52:21 by fpapadak          #+#    #+#             */
/*   Updated: 2025/04/29 12:54:06 by fpapadak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	cleanup_philos(t_table *table, int philos_init)
{
	int	i;

	if (table->philos)
	{
		i = -1;
		while (++i < philos_init)
			pthread_mutex_destroy(&table->philos[i].meal_mutex);
		free(table->philos);
		table->philos = NULL;
	}
}

void	cleanup_forks(t_table *table, int forks_init)
{
	int	i;

	if (table->forks)
	{
		i = -1;
		while (++i < forks_init)
			pthread_mutex_destroy(&table->forks[i]);
		free(table->forks);
		table->forks = NULL;
	}
}

void	cleanup_shared_mutexes(t_table *table)
{
	pthread_mutex_destroy(&table->print_mutex);
	pthread_mutex_destroy(&table->termination_mutex);
}

int	cleanup(t_table *table, int forks_init, int philos_init, int exit_code)
{
	cleanup_philos(table, philos_init);
	cleanup_forks(table, forks_init);
	cleanup_shared_mutexes(table);
	return (exit_code);
}
