#include "philo.h"

static void	take_forks_even(t_philo *philos)
{
	pthread_mutex_lock(philos->left_fork);
	print_status(philos, "has taken a fork");
	pthread_mutex_lock(philos->right_fork);
	print_status(philos, "has taken a fork");
}

static void	take_forks_odd(t_philo *philos)
{
	pthread_mutex_lock(philos->right_fork);
	print_status(philos, "has taken a fork");
	pthread_mutex_lock(philos->left_fork);
	print_status(philos, "has taken a fork");
}

void	take_forks(t_philo *philos)
{
	if (philos->id % 2 == 0)
		take_forks_even(philos);
	else
		take_forks_odd(philos);
}

void	release_forks(t_philo *philos)
{
	pthread_mutex_unlock(philos->left_fork);
	pthread_mutex_unlock(philos->right_fork);
	print_status(philos, "is sleeping");
}
