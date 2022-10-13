/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:10:38 by dduvivie          #+#    #+#             */
/*   Updated: 2022/10/12 19:10:40 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_end(t_philo *philo)
{
	int i;
	int philo_num;

	i = 0;
	philo_num = philo->end_flag->philo_num;
	if (philo->num_of_times_eat != -1)
	{
		pthread_mutex_lock(&(philo->end_flag->mutex));
		while (i < philo_num)
		{
			if (philo->end_flag->eat_counter[i] > 0)
				return (0);
			i++;
		}
		pthread_mutex_unlock(&(philo->end_flag->mutex));
	}
	return (1);
}

int	check_end_flag(t_endflag *end_flag)
{
	int	end;

	end = 0;
	pthread_mutex_lock(&(end_flag->mutex));
	// print message
	if (end_flag->finish)
		end = 1;
	pthread_mutex_unlock(&(end_flag->mutex));
	return (end);
}

void	*start(void *data)
{
	t_philo			*philo;
	struct timeval	start_time;

	philo = (t_philo *)data;
	gettimeofday(&start_time, NULL);
	gettimeofday(&(philo->philo_life), NULL);
	if (philo->end_flag->philo_num == 1)
	{
		philo_alone(start_time, philo);
		return (NULL);
	}
	while (check_end_flag(philo->end_flag) == 0)
	{
		time_check(start_time, philo);
		if (check_end_flag(philo->end_flag) == 0)
			philo_think(start_time, philo);
		if (check_end_flag(philo->end_flag) == 0)
			time_check(start_time, philo);
		if (check_end_flag(philo->end_flag) == 0)
		{
			//philo_eat(start_time, philo);
			if (philo->id % 2 == 0)
				even_philo_eat(start_time, philo);
			else
				odd_philo_eat(start_time, philo);
			gettimeofday(&(philo->philo_life), NULL);
		}
		if (check_end_flag(philo->end_flag) == 0)
			philo_sleep(start_time, philo);
	}
	return (NULL);
}

void	*start2(void *data)
{
	t_philo			*philo;
	struct timeval	start_time;
	//struct timeval	life_time;

	philo = (t_philo *)data;
	gettimeofday(&start_time, NULL);
	//gettimeofday(&life_time, NULL);
	//printf("My ID is %d.\ntime_to_eat = %d\ntime_to_die = %d\n", philo->id, philo->time_to_eat, philo->time_to_die);
	usleep_ms(60);
	printf("%ld\n", get_time(start_time));
	usleep_ms(60);
	printf("%ld\n", get_time(start_time));
	usleep_ms(60);
	printf("%ld\n", get_time(start_time));
	usleep_ms(60);
	printf("%ld\n", get_time(start_time));
	//philo_think(start_time, philo);
	//philo_eat(start_time, philo);
	//philo_sleep(start_time, philo);
	//time_check(life_time, philo);
	return (NULL);
}

void	*eat_till_die(void *data)
{
	t_philo			*philo;

	philo = (t_philo *)data;
	printf("test thread\n");
	return (NULL);
}

void	*eat_n_times(void *data)
{
	t_philo			*philo;

	philo = (t_philo *)data;
	printf("test2 thread\n");
	return (NULL);
}
