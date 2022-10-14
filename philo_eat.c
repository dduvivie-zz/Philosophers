#include "philosophers.h"

int	get_first_fork(struct timeval *start, t_philo *philo)
{
	if (philo->id == philo->end_flag->philo_num)
	{
		if (get_right_fork(start, philo))
			return (1);
		else
			return (0);
	}
	else
	{
		if (get_left_fork(start, philo))
			return (1);
		else
			return (0);
	}
}

int	get_second_fork(struct timeval *start, t_philo *philo)
{
	if (philo->id == philo->end_flag->philo_num)
	{
		if (get_left_fork(start, philo))
			return (1);
		else
			return (0);
	}
	else
	{
		if (get_right_fork(start, philo))
			return (1);
		else
			return (0);
	}
}

int	get_left_fork(struct timeval *start, t_philo *philo)
{
	pthread_mutex_lock(&(philo->left_fork->mutex));
	if (philo->left_fork->used)
	{
		pthread_mutex_unlock(&(philo->left_fork->mutex));
		return (0);
	}
	philo->left_fork->used = 1;
	print_message(get_time(start), philo, "has taken a fork");
	pthread_mutex_unlock(&(philo->left_fork->mutex));
	return (1);
}

int	get_right_fork(struct timeval *start, t_philo *philo)
{
	pthread_mutex_lock(&(philo->right_fork->mutex));
	if (philo->right_fork->used)
	{
		pthread_mutex_unlock(&(philo->right_fork->mutex));
		return (0);
	}
	philo->right_fork->used = 1;
	print_message(get_time(start), philo, "has taken a fork");
	pthread_mutex_unlock(&(philo->right_fork->mutex));
	return (1);
}

void	put_down_forks(t_philo *philo)
{
	if (philo->id == philo->end_flag->philo_num)
	{
		pthread_mutex_lock(&(philo->right_fork->mutex));
		philo->right_fork->used = 0;
		pthread_mutex_unlock(&(philo->right_fork->mutex));
		pthread_mutex_lock(&(philo->left_fork->mutex));
		philo->left_fork->used = 0;
		pthread_mutex_unlock(&(philo->left_fork->mutex));
	}
	else
	{
		pthread_mutex_lock(&(philo->left_fork->mutex));
		philo->left_fork->used = 0;
		pthread_mutex_unlock(&(philo->left_fork->mutex));
		pthread_mutex_lock(&(philo->right_fork->mutex));
		philo->right_fork->used = 0;
		pthread_mutex_unlock(&(philo->right_fork->mutex));
	}
}

/*		pthread_mutex_lock(&(philo->right_fork->mutex));
		philo->right_fork->used = 0;
		pthread_mutex_unlock(&(philo->right_fork->mutex));
		pthread_mutex_lock(&(philo->left_fork->mutex));
		philo->left_fork->used = 0;
		pthread_mutex_unlock(&(philo->left_fork->mutex));*/
