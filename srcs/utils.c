/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohhusse <mohhusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 22:50:48 by mohhusse          #+#    #+#             */
/*   Updated: 2024/11/16 22:50:48 by mohhusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	i;
	int	result;

	sign = 1;
	i = 0;
	result = 0;
	while (*(nptr + i) == ' ' || *(nptr + i) == '\f' || *(nptr + i) == '\n'
		|| *(nptr + i) == '\r' || *(nptr + i) == '\t' || *(nptr + i) == '\v')
	{
		i++;
	}
	if (*(nptr + i) == '-' || *(nptr + i) == '+')
	{
		if (*(nptr + i) == '-')
			sign *= -1;
		i++;
	}
	while (*(nptr + i) && *(nptr + i) >= '0' && *(nptr + i) <= '9')
	{
		result = result * 10;
		result = result + (*(nptr + i) - '0');
		i++;
	}
	return (sign * result);
}

long	ft_atol(const char *nptr)
{
	long	sign;
	int		i;
	long	result;

	sign = 1;
	i = 0;
	result = 0;
	while (*(nptr + i) == ' ' || *(nptr + i) == '\f' || *(nptr + i) == '\n'
		|| *(nptr + i) == '\r' || *(nptr + i) == '\t' || *(nptr + i) == '\v')
	{
		i++;
	}
	if (*(nptr + i) == '-' || *(nptr + i) == '+')
	{
		if (*(nptr + i) == '-')
			sign *= -1;
		i++;
	}
	while (*(nptr + i) && *(nptr + i) >= '0' && *(nptr + i) <= '9')
	{
		result = result * 10;
		result = result + (*(nptr + i) - '0');
		i++;
	}
	return (sign * result);
}
