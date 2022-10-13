/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:11:13 by dduvivie          #+#    #+#             */
/*   Updated: 2022/10/12 19:11:15 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* The philosopher has only one fork, so he will die before eating */
void	philo_alone(struct timeval start, t_philo *philo)
{
	pthread_mutex_lock(&(philo->left_fork->mutex));
	printf("%10ld %u has taken a fork\n", get_time(start), philo->id);
	pthread_mutex_unlock(&(philo->left_fork->mutex));
	usleep_ms(philo->time_to_die);
	philo_die(start, philo);
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

//void	philo_eat(struct timeval start, t_philo *philo);
//{
//
//}
