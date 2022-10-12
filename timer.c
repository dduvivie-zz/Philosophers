#include "philosophers.h"

/* Execute usleep() with the millisecond parameter */
void	usleep_ms(unsigned int time)
{
	struct timeval	start;
	struct timeval	end;
	double			start_microsecond;
	double			end_microsecond;
	double			total_microseconds;	

	time = time * 1000;
	gettimeofday(&start, NULL);
	gettimeofday(&end, NULL);
	start_microsecond = (start.tv_sec * 1000000) + (start.tv_usec);
	end_microsecond = (end.tv_sec * 1000000) + (end.tv_usec);
	total_microseconds = end_microsecond - start_microsecond;
	while (total_microseconds < time)
	{
		usleep(100);
		gettimeofday(&end, NULL);
		end_microsecond = (end.tv_sec * 1000000) + (end.tv_usec);
		total_microseconds = end_microsecond - start_microsecond;
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
	double			start_microsecond;
	double			end_microsecond;
	int				total_microseconds;	

	gettimeofday(&end, NULL);
	start_microsecond = (start.tv_sec * 1000000) + (start.tv_usec);
	end_microsecond = (end.tv_sec * 1000000) + (end.tv_usec);
	total_microseconds = (int)end_microsecond - (int)start_microsecond;
	if (total_microseconds >= philo->time_to_die)
	{
		pthread_mutex_lock(&(philo->end_flag->mutex));
		philo->end_flag->finish = 1;
		pthread_mutex_unlock(&(philo->end_flag->mutex));
		philo_die(start, philo);
	}
}
