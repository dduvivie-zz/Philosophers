#include "philosophers.h"

void	*philo_start(void *data)
{
	t_philo		*philo;

	philo = (t_philo *)data;
	printf("left fork of %d is %d and right fork is %d.\n", philo->id, philo->left_fork->used, philo->right_fork->used);

	// timer count start

	// try to take fork

	// eat
	//printf("Time to eat is: %ums.\n", philo->time_to_eat);
	// reset timer

	// put back fork

	// sleep
	//printf("Time to sleep is: %ums.\n", philo->time_to_sleep);

	// think
	//printf("Time to think is: %ums.\n", philo->time_to_think);


	//printf("Num of times to eat is: %d.\n", philo->num_of_times_eat);
	//philo_sleep(philo);
	return (NULL);
}
