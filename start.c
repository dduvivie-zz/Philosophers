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

/* The philosopher has only one fork, so he will die before eating */
void	philo_alone(struct timeval *start, t_philo *philo)
{
	printf("%10ld %u has taken a fork\n", get_time(start), philo->id);
	usleep_ms(philo->time_to_die);
	printf("%10ld %u died\n", get_time(start), philo->id);
}

void	eat_till_die(struct timeval *start, t_philo *philo)
{
	int	check_flag;

	check_flag = 0;
	while (!check_end_flag(philo->end_flag))
	{
		philo_think(start, philo, &check_flag);
		check_end(start, philo, &check_flag);
		philo_eat(start, philo, &check_flag);
		check_end(start, philo, &check_flag);
		philo_sleep(start, philo, &check_flag);
		check_end(start, philo, &check_flag);
	}
	return ;
}

void	eat_n_times(struct timeval *start, t_philo *philo)
{
	int	check_flag;

	check_flag = 1;
	while (!check_end_flag(philo->end_flag))
	{
		philo_think(start, philo, &check_flag);
		check_end(start, philo, &check_flag);
		philo_eat(start, philo, &check_flag);
		check_end(start, philo, &check_flag);
		philo_sleep(start, philo, &check_flag);
		check_end(start, philo, &check_flag);
	}
	return ;
}

void	*start(void *data)
{
	t_philo			*philo;

	philo = (t_philo *)data;
	gettimeofday(&(philo->philo_life), NULL);
	if (philo->end_flag->philo_num == 1)
	{
		philo_alone(&(philo->prg_start), philo);
		return (NULL);
	}
	if (philo->num_of_times_eat == -1)
		eat_till_die(&(philo->prg_start), philo);
	else
		eat_n_times(&(philo->prg_start), philo);
	return (NULL);
}
