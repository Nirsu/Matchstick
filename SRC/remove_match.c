/*
** EPITECH PROJECT, 2018
** remove_match.c
** File description:
** remove matchstick
*/

#include "my.h"

int end_match(char *map, int i)
{
	while (map[i] != '*')
		i++;
	while (map[i] != '|')
		i--;
	return (i);
}

char *remove_match_player(char *map, char *gnl_line, char *gnl_matches)
{
	int line = my_getnbr(gnl_line);
	int matches = my_getnbr(gnl_matches);
	int line_map = 0;
	int i = 0;
	int nbr_remove = 0;

	while (map[i] != '\0' && line_map != line) {
		if (map[i] == '\n') {
			line_map++;
			i++;
		}
		i++;
	}
	i = end_match(map, i);
	while (nbr_remove != matches && map[i] == '|') {
		map[i] = ' ';
		i--;
		nbr_remove++;
	}
	return (map);
}
