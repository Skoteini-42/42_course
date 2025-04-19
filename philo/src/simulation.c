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

void	*philosopher_routine(void *arg)
{
	t_philo	*philos;

	philos = (t_philo *)arg;
	while (get_current_time() < philos->table->start_time)
		usleep(100);
	while (1)
	{
		pthread_mutex_lock(&philos->table->termination_mutex);
		if (philos->table->termination_flag)
		{
			pthread_mutex_unlock(&philos->table->termination_mutex);
			break ;
		}
		pthread_mutex_unlock(&philos->table->termination_mutex);
		pthread_mutex_lock(&philos->table->print_mutex);
		printf("%ld %d is thinking\n",
			get_current_time() - philos->table->start_time, philos->id);
		pthread_mutex_unlock(&philos->table->print_mutex);
		usleep(1000);
	}
	return (NULL);
}

void	*monitor_routine(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
	// Temporary: Just wait 2 seconds and terminate
	usleep(2000000); // 2 seconds
	pthread_mutex_lock(&table->termination_mutex);
	table->termination_flag = 1;
	pthread_mutex_unlock(&table->termination_mutex);
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
