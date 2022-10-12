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

/* The philosopher with odd number takes the left fork first. */
void	odd_philo_eat(struct timeval start, t_philo *philo)
{
	pthread_mutex_lock(&(philo->left_fork->mutex));
	time_check(start, philo);
	if (check_end_flag(philo->end_flag) == 0)
	{
		printf("%10ld %u has taken a fork\n", get_time(start), philo->id);
		pthread_mutex_lock(&(philo->right_fork->mutex));
		time_check(start, philo);
		if (check_end_flag(philo->end_flag) == 0)
		{
			printf("%10ld %u has taken a fork\n", get_time(start), philo->id);
			printf("%10ld %u is eating\n", get_time(start), philo->id);
			usleep_ms(philo->time_to_eat);
		}
		pthread_mutex_unlock(&(philo->right_fork->mutex));
	}
	pthread_mutex_unlock(&(philo->left_fork->mutex));
}

/* The philosopher with even number takes the right fork first. */
void	even_philo_eat(struct timeval start, t_philo *philo)
{
	pthread_mutex_lock(&(philo->right_fork->mutex));
	time_check(start, philo);
	if (check_end_flag(philo->end_flag) == 0)
	{
		printf("%10ld %u has taken a fork\n", get_time(start), philo->id);
		pthread_mutex_lock(&(philo->left_fork->mutex));
		time_check(start, philo);
		if (check_end_flag(philo->end_flag) == 0)
		{
			printf("%10ld %u has taken a fork\n", get_time(start), philo->id);
			printf("%10ld %u is eating\n", get_time(start), philo->id);
			usleep_ms(philo->time_to_eat);
		}
		pthread_mutex_unlock(&(philo->left_fork->mutex));
	}
	pthread_mutex_unlock(&(philo->right_fork->mutex));
}

void	philo_die(struct timeval start, t_philo *philo)
{
	long int	current_time;

	current_time = get_time(start);
	printf("%10ld %u died\n", current_time, philo->id);
}
