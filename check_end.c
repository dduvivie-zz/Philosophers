/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:26:06 by dduvivie          #+#    #+#             */
/*   Updated: 2022/10/14 16:26:08 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
If the check_flag is 1, check both:
- if all philo ate the number of times they must eat
- if the philo died
If the check_flag is 0, check only if the philo died
*/
void	check_end(struct timeval *start, t_philo *philo, int *check_flag)
{
	int	i;
	int	philo_num;

	if (*check_flag == 0)
	{
		check_philo_life(start, philo);
		return ;
	}
	i = 0;
	philo_num = philo->end_flag->philo_num;
	pthread_mutex_lock(&(philo->end_flag->mutex));
	while (i < philo_num)
	{
		if (philo->end_flag->eat_counter[i] > 0)
		{
			pthread_mutex_unlock(&(philo->end_flag->mutex));
			check_philo_life(start, philo);
			return ;
		}
		i++;
	}
	philo->end_flag->finish = 1;
	pthread_mutex_unlock(&(philo->end_flag->mutex));
}

/* Lock the mutex and check if the end_flag is 1 or 0 */
int	check_end_flag(t_endflag *end_flag)
{
	int	end;

	end = 0;
	pthread_mutex_lock(&(end_flag->mutex));
	if (end_flag->finish == 1)
		end = 1;
	pthread_mutex_unlock(&(end_flag->mutex));
	return (end);
}
