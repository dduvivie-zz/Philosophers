#include "philosophers.h"

/* Execute usleep() with the millisecond parameter */
void	usleep_ms(unsigned int time)
{
	struct timeval	start;
	struct timeval	end;
	long int		milli_seconds;

	gettimeofday(&start, NULL);
	gettimeofday(&end, NULL);
	milli_seconds = (((end.tv_sec - start.tv_sec) * 1000) \
					+ (end.tv_usec - start.tv_usec) / 1000);
	while (milli_seconds + 100 < time)
	{
		usleep(100);
		gettimeofday(&end, NULL);
		milli_seconds = (((end.tv_sec - start.tv_sec) * 1000) \
					+ (end.tv_usec - start.tv_usec) / 1000);
	}
}

/* Get the current time in millisecond */
long long	current_timestamp(struct timeval start)
{
	struct timeval	te;
	long long		milliseconds;

	gettimeofday(&te, NULL);
	milliseconds = (((te.tv_sec - start.tv_sec) * 1000) \
					+ (te.tv_usec - start.tv_usec) / 1000);
	return (milliseconds);
}

/* Check if the philosopher still have time to be alive */
void	time_check(struct timeval start, t_philo *philo)
{
	struct timeval	end;
	long int		microseconds;

	gettimeofday(&end, NULL);
	microseconds = (((end.tv_sec - start.tv_sec) * 1000) \
					+ ((end.tv_usec - start.tv_usec) / 1000));
	if (microseconds >= philo->time_to_die)
	{
		pthread_mutex_lock(&(philo->end_flag->mutex));
		philo->end_flag->finish = 1;
		pthread_mutex_unlock(&(philo->end_flag->mutex));
		philo_die(start, philo);
	}
}
