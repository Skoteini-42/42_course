/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:52:40 by fpapadak          #+#    #+#             */
/*   Updated: 2025/04/29 14:59:57 by fpapadak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void take_forks(t_philo *philos)
{
    if (philos->id % 2 == 0)
        take_forks_even(philos);
    else
        take_forks_odd(philos);
}

/*void take_forks(t_philo *philos)
{
    if (philos->id == philos->table->philo_count)
        take_forks_odd(philos);
    if (philos->id % 2 == 0)
        take_forks_even(philos);
    else
        take_forks_odd(philos);
    pthread_mutex_lock(&philos->meal_mutex);
    philos->last_meal_time = get_current_time();
    pthread_mutex_unlock(&philos->meal_mutex);
}*/

void	release_forks(t_philo *philos)
{
	pthread_mutex_unlock(philos->left_fork);
	pthread_mutex_unlock(philos->right_fork);
}
