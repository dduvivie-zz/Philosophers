/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:10:48 by dduvivie          #+#    #+#             */
/*   Updated: 2022/10/12 19:10:49 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* Check if the argument is integer */
int	arg_is_int(char *arg)
{
	long int	num;

	num = 0;
	while (*arg != '\0')
	{
		if (!ft_isdigit(*arg))
			return (0);
		num = (num * 10) + (*arg - 48);
		if (num > INT_MAX)
			return (0);
		arg++;
	}
	return (1);
}

/* Convert a char string to a long int */
long	str_to_num(const char *str)
{
	long int	num;

	num = 0;
	while (*str != '\0')
	{
		num = (num * 10) + (*str - 48);
		str++;
	}
	return (num);
}

/* Check if the arguments numbers are correct */
int	args_are_correct(int argc, char *argv[])
{
	int	i;
	int	num;

	if (argc != 4 && argc != 5)
		return (0);
	i = 1;
	while (i <= argc)
	{
		if (!arg_is_int(argv[i]))
			return (0);
		if (i == 1)
		{
			num = (int)str_to_num(argv[i]);
			if (num < 1)
				return (0);
		}
		i++;
	}
	return (1);
}

/* Get all arguments (string) to int */
int	get_args_in_int(int argc, char *argv[], t_args *args)
{
	if (!args_are_correct(argc, argv))
	{
		printf("Error: the arguments are invalid.\n");
		return (0);
	}
	args->num_of_philo = (int)str_to_num(argv[1]);
	args->time_to_die = (int)str_to_num(argv[2]);
	args->time_to_eat = (int)str_to_num(argv[3]);
	args->time_to_sleep = (int)str_to_num(argv[4]);
	if (argc == 5)
		args->num_of_times_eat = (int)str_to_num(argv[5]);
	else
		args->num_of_times_eat = -1;
	return (1);
}
