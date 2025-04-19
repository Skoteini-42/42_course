#include "philo.h"

static int	init_forks(t_table *table, int *forks_initialized)
{
	int	i;

	i = -1;
	while (++i < t->philo_count)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
			return (1);
		(*forks_initialized)++;
	}
	return (0);
}

static int	init_shared_mutexes(t_table *table, int forks_initialized)
{
	if (pthread_mutex_init(&table->print_mutex, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&table->termination_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&table->print_mutex);
		cleanup_forks(table, forks_initialized);
		return (1);
	}
	return (0);
}

static int	initialize_philos(t_table *table)
{
	int	i;
	int	philos_initialized;

	i = -1;
	philos_initialized = 0;
	while (++i < table->philo_count)
	{
		table->philos[i].id = i + 1;
		table->philos[i].left_fork = &table->forks[i];
		table->philos[i].right_fork = &table->forks[(i + 1) % table->philo_count];
		table->philos[i].table = table;
		table->philos[i].last_meal_time = 0;
		table->philos[i].eat_count = 0;
		if (pthread_mutex_init(&table->philos[i].meal_mutex, NULL) != 0)
			return (cleanup_philos(table, philos_initialized), 1);
		philos_initialized++;
	}
	return (0);
}

int	initialize_simulation(t_table *table)
{
	int	i;
	int	forks_initialized; 

	forks_initialized = 0;
	table->forks = malloc(sizeof(pthread_mutex_t) * table->philo_count);
	if (!table->forks || init_forks(table, &forks_initiliazed)) != 0
		return (cleanup(table, forks_initialized, 0, 1));
	if (init_shared_mutexes(table, forks_initialized) != 0)
		return (cleanup(table, forks_initialized, 0, 1));
	table->philos = malloc(sizeof(t_philo) * table->philo_count);
	if (!table->philos || initialize_philos(table) != 0)
		return (cleanup_shared_mutexes(table),
			cleanup(table, forks_initialized, table->philo_count, 1));
	return (0);
}
