#include "philosophers.h"

void	philo_sleep(struct timeval start, t_philo *philo)
{
	long long	current_time;

	current_time = current_timestamp(start);
	printf("%10lld %u is sleeping\n", current_time, philo->id);
	usleep_ms(philo->time_to_sleep);
}

void	philo_think(struct timeval start, t_philo *philo)
{
	long long	current_time;

	current_time = current_timestamp(start);
	printf("%10lld %u is thinking\n", current_time, philo->id);
}

void	philo_eat(struct timeval start, t_philo *philo)
{
	if (philo->id % 2 == 1)
	{
		pthread_mutex_lock(&(philo->left_fork->mutex));
		printf("%10lld %u has taken a left fork\n", current_timestamp(start), philo->id);
		pthread_mutex_lock(&(philo->right_fork->mutex));
		printf("%10lld %u has taken a right fork\n", current_timestamp(start), philo->id);
		printf("%10lld %u is eating\n", current_timestamp(start), philo->id);
		usleep_ms(philo->time_to_eat);
		pthread_mutex_unlock(&(philo->left_fork->mutex));
		pthread_mutex_unlock(&(philo->right_fork->mutex));
	}
	else
	{
		pthread_mutex_lock(&(philo->right_fork->mutex));
		printf("%10lld %u has taken a right fork\n", current_timestamp(start), philo->id);
		pthread_mutex_lock(&(philo->left_fork->mutex));
		printf("%10lld %u has taken a left fork\n", current_timestamp(start), philo->id);
		printf("%10lld %u is eating\n", current_timestamp(start), philo->id);
		usleep_ms(philo->time_to_eat);
		pthread_mutex_unlock(&(philo->right_fork->mutex));
		pthread_mutex_unlock(&(philo->left_fork->mutex));
	}
}

void	philo_die(struct timeval start, t_philo *philo)
{
	long long	current_time;

	current_time = current_timestamp(start);
	printf("%10lld %u died\n", current_time, philo->id);
}
