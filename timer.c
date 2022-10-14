/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:11:57 by dduvivie          #+#    #+#             */
/*   Updated: 2022/10/12 19:11:58 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* Execute usleep() with the millisecond parameter */
void	usleep_ms(unsigned int time)
{
	struct timeval	curr;
	long int		end_microsecond;
	long int		curr_microsecond;

	gettimeofday(&curr, NULL);
	curr_microsecond = (curr.tv_sec * 1000000) + (curr.tv_usec);
	end_microsecond = curr_microsecond + (time * 1000);
	while (curr_microsecond < end_microsecond)
	{
		usleep(100);
		gettimeofday(&curr, NULL);
		curr_microsecond = (curr.tv_sec * 1000000) + (curr.tv_usec);
	}
}

/* Get the current time in millisecond */
long int	get_time(struct timeval *start)
{
	struct timeval	te;
	long int		milliseconds;

	gettimeofday(&te, NULL);
	milliseconds = (((te.tv_sec - start->tv_sec) * 1000) \
					+ (te.tv_usec - start->tv_usec) / 1000);
	return (milliseconds);
}
