#include "philo.h"

void	think(t_philo *philos)
{
	print_status(philos, "is thinking");
}

void	eat(t_philo *philos)
{
	print_status(philos, "is eating");
	pthread_mutex_lock(&philos->meal_mutex);
	philos->last_meal_time = get_current_time();
	philos->eat_count++;
	pthread_mutex_unlock(&philos->meal_mutex);
	usleep(philos->table->time_to_eat * 1000);
}

void	philo_sleep(t_philo *philos)
{
	print_status(philos, "is sleeping");
	usleep(philos->table->time_to_sleep * 1000);
}
