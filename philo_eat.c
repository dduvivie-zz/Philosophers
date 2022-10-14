/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:27:20 by dduvivie          #+#    #+#             */
/*   Updated: 2022/10/14 16:27:21 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* Get the two forks and mutex_lock these */
void	get_forks(struct timeval *start, t_philo *philo)
{
	pthread_mutex_lock(&(philo->left_fork->mutex));
	print_message(get_time(start), philo, "has taken a fork");
	pthread_mutex_lock(&(philo->right_fork->mutex));
	print_message(get_time(start), philo, "has taken a fork");
}

/* Unlock the mutex of two forks */
void	put_down_forks(struct timeval *start, t_philo *philo)
{
	pthread_mutex_unlock(&(philo->left_fork->mutex));
	pthread_mutex_unlock(&(philo->right_fork->mutex));
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
