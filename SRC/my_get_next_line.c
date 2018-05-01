/*
** EPITECH PROJECT, 2018
** my_get_next_line.c
** File description:
** get next line
*/

#include "my.h"

char *my_get_next_line(int fd)
{
	int i = 0;
	int byte_read = 0;
	char buf;
	char *str = malloc(sizeof(char) * 100000);
	int boucle = 1;

	if (str == NULL)
		return (NULL);
	while (boucle == 1 && read(fd, &buf, 1)) {
		if (buf == '\n')
			boucle = 0;
		str[i] = buf;
		i++;
	}
	if (buf == 0) {
		free(str);
		return (NULL);
	}
	str[--i] = '\0';
	return (str);
}
