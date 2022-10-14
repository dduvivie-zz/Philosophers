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

void	philo_sleep(struct timeval *start, t_philo *philo, int *check_flag)
{
	check_end(start, philo, check_flag);
	if (check_end_flag(philo->end_flag) == 0)
	{
		if (philo->time_to_sleep > philo->time_to_die)
		{
			usleep_ms(philo->time_to_sleep);
			check_end(start, philo, check_flag);
		}
		else
		{
			check_end(start, philo, check_flag);
			if (check_end_flag(philo->end_flag) == 0)
				print_message(get_time(start), philo, "is sleeping");
			usleep_ms(philo->time_to_sleep);
		}
	}
	else
		return ;
}

void	philo_think(struct timeval *start, t_philo *philo, int *f, int *c)
{
	check_end(start, philo, c);
	if ((check_end_flag(philo->end_flag) == 0) && *f == 0)
	{
		printf("%10ld %u is thinking\n", get_time(start), philo->id);
		*f = 1;
	}
}

void	philo_eat(struct timeval *start, t_philo *philo, int *check_flag)
{
	check_end(start, philo, check_flag);
	if (check_end_flag(philo->end_flag) == 0)
	{
		gettimeofday(&(philo->philo_life), NULL);
		if (philo->time_to_eat > philo->time_to_die)
		{
			usleep_ms(philo->time_to_die);
			check_end(start, philo, check_flag);
		}
		else
		{
			check_end(start, philo, check_flag);
			print_message(get_time(start), philo, "is eating");
			if (*check_flag)
				count_eat(philo);
			usleep_ms(philo->time_to_eat);
			put_down_forks(philo);
		}
	}
	else
		return ;
}
