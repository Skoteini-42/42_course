#include "philo.h"

void	unlock_last_meal(t_philo *philos)
{
	pthread_mutex_unlock(&philos->meal_mutex);
}

void	set_termination_flag(t_table *table)
{
	pthread_mutex_lock(&table->termination_mutex);
	table->termination_flag = 1;
	pthread_mutex_unlock(&table->termination_mutex);
}
