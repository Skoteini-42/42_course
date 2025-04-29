/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:53:06 by fpapadak          #+#    #+#             */
/*   Updated: 2025/04/29 15:06:46 by fpapadak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	wait_for_simulation_start(t_table *table)
{
	while (get_current_time() < table->start_time)
		usleep(100);
}

void	print_status(t_philo *philos, char *msg)
{
	pthread_mutex_lock(&philos->table->print_mutex);
	if (!simulation_ended(philos->table))
	{
		printf("%ld %d %s\n",
			get_current_time() - philos->table->start_time,
			philos->id, msg);
	}
	pthread_mutex_unlock(&philos->table->print_mutex);
}

void	print_death(t_philo *philos)
{
	pthread_mutex_lock(&philos->table->print_mutex);
	printf("%ld %d died\n",
		get_current_time() - philos->table->start_time, philos->id);
	pthread_mutex_unlock(&philos->table->print_mutex);
}

void	set_termination_flag(t_table *table)
{
	pthread_mutex_lock(&table->termination_mutex);
	table->termination_flag = 1;
	pthread_mutex_unlock(&table->termination_mutex);
}
