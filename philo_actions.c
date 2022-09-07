#include "philosophers.h"

/* Execute usleep() in millisecond */
void	usleep_ms(unsigned int time)
{
	usleep(time * 1000);
}

/* Get the current time in millisecond */
long long	current_timestamp(void)
{
	struct timeval	te;
	long long		milliseconds;

	gettimeofday(&te, NULL);
	milliseconds = te.tv_sec * 1000LL + te.tv_usec / 1000;
	return (milliseconds);
}

void	philo_sleep(t_philo *philo)
{
	long long	current_time;

	current_time = current_timestamp();
	printf("%lld %u is sleeping\n", current_time, philo->id);
	usleep_ms(philo->time_to_sleep);
}

void	philo_think(t_philo *philo)
{
	long long	current_time;

	current_time = current_timestamp();
	printf("%lld %u is thinking\n", current_time, philo->id);
	usleep_ms(philo->time_to_think);
}

//void	philo_eat(t_philo *philo)
//{
//	/* need two fork to execute eat() */
//	// get_right fork()
//	// get_left_fork()
//	// eat
//}
