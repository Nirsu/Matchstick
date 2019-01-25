/*
** EPITECH PROJECT, 2017
** my_put_nbr.c
** File description:
**
*/

#include "my.h"
#include<unistd.h>

int my_put_nbr(int nb)
{
	if (nb < 0) {
		my_putchar('-');
		nb = nb * (-1);
	}
	if (nb >= 10) {
		my_put_nbr(nb / 10);
	}
	nb = nb % 10 + '0';
	my_putchar(nb);
	return (0);
}
