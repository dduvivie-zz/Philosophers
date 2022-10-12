#include "philosophers.h"

/* Destroy all mutex of t_fork structure */
void	destroy_fork_mutex(t_fork *forks, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		pthread_mutex_destroy(&(forks[i].mutex));
		i++;
	}
}

/* Destroy the mutex of t_endflag structure */
void	destroy_endflag_mutex(t_endflag *end_flag)
{
	pthread_mutex_destroy(&(end_flag->mutex));
}

/*
Depends on the second parameter "num",
free all allocated memory and destroy all mutex.
*/
int	error_exit(t_program *prg, int num)
{
	if (num == 0)
		free(prg->threads);
	else if (num == 1)
	{
		free(prg->threads);
		destroy_fork_mutex(prg->forks, prg->args.num_of_philo);
		free(prg->forks);
	}
	else if (num == 2)
	{
		free(prg->threads);
		destroy_fork_mutex(prg->forks, prg->args.num_of_philo);
		free(prg->forks);
		free(prg->end_flag.eat_counter);
		destroy_endflag_mutex(&(prg->end_flag));
	}
	return (0);
}

void	free_all_memory(t_program *prg)
{
	int	num;

	num = prg->args.num_of_philo;
	free(prg->threads);
	destroy_fork_mutex(prg->forks, num);
	free(prg->forks);
	free(prg->end_flag.eat_counter);
	destroy_endflag_mutex(&(prg->end_flag));
	free(prg->philos);
}
