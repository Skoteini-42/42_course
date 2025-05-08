/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:53:01 by fpapadak          #+#    #+#             */
/*   Updated: 2025/05/08 11:55:47 by fpapadak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_simulation(t_table *table)
{
	int			i;
	pthread_t	monitor;

	i = -1;
	while (++i < table->philo_count)
	{
		if (pthread_create(&table->philos[i].thread_id, NULL,
				philosopher_routine, &table->philos[i]) != 0)
			return (1);
	}
	if (pthread_create(&monitor, NULL, monitor_routine, table) != 0)
		return (1);
	pthread_join(monitor, NULL);
	i = -1;
	while (++i < table->philo_count)
		pthread_join(table->philos[i].thread_id, NULL);
	return (0);
}

static void	*handle_single_philosopher(t_philo *philos)
{
	wait_for_simulation_start(philos->table);
	pthread_mutex_lock(philos->left_fork);
	print_status(philos, "has taken a fork");
	pthread_mutex_lock(&philos->meal_mutex);
	philos->last_meal_time = get_current_time();
	pthread_mutex_unlock(&philos->meal_mutex);
	while (!simulation_ended(philos->table))
		usleep(100);
	pthread_mutex_unlock(philos->left_fork);
	return (NULL);
}

void	*philosopher_routine(void *arg)
{
	t_philo	*philos;

	philos = (t_philo *)arg;
	wait_for_simulation_start(philos->table);
	if (philos->table->philo_count == 1)
		return (handle_single_philosopher(philos));
	pthread_mutex_lock(&philos->meal_mutex);
	philos->last_meal_time = get_current_time();
	pthread_mutex_unlock(&philos->meal_mutex);
	while (!simulation_ended(philos->table))
	{
		think(philos);
		take_forks(philos);
		eat(philos);
		release_forks(philos);
		philo_sleep(philos);
	}
	return (NULL);
}

void	*monitor_routine(void *arg)
{
	t_table	*table;
	int		i;

	table = (t_table *)arg;
	while (!simulation_ended(table))
	{
		i = -1;
		while (++i < table->philo_count)
		{
			if (check_philo_death(&table->philos[i]))
				return (NULL);
		}
		if (table->must_eat_count != -1 && check_all_philos_full(table))
		{
			set_termination_flag(table);
			pthread_mutex_lock(&table->print_mutex);
			printf("%ld All philosophers have eaten %d times\n",
				get_current_time() - table->start_time, table->must_eat_count);
			pthread_mutex_unlock(&table->print_mutex);
			return (NULL);
		}
		precise_usleep(1, table);
	}
	return (NULL);
}

int	simulation_ended(t_table *table)
{
	int	ended;

	pthread_mutex_lock(&table->termination_mutex);
	ended = table->termination_flag;
	pthread_mutex_unlock(&table->termination_mutex);
	return (ended);
}
