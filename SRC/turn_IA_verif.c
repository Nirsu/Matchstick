/*
** EPITECH PROJECT, 2018
** turn_IA_verif.c
** File description:
** verif turn IA
*/

#include "my.h"

int end_match_ia(char *map, int i)
{
	int nbr_allu = 0;

	while (map[i] != '*') {
		if (map[i] == '|')
			nbr_allu++;
		i++;
	}
	if (nbr_allu == 0)
		return (3);
	i = end_match(map, i);
	return (i);
}

char *remove_matches_ia(char *map, int line)
{
	int i = 0;
	int line_map = 0;
	int nbr_remove = 0;
	int matches = 1;

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

int verif_line_ia(char *map, int line)
{
	int i = 0;
	int line_map = 0;

	while (map[i] != '\0' && line_map != line) {
		if (map[i] == '\n') {
			line_map++;
			i++;
		}
		i++;
	}
	i = end_match_ia(map, i);
	if (i == 3)
		return (3);
	return (0);
}
