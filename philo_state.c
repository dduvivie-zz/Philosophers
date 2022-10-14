/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:17:22 by dduvivie          #+#    #+#             */
/*   Updated: 2022/10/14 16:17:24 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* Print the action of philosopher */
void	print_message(long int time, t_philo *philo, char *msg)
{
	pthread_mutex_lock(&(philo->end_flag->mutex));
	if (philo->end_flag->finish == 0)
		printf("%10ld %u %s\n", time, philo->id, msg);
	pthread_mutex_unlock(&(philo->end_flag->mutex));
}

/* Decrement the number of times philosopher must eat */
void	count_eat(t_philo *philo)
{
	int	i;

	i = philo->id - 1;
	pthread_mutex_lock(&(philo->end_flag->mutex));
	if (philo->end_flag->eat_counter[i] > 0)
		philo->end_flag->eat_counter[i] -= 1;
	pthread_mutex_unlock(&(philo->end_flag->mutex));
}

/* Check if the philosopher is dead. If so, print the died message */
void	check_philo_life(struct timeval *start, t_philo *philo)
{
	struct timeval	now;
	long int		milliseconds;

	gettimeofday(&now, NULL);
	milliseconds = (((now.tv_sec - philo->philo_life.tv_sec) * 1000) \
					+ (now.tv_usec - philo->philo_life.tv_usec) / 1000);
	if ((long int)philo->time_to_die - milliseconds <= 0)
	{
		pthread_mutex_lock(&(philo->end_flag->mutex));
		if (philo->end_flag->finish == 0)
		{
			printf("%10ld %u died\n", get_time(start), philo->id);
			philo->end_flag->finish = 1;
		}
		pthread_mutex_unlock(&(philo->end_flag->mutex));
	}
}
