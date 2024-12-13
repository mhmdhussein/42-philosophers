/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohhusse <mohhusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 21:19:05 by mohhusse          #+#    #+#             */
/*   Updated: 2024/11/15 21:19:05 by mohhusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

// Philo struct
typedef struct s_philo
{
	int					id;
	int					meals_eaten;
	int					left_fork;
	int					right_fork;
	long				last_meal_time;
	pthread_t			thread;
	struct s_table		*table;
}	t_philo;

// Table struct
typedef struct s_table
{
	int				philos_nb;
	long			start_time;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				meals_required;
	int				simulation_running;
	int				meal_flag;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
}	t_table;

// Check Args
void	check_args(int argc, char **argv);

// Init
void	init_numbers(t_table *table, int argc, char **argv);
void	init_table(t_table *table, t_philo *philos, pthread_mutex_t *forks);
void	init_philos(t_table *table);

// Simulation
void	start_simulation(t_table *table);
int		check_dead(t_table *table);

// Routine
void	*philo_routine(void *arg);

// Monitor
void	monitor_philos(t_table *table);

// Status
void	print_status(t_table *table, int id, char *message);

// Time
long	current_time(void);

// Error
void	error(int flag);

// Utils
int		ft_atoi(const char *nptr);
long	ft_atol(const char *nptr);

#endif
