/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:52:34 by fpapadak          #+#    #+#             */
/*   Updated: 2025/04/29 12:52:35 by fpapadak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_philo_death(t_philo *philos)
{
	long	time_since_meal;
	int		died;

	died = 0;
	pthread_mutex_lock(&philos->meal_mutex);
	time_since_meal = get_current_time() - philos->last_meal_time;
	if (time_since_meal >= philos->table->time_to_die)
	{
		pthread_mutex_lock(&philos->table->termination_mutex);
		if (!philos->table->termination_flag)
		{
			print_death(philos);
			philos->table->termination_flag = 1;
			died = 1;
		}
		pthread_mutex_unlock(&philos->table->termination_mutex);
	}
	pthread_mutex_unlock(&philos->meal_mutex);
	return (died);
}

int	check_all_philos_full(t_table *table)
{
	int	i;
	int	full_count;

	if (table->must_eat_count == -1)
		return (0);
	full_count = 0;
	i = -1;
	while (++i < table->philo_count)
	{
		pthread_mutex_lock(&table->philos[i].meal_mutex);
		if (table->philos[i].eat_count >= table->must_eat_count)
			full_count++;
		pthread_mutex_unlock(&table->philos[i].meal_mutex);
	}
	return (full_count == table->philo_count);
}

void	handle_all_full(t_table *table)
{
	pthread_mutex_lock(&table->termination_mutex);
	if (!table->termination_flag)
	{
		pthread_mutex_lock(&table->print_mutex);
		printf("%ld All philosophers have eaten %d times\n",
			get_current_time() - table->start_time, table->must_eat_count);
		pthread_mutex_unlock(&table->print_mutex);
		table->termination_flag = 1;
	}
	pthread_mutex_unlock(&table->termination_mutex);
}
