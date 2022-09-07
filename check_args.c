#include "philosophers.h"

/* Check if the argument contains only digits */
int	arg_is_positive_num(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

/* Convert a char string to a long int */
long	str_to_num(const char *str)
{
	long int	num;

	num = 0;
	while (ft_isdigit(*str))
	{
		num = (num * 10) + (*str - 48);
		str++;
	}
	return (num);
}

/* Check if the arguments numbers are correct */
int	args_are_correct(int argc, char *argv[])
{
	int			i;
	long int	num;

	if (argc != 4 && argc != 5)
		return (0);
	i = 1;
	while (i < argc)
	{
		if (i == 1)
		{
			num = str_to_num(argv[i]);
			if (num < 2)
				return (0);
		}
		if (!arg_is_positive_num(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

void	get_args_in_int(int argc, char *argv[], t_args *args)
{
	long int	num;

	args->error_flag = 1;
	if (!args_are_correct(argc, argv))
		return ;
	args->error_flag = 0;
	num = str_to_num(argv[1]);
	args->num_of_philo = (unsigned int)num;
	num = str_to_num(argv[2]);
	args->time_to_eat = (unsigned int)num;
	num = str_to_num(argv[3]);
	args->time_to_sleep = (unsigned int)num;
	num = str_to_num(argv[4]);
	args->time_to_think = (unsigned int)num;
	if (argc == 5)
	{
		num = str_to_num(argv[5]);
		args->num_of_times_eat = (int)num;
	}
	else
		args->num_of_times_eat = -1;
}
