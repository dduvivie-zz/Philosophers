/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:10:13 by dduvivie          #+#    #+#             */
/*   Updated: 2022/10/12 19:10:19 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* Init the list of threads. */
pthread_t	*init_threads(t_args *args)
{
	pthread_t	*threads;

	threads = (pthread_t *)malloc(args->num_of_philo * sizeof(pthread_t));
	if (!threads)
		return (NULL);
	return (threads);
}

/* Init the end_flag variables and its mutex */
int	init_endflag(t_args *args, t_endflag *end_flag)
{
	int	i;

	i = 0;
	end_flag->finish = 0;
	end_flag->philo_num = args->num_of_philo;
	end_flag->eat_counter = (int *)malloc(args->num_of_philo * sizeof(int));
	if (!end_flag->eat_counter)
		return (0);
	while (i < args->num_of_philo)
	{
		end_flag->eat_counter[i] = args->num_of_times_eat;
		i++;
	}
	if (pthread_mutex_init(&(end_flag->mutex), NULL) != 0)
	{
		free(end_flag->eat_counter);
		return (0);
	}
	return (1);
}

/*
Init all structures (t_thread, t_forks, t_endflag, t_philo)
If it encount an error during malloc or init_mutex, call error_exit function.
*/
int	init_structs(t_program *prg)
{
	prg->threads = init_threads(&(prg->args));
	if (!prg->threads)
		return (0);
	prg->forks = init_forks(&(prg->args));
	if (!prg->forks)
		return (error_exit(prg, 0));
	if (!init_endflag(&(prg->args), &(prg->end_flag)))
		return (error_exit(prg, 1));
	prg->philos = init_philos(&(prg->args), prg->forks, &(prg->end_flag));
	if (!prg->philos)
		return (error_exit(prg, 2));
	return (1);
}
