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

