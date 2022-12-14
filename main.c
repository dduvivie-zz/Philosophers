/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:10:30 by dduvivie          #+#    #+#             */
/*   Updated: 2022/10/12 19:10:32 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* Create all threads. Return 0 if an error occurr.ed */
int	thread_created(pthread_t *threads, t_philo *philos, t_program *prg)
{
	int	i;
	int	num;

	i = 0;
	num = prg->args.num_of_philo;
	gettimeofday(&(prg->prg_start), NULL);
	while (i < num)
	{
		philos[i].prg_start = prg->prg_start;
		if (pthread_create(&(threads[i]), NULL, start, &(philos[i])))
			return (0);
		i++;
		usleep(100);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_program	prg;
	int			i;
	int			error;

	if (!get_args_in_int(argc - 1, argv, &(prg.args)))
		return (0);
	if (!init_structs(&prg))
		return (0);
	if (thread_created(prg.threads, prg.philos, &prg))
	{
		error = 0;
		i = -1;
		while (++i < prg.args.num_of_philo && !error)
		{
			if (pthread_join(prg.threads[i], NULL))
				error = 1;
		}
	}
	free_all_memory(&prg);
	system("leaks philo > .leaks_log.txt");
	return (0);
}
