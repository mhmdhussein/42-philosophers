/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohhusse <mohhusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:07:27 by mohhusse          #+#    #+#             */
/*   Updated: 2024/12/10 15:07:27 by mohhusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_dead(t_table *table)
{
	pthread_mutex_lock(&table->dead_lock);
	if (!table->simulation_running)
	{
		pthread_mutex_unlock(&table->dead_lock);
		return (1);
	}
	pthread_mutex_unlock(&table->dead_lock);
	return (0);
}

void	print_status(t_table *table, int id, char *message)
{
	pthread_mutex_lock(&table->print_lock);
	if (!check_dead(table))
		printf("%ld %d %s\n", current_time() - table->start_time, id, message);
	pthread_mutex_unlock(&table->print_lock);
}

void	start_simulation(t_table *table)
{
	int			i;

	i = 0;
	while (i < table->philos_nb)
	{
		pthread_create(&table->philos[i].thread, NULL, philo_routine,
			&table->philos[i]);
		i++;
	}
	monitor_philos(table);
}
