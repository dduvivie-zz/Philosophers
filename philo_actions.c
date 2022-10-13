/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:11:13 by dduvivie          #+#    #+#             */
/*   Updated: 2022/10/12 19:11:15 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_sleep(struct timeval start, t_philo *philo)
{
	long int	current_time;

	current_time = get_time(start);
	printf("%10ld %u is sleeping\n", current_time, philo->id);
	usleep_ms(philo->time_to_sleep);
}

void	philo_think(struct timeval start, t_philo *philo)
{
	long int	current_time;

	current_time = get_time(start);
	printf("%10ld %u is thinking\n", current_time, philo->id);
}

void	philo_die(struct timeval start, t_philo *philo)
{
	long int	current_time;

	current_time = get_time(start);
	printf("%10ld %u died\n", current_time, philo->id);
}
