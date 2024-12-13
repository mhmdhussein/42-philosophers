/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohhusse <mohhusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 00:06:17 by mohhusse          #+#    #+#             */
/*   Updated: 2024/11/17 00:06:17 by mohhusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_numbers(t_table *table, int argc, char **argv)
{
	table->philos_nb = ft_atoi(argv[1]);
	table->time_to_die = ft_atol(argv[2]);
	table->time_to_eat = ft_atol(argv[3]);
	table->time_to_sleep = ft_atol(argv[4]);
	table->simulation_running = 1;
	table->meal_flag = 0;
	table->start_time = current_time();
	if (argc == 6)
		table->meals_required = ft_atoi(argv[5]);
	else
		table->meals_required = -1;
}

void	init_table(t_table *table, t_philo *philos, pthread_mutex_t *forks)
{
	int		i;

	table->forks = forks;
	table->philos = philos;
	i = 0;
	while (i < table->philos_nb)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&table->print_lock, NULL);
	pthread_mutex_init(&table->dead_lock, NULL);
	pthread_mutex_init(&table->meal_lock, NULL);
}

void	init_philos(t_table *table)
{
	int			i;

	i = 0;
	while (i < table->philos_nb)
	{
		table->philos[i].id = i + 1;
		table->philos[i].meals_eaten = 0;
		table->philos[i].last_meal_time = current_time();
		table->philos[i].table = table;
		table->philos[i].left_fork = i;
		if (i == 0)
			table->philos[i].right_fork = table->philos_nb - 1;
		else
			table->philos[i].right_fork = i - 1;
		i++;
	}
}
