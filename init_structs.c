#include "philosophers.h"

pthread_t	*init_threads(t_args *args)
{
	pthread_t	*thread_list;

	thread_list = (pthread_t *)malloc(args->num_of_philo * sizeof(pthread_t));
	if (!thread_list)
		return (NULL);
	return (thread_list);
}

pthread_mutex_t	init_mutex(void)
{
	pthread_mutex_t	mutex;

	pthread_mutex_init(&mutex, NULL);
	return (mutex);
}

t_fork	*init_forks(t_args *args)
{
	unsigned int	i;
	t_fork			*fork_list;

	i = 0;
	fork_list = (t_fork *)malloc(args->num_of_philo * sizeof(t_fork));
	if (!fork_list)
		return (NULL);
	while (i < args->num_of_philo)
	{
		fork_list[i].mutex = init_mutex();
		fork_list[i].used = i + 1;
		i++;
	}
	return (fork_list);
}

void	set_forks(t_philo *philo, int i, int last, t_fork *fork_list)
{
	if (i == 0)
		philo->left_fork = &(fork_list[last]);
	else
		philo->left_fork = &(fork_list[i - 1]);
	if (i == last)
		philo->right_fork = &(fork_list[last]);
	else
		philo->right_fork = &(fork_list[i]);
}

t_philo	*init_philos(t_args *args, t_fork *fork_list)
{
	unsigned int	i;
	unsigned int	last;
	t_philo			*philo_list;

	i = 0;
	last = args->num_of_philo - 1;
	philo_list = (t_philo *)malloc(args->num_of_philo * sizeof(t_philo));
	if (!philo_list)
		return (NULL);
	while (i < args->num_of_philo)
	{
		philo_list[i].id = i + 1;
		philo_list[i].time_to_eat = args->time_to_eat;
		philo_list[i].time_to_sleep = args->time_to_sleep;
		philo_list[i].time_to_think = args->time_to_think;
		philo_list[i].num_of_times_eat = args->num_of_times_eat;
		set_forks(&(philo_list[i]), (int)i, (int)last, fork_list);
		i++;
	}
	return (philo_list);
}
