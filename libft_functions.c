/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:11:41 by dduvivie          #+#    #+#             */
/*   Updated: 2022/10/12 19:11:43 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
Tests for a decimal digit character,  '0' ~ '9'.
Return: 1(True) or 0(False)
*/
int	ft_isdigit(int c)
{
	if (c < 48 || c > 57)
		return (0);
	return (1);
}
