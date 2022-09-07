#include "philosophers.h"

/*
	//pthread_mutex_t	fork1;
	//pthread_mutex_t	fork2;
	//pthread_mutex_init(&fork1, NULL);
	//pthread_mutex_init(&fork2, NULL);
*/

int	main(int argc, char *argv[])
{
	pthread_t		*thread_list;
	t_fork			*fork_list;
	t_philo			*philo_list;
	t_args			args;
	unsigned int	i;

	/* check argument and get it in int */
	get_args_in_int(argc - 1, argv, &args);
	if (args.error_flag == 1)
		return (0);

	/* init structure */
	thread_list = init_threads(&args);
	if (!thread_list)
		return (0);

	fork_list = init_forks(&args); //---------->
	if (!fork_list)
	{
		free(thread_list);
		return (0);
	}

	philo_list = init_philos(&args, fork_list);
	if (!philo_list)
	{
		free(thread_list);
		free(fork_list);
		return (0);
	}

	/* start threads */
	i = -1;
	while (++i < args.num_of_philo)
		pthread_create(&(thread_list[i]), NULL, philo_start, &(philo_list[i]));
	i = -1;
	while (++i < args.num_of_philo)
		pthread_join(thread_list[i], NULL);

	//pthread_mutex_destroy(&fork1);
	//pthread_mutex_destroy(&fork2);
	return (0);
}
