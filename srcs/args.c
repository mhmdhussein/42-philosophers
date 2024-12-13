/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohhusse <mohhusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 22:25:57 by mohhusse          #+#    #+#             */
/*   Updated: 2024/11/15 22:25:57 by mohhusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	is_numerical(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((s[i] < 48 || s[i] > 57) && s[i] != 43 && s[i] != 45)
			return (0);
		i++;
	}
	return (1);
}

void	check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc != 5 && argc != 6)
		error(1);
	i = 1;
	while (i < argc)
	{
		if (!is_numerical(argv[i]))
			error(2);
		else if (ft_atoi(argv[i]) < 0)
			error(3);
		i++;
	}
	if (ft_atoi(argv[1]) > 200)
		error(4);
	else if (ft_atoi(argv[2]) < 60 || ft_atoi(argv[3]) < 60
		|| ft_atoi(argv[4]) < 60)
		error(5);
	if (argc == 6 && ft_atoi(argv[5]) == 0)
		exit(0);
}
