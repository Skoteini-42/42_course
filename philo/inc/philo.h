#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <string.h>
# include <limits.h>
# include <sys/time.h>

# define PHILO_ERR "Need ≥1 philosopher"
# define TIME_DIE_ERR "time_to_die must be ≥1ms"
# define TIME_EAT_ERR "time_to_eat must be ≥1ms"
# define TIME_SLEEP_ERR "time_to_sleep must be ≥1ms"
# define EAT_COUNT_ERR "must_eat_count must be ≥1"

typedef struct s_philo
{
	int				id;
	pthread_t		thread_id;
	int				eat_count;
	long			last_meal_time;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_table 	*table;
}	t_philo;

typedef struct s_table
{
	t_philo			*philos;
	long			start_time;
	int				termination_flag;
	int				philo_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_count;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	termination_mutex;
}	t_table;

/******** Argument Utilities ********/
int		ft_atoi(const char *nptr);
int		is_valid_number(char *str);

/******** Simulation ********/
int		initialize_simulation(t_table *table);
int		start_simulation(t_table *table);
void	*philosopher_routine(void *arg);
void	*monitor_routine(void *arg);
int		simulation_ended(t_table *table);

/******** Simulation Utils ********/
long	get_current_time(void);
void	print_status(t_philo *philos, char *msg);
void	print_death(t_philo *philos);

/******** Fork management ********/
void	take_forks(t_philo *philos);
void	release_forks(t_philo *philos);

/******** Cleanup ********/
void	cleanup_philos(t_table *table, int philos_init);
void	cleanup_forks(t_table *table, int forks_init);
void	cleanup_shared_mutexes(t_table *table);
int		cleanup(t_table *table, int forks_init, int philos_init, int exit_code);

#endif