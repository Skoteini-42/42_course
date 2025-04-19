#include "philo.h"

long	get_current_time(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	print_status(t_philo *philos, char *msg)
{
	pthread_mutex_lock(&philos->table->print_mutex);
	if (!simulation_ended(philos->table))
	{
		printf("%ld %d %s\n", 
		get_current_time() - philos->table->start_time,
		philo->id, msg);
	}
	pthread_mutex_unlock(&philos->table->print_mutex);
}

void	print_death(t_philo *philos)
{
	pthread_mutex_lock(&philos->table->print_mutex);
	printf("%ld %d died\n", 
		get_current_time() - philos->table->start_time, philo->id);
	pthread_mutex_unlock(&philos->table->print_mutex);
}
