/*
** EPITECH PROJECT, 2017
** my_put_nbr.c
** File description:
**
*/

#include "my.h"
#include<unistd.h>

int my_pow(int value, int exponent)
{
	if (exponent == 0)
	{
		my_putchar (1);
	}

	while (exponent > 0)
	{
		value = 10 * value;
		exponent = exponent - 1;
	}
	return (value);
}

int my_put_nbr(int nb)
{
	if (nb < 0)
	{
		my_putchar('-');
		nb = nb * (-1);
	}
	int tmp = nb;
	int cpt = 0;

	while (tmp > 0)
	{
		tmp = tmp / 10;
		cpt = cpt + 1;
	}
	int mpow = my_pow(10, cpt - 2);
	int unit = 0;

	while (mpow > 0)
	{
		unit = nb / mpow;
		my_putchar(unit %10 + '0');
		mpow = mpow / 10;
	}
	return (0);
}
