#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <limits.h>

/* structures */
typedef struct s_fork{
	int				id;
	int				used;
	pthread_mutex_t	mutex;
}				t_fork;

typedef struct s_philo{
	int			id;
	int			time_to_eat;
	int			time_to_sleep;
	int			time_to_think;
	int			num_of_times_eat;
	t_fork		*left_fork;
	t_fork		*right_fork;
}				t_philo;

typedef struct s_args{
	int				error_flag;
	unsigned int	num_of_philo;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	time_to_think;
	int				num_of_times_eat;
}				t_args;

int				args_are_correct(int argc, char *argv[]);
void			get_args_in_int(int argc, char *argv[], t_args *args);
pthread_t		*init_threads(t_args *args);
t_fork			*init_forks(t_args *args);
t_philo			*init_philos(t_args *args, t_fork *fork_list);

int				ft_isdigit(int c);
void			*philo_start(void *data);
void			philo_sleep(t_philo *philo);
void			philo_think(t_philo *philo);


#endif
