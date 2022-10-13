/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:11:57 by dduvivie          #+#    #+#             */
/*   Updated: 2022/10/12 19:11:58 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* Execute usleep() with the millisecond parameter */
void	usleep_ms(unsigned int time)
{
	struct timeval	start;
	struct timeval	end;
	double			start_microsecond;
	double			end_microsecond;
	double			total_microseconds;

	time = (double)(time * 1000);
	gettimeofday(&start, NULL);
	gettimeofday(&end, NULL);
	start_microsecond = (start.tv_sec * 1000000) + (start.tv_usec);
	end_microsecond = (end.tv_sec * 1000000) + (end.tv_usec);
	total_microseconds = end_microsecond - start_microsecond;
	while (total_microseconds < time)
	{
		usleep(100);
		gettimeofday(&end, NULL);
		end_microsecond = (end.tv_sec * 1000000) + (end.tv_usec);
		total_microseconds = end_microsecond - start_microsecond;
	}
}

/* Get the current time in millisecond */
long int	get_time(struct timeval start)
{
	struct timeval	te;
	long int		milliseconds;

	gettimeofday(&te, NULL);
	milliseconds = (((te.tv_sec - start.tv_sec) * 1000) \
					+ (te.tv_usec - start.tv_usec) / 1000);
	return (milliseconds);
}

/* Check if the philosopher still have time to be alive */
void	time_check(struct timeval start, t_philo *philo)
{
	struct timeval	now;
	long int		milliseconds;

	gettimeofday(&now, NULL);
	milliseconds = (((now.tv_sec - philo->philo_life.tv_sec) * 1000) \
					+ (now.tv_usec - philo->philo_life.tv_usec) / 1000);
	//printf("----PHILO %d's time is %ld\n", philo->id, milliseconds);
	if (milliseconds >= philo->time_to_die)
	{
		pthread_mutex_lock(&(philo->end_flag->mutex));
		philo->end_flag->finish = 1;
		pthread_mutex_unlock(&(philo->end_flag->mutex));

		philo_die(start, philo);
	}
}
