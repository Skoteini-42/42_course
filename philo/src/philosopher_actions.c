/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_actions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:52:54 by fpapadak          #+#    #+#             */
/*   Updated: 2025/04/29 12:52:56 by fpapadak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think(t_philo *philos)
{
	print_status(philos, "is thinking");
	if (philos->id % 2 == 1)
		usleep(1000);
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
