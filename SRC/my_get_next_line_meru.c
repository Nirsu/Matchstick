/*
** EPITECH PROJECT, 2018
** my_get_next_line
** File description:
** get_next_line
*/

#include "my.h"

char *my_get_next_line(int fd)
{
	char *buff = malloc(sizeof(char) * 100000);
	int size = 0;

	if (buff == NULL)
		return (NULL);
	size = read(fd, buff, sizeof(buff));
	if (size == 0)
		return (NULL);
	buff[size] = '\0';
	return (buff);
}
