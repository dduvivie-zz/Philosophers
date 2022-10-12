#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <limits.h>

/* structures */
typedef struct s_endflag{
	int				finish;
	int				*eat_counter;
	pthread_mutex_t	mutex;
}				t_endflag;

typedef struct s_fork{
	int				id;
	pthread_mutex_t	mutex;
}				t_fork;

typedef struct s_philo{
	int			id;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			num_of_times_eat;
	t_fork		*left_fork;
	t_fork		*right_fork;
	t_endflag	*end_flag;
}				t_philo;

typedef struct s_args{
	int		error_flag;
	int		num_of_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		num_of_times_eat;
}				t_args;

typedef struct s_program{
	t_args		args;
	pthread_t	*threads;
	t_fork		*forks;
	t_endflag	end_flag;
	t_philo		*philos;
}				t_program;

/* check arguments */
int			get_args_in_int(int argc, char *argv[], t_args *args);
int			ft_isdigit(int c);

/* initialization */
int			init_structs(t_program *prg);
pthread_t	*init_threads(t_args *args);
t_fork		*init_forks(t_args *args);
int			init_endflag(t_args *args, t_endflag *end_flag);
t_philo		*init_philos(t_args *args, t_fork *forks, t_endflag *end_flag);

/* simulation */
void		*start(void *data);
void		*start2(void *data); //
void		philo_sleep(struct timeval start, t_philo *philo);
void		philo_think(struct timeval start, t_philo *philo);
void		even_philo_eat(struct timeval start, t_philo *philo);
void		odd_philo_eat(struct timeval start, t_philo *philo);
void		philo_die(struct timeval start, t_philo *philo);

/* timer */
long long	current_timestamp(struct timeval start);
void		usleep_ms(unsigned int time);
void		time_check(struct timeval start, t_philo *philo);

/* before exit the program */
int			error_exit(t_program *prg, int num);
void		destroy_fork_mutex(t_fork *forks, int num);
void		destroy_endflag_mutex(t_endflag *end_flag);
void		free_all_memory(t_program *prg);
#endif
