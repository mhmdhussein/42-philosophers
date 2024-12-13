/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohhusse <mohhusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 21:18:42 by mohhusse          #+#    #+#             */
/*   Updated: 2024/11/15 21:18:42 by mohhusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	join_destroy(t_table *table)
{
	int		i;

	i = 0;
	while (i < table->philos_nb)
	{
		pthread_join(table->philos[i].thread, NULL);
		i++;
	}
	i = 0;
	while (i < table->philos_nb)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&table->print_lock);
	pthread_mutex_destroy(&table->dead_lock);
	pthread_mutex_destroy(&table->meal_lock);
}

int	main(int argc, char **argv)
{
	t_table			table;
	t_philo			philos[200];
	pthread_mutex_t	forks[200];

	check_args(argc, argv);
	init_numbers(&table, argc, argv);
	init_table(&table, philos, forks);
	init_philos(&table);
	start_simulation(&table);
	join_destroy(&table);
	return (0);
}
