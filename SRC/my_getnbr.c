/*
** EPITECH PROJECT, 2017
** my_getnbr.c
** File description:
** my_getnbr 2.0
*/

#include "my.h"

int my_getnbr(char *str)
{
	int nombre = 0;
	int i = -1;

	while (++i != my_strlen(str) && str[i] >= '0' && str[i] <= '9') {
		nombre = nombre * 10;
		nombre = (str[i] - '0') + nombre;
	}
	return (nombre);
}
