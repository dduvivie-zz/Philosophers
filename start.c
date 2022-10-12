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
		{	
			if (philo->id % 2 == 0)
				even_philo_eat(start_time, philo);
			else
				odd_philo_eat(start_time, philo);
		}
		gettimeofday(&life_time, NULL);
		if (philo->end_flag->finish == 0)
			philo_sleep(start_time, philo);
	}
	return (NULL);
}

void	*start2(void *data)
{
	t_philo			*philo;
	struct timeval	start_time;


	philo = (t_philo *)data;
	//printf("My ID is %d.\ntime_to_eat = %d\ntime_to_die = %d\n", philo->id, philo->time_to_eat, philo->time_to_die);
	gettimeofday(&start_time, NULL);
	printf("START\n");
	usleep_ms(60);
	printf("%10lld\n", current_timestamp(start_time));
	usleep_ms(60);
	printf("%10lld\n", current_timestamp(start_time));
	usleep_ms(60);
	printf("%10lld\n", current_timestamp(start_time));
	usleep_ms(60);
	printf("%10lld\n", current_timestamp(start_time));
	//philo_think(start_time, philo);
	//philo_eat(start_time, philo);
	//philo_sleep(start_time, philo);
	return (NULL);
}
