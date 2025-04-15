#include "philo.h"

void	*monitor_routine(void *arg)
{
	t_table	*table;
	int		i;

	table = (t_table *)arg;
	while (1)
	{
		i = -1;
		while (++i < table->philo_count)
		{
			if (philo_died(&table->philos[i]))
			{
				print_death(&table->philos[i]);
				set_termination_flag(table);
				return (NULL);
			}
		}
		if (all_philos_full(table))
		{
			set_termination_flag(table);
			return (NULL);
		}
		usleep(1000);
	}
}

void	*philosopher_routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while (get_current_time() < philo->table->start_time)
		usleep(100);
	while (1)
	{
		if (simulation_ended(philo->table))
			break;
		if (philo->id % 2 == 0)
			take_forks_even(philo);
		else
			take_forks_odd(philo);
		update_last_meal(philo);
		usleep(philo->table->time_to_eat * 1000);
		release_forks(philo);
		usleep(philo->table->time_to_sleep * 1000);
	}
	return (NULL);
}

int	start_simulation(t_table *table)
{
	int		i;
	t_philo	*philo;

	table->start_time = get_current_time() + 100;
	i = -1;
	while (++i < table->philo_count)
	{
		philo = &table->philos[i];
		if (pthread_create(&philo->thread_id, NULL,
			philosopher_routine, philo) != 0)
			return (error("Thread creation failed"));
	}
	if (pthread_create(&table->monitor_id, NULL,
		monitor_routine, table) != 0)
		return (error("Monitor thread failed"));
	return (0);
}

int	simulation_ended(t_table *table)
{
	pthread_mutex_lock(&table->termination_mutex);
	if (table->termination_flag)
	{
		pthread_mutex_unlock(&table->termination_mutex);
		return (1);
	}
	pthread_mutex_unlock(&table->termination_mutex);
	return (0);
}
