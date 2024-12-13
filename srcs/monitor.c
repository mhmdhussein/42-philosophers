/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohhusse <mohhusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:34:53 by mohhusse          #+#    #+#             */
/*   Updated: 2024/12/13 11:13:34 by mohhusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	monitor_meals(t_table *table)
{
	int		i;
	int		meals_eaten;

	if (table->meals_required == -1)
		return (0);
	i = -1;
	meals_eaten = 0;
	while (++i < table->philos_nb)
	{
		pthread_mutex_lock(&table->meal_lock);
		if (table->philos[i].meals_eaten != table->meals_required)
		{
			pthread_mutex_unlock(&table->meal_lock);
			break ;
		}
		pthread_mutex_unlock(&table->meal_lock);
	}
	if (i == table->philos_nb)
	{
		pthread_mutex_lock(&table->dead_lock);
		table->simulation_running = 0;
		pthread_mutex_unlock(&table->dead_lock);
		return (1);
	}
	return (0);
}

int	check_philo_dead(t_table *table, int i)
{
	pthread_mutex_lock(&table->meal_lock);
	if (current_time() - table->philos[i].last_meal_time >= table->time_to_die)
	{
		pthread_mutex_unlock(&table->meal_lock);
		return (1);
	}
	pthread_mutex_unlock(&table->meal_lock);
	return (0);
}

int	monitor_dead(t_table *table)
{
	int		i;

	i = 0;
	while (i < table->philos_nb)
	{
		if (check_philo_dead(table, i))
		{
			print_status(table, i + 1, "died");
			pthread_mutex_lock(&table->dead_lock);
			table->simulation_running = 0;
			pthread_mutex_unlock(&table->dead_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

void	monitor_philos(t_table *table)
{
	while (1)
	{
		if (monitor_dead(table) || monitor_meals(table))
			break ;
	}
}
