#include "philosophers.h"

void	print_message(long int time, t_philo *philo, char *msg)
{
	pthread_mutex_lock(&(philo->end_flag->mutex));
	if (philo->end_flag->finish == 0)
		printf("%10ld %u %s\n", time, philo->id, msg);
	pthread_mutex_unlock(&(philo->end_flag->mutex));
}

void	count_eat(t_philo *philo)
{
	int	i;

	i = philo->id - 1;
	pthread_mutex_lock(&(philo->end_flag->mutex));
	if (philo->end_flag->eat_counter[i] > 0)
		philo->end_flag->eat_counter[i] -= 1;
	pthread_mutex_unlock(&(philo->end_flag->mutex));
}

void	check_end(struct timeval *start, t_philo *philo, int *check_flag)
{
	int	i;
	int	philo_num;

	if (*check_flag == 0)
	{
		time_check(start, philo);
		return ;
	}
	i = 0;
	philo_num = philo->end_flag->philo_num;
	pthread_mutex_lock(&(philo->end_flag->mutex));
	while (i < philo_num)
	{
		if (philo->end_flag->eat_counter[i] > 0)
		{
			pthread_mutex_unlock(&(philo->end_flag->mutex));
			time_check(start, philo);
			return ;
		}
		i++;
	}
	philo->end_flag->finish = 1;
	pthread_mutex_unlock(&(philo->end_flag->mutex));
}

int	check_end_flag(t_endflag *end_flag)
{
	int	end;

	end = 0;
	pthread_mutex_lock(&(end_flag->mutex));
	if (end_flag->finish == 1)
		end = 1;
	pthread_mutex_unlock(&(end_flag->mutex));
	return (end);
}

/* Check if the philosopher still have time to be alive */
void	time_check(struct timeval *start, t_philo *philo)
{
	struct timeval	now;
	long int		milliseconds;

	gettimeofday(&now, NULL);
	milliseconds = (((now.tv_sec - philo->philo_life.tv_sec) * 1000) \
					+ (now.tv_usec - philo->philo_life.tv_usec) / 1000);
	if ((long int)philo->time_to_die - milliseconds <= 0)
	{
		pthread_mutex_lock(&(philo->end_flag->mutex));
		if (philo->end_flag->finish == 0)
		{
			printf("%10ld %u died\n", get_time(start), philo->id);
			philo->end_flag->finish = 1;
		}
		pthread_mutex_unlock(&(philo->end_flag->mutex));
	}
}
