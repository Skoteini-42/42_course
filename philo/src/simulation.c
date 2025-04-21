#include "philo.h"

int	start_simulation(t_table *table)
{
	int				i;
	pthread_t	monitor;

	table->start_time = get_current_time() + 100;
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
	pthread_mutex_lock(philos->left_fork);
	print_status(philos, "has taken a fork");
	usleep(philos->table->time_to_die * 1000);
	print_status(philos, "died");
	return (NULL);
}

void	*philosopher_routine(void *arg)
{
	t_philo	*philos;

	philos = (t_philo *)arg;
	wait_for_simulation_start(philos->table);
	if (philos->table->philo_count == 1)
		return (handle_single_philosopher(philos));
	while (!simulation_ended(philos->table))
	{
		think(philos);
		take_forks(philos);
		eat(philos);
		release_forks(philos);
		sleep_and_think(philos);
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
				return (set_termination_flag(table), NULL);
		}
		if (check_all_philos_full(table))
			return (set_termination_flag(table), NULL);
		usleep(1000);
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
