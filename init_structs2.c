/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:10:59 by dduvivie          #+#    #+#             */
/*   Updated: 2022/10/12 19:11:00 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* Init the list of forks, and its mutex */
t_fork	*init_forks(t_args *args)
{
	int		i;
	int		error_flag;
	t_fork	*forks;

	i = 0;
	error_flag = 0;
	forks = (t_fork *)malloc(args->num_of_philo * sizeof(t_fork));
	if (!forks)
		return (NULL);
	while (i < args->num_of_philo && !error_flag)
	{
		if (pthread_mutex_init(&(forks[i].mutex), NULL) != 0)
			error_flag = 1;
		forks[i].used = 0;
		i++;
	}
	if (error_flag)
	{
		i--;
		if (i > 0)
			destroy_fork_mutex(forks, i);
		free(forks);
		return (NULL);
	}
	return (forks);
}

void	set_forks(t_philo *philo, int i, int last, t_fork *forks)
{
	if (last == 0)
	{
		philo->left_fork = &(forks[last]);
		philo->right_fork = NULL;
		return ;
	}
	if (i == 0)
		philo->left_fork = &(forks[last]);
	else
		philo->left_fork = &(forks[i - 1]);
	if (i == last)
		philo->right_fork = &(forks[last]);
	else
		philo->right_fork = &(forks[i]);
}

t_philo	*init_philos(t_args *args, t_fork *forks, t_endflag *end_flag)
{
	int		i;
	int		last;
	t_philo	*philos;

	i = 0;
	last = args->num_of_philo - 1;
	philos = (t_philo *)malloc(args->num_of_philo * sizeof(t_philo));
	if (!philos)
		return (NULL);
	while (i < args->num_of_philo)
	{
		philos[i].id = i + 1;
		philos[i].time_to_die = args->time_to_die;
		philos[i].time_to_eat = args->time_to_eat;
		philos[i].time_to_sleep = args->time_to_sleep;
		philos[i].num_of_times_eat = args->num_of_times_eat;
		philos[i].end_flag = end_flag;
		set_forks(&(philos[i]), i, last, forks);
		i++;
	}
	return (philos);
}
