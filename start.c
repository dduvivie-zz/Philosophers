#include "philosophers.h"

void	*start(void *data)
{
	t_philo			*philo;
	struct timeval	start_time;
	struct timeval	life_time;

	philo = (t_philo *)data;
	gettimeofday(&start_time, NULL);
	gettimeofday(&life_time, NULL);
	while (philo->end_flag->finish == 0)
	{
		time_check(life_time, philo);
		if (philo->end_flag->finish == 0)
			philo_think(start_time, philo);
		if (philo->end_flag->finish == 0)
			time_check(life_time, philo);
		if (philo->end_flag->finish == 0)
			philo_eat(start_time, philo);
		gettimeofday(&life_time, NULL);
		if (philo->end_flag->finish == 0)
			philo_sleep(start_time, philo);
	}
	return (NULL);
}

void	*start2(void *data)
{
	t_philo			*philo;

	philo = (t_philo *)data;
	printf("My ID is %d.\n", philo->id);
	return (NULL);
}
