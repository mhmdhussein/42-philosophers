/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohhusse <mohhusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:42:32 by mohhusse          #+#    #+#             */
/*   Updated: 2024/11/16 18:42:32 by mohhusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	error(int flag)
{
	printf("\033[31mError!\033[0m\n");
	if (flag == 1)
		printf("The number of argument should be either 4 or 5.\n");
	else if (flag == 2)
		printf("The arguments must be numerical\n");
	else if (flag == 3)
		printf("The arguments must be positive.\n");
	else if (flag == 4)
		printf("The number of philosophers should not exceed 200.\n");
	else if (flag == 5)
		printf("Time to die, eat or sleep should not be lower than 60ms.\n");
	else if (flag == 6)
		printf("Initialization error.\n");
	exit(1);
}
