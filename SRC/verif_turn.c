/*
** EPITECH PROJECT, 2018
** verif_turn.c
** File description:
** verif turn
*/

#include "my.h"

int verif_line_player(char *gnl_line, char **argv)
{
	int line = my_getnbr(gnl_line);
	int all_line = my_getnbr(argv[1]);

	if (line > all_line || line <= 0) {
		my_putstr("Error : this line is out of range\n");
		return (3);
	}
	return (0);
}

int verif_matches_player(char *map, char *gnl_line,
				char *gnl_matches, char **argv)
{
	int matches = my_getnbr(gnl_matches);
	int line = my_getnbr(gnl_line);
	int allu = 0;
	int line_map = 0;
	int i = 0;

	if (matches > my_getnbr(argv[2])) {
		my_putstr("Error: you cannot remove more than ");
		my_put_nbr(my_getnbr(argv[2]));
		my_putstr(" matches per turn\n");
		return (3);
	}
	while (map[i] != '\0' && line_map != line) {
		if (map[i] == '\n')
			line_map++;
		i++;
	}
	i++;
	while (map[i] != '*') {
		if (map[i] == '|')
			allu++;
		i++;
	}
	if (matches > allu || matches <= 0) {
		my_putstr("Error : not enough matches on this line\n");
		return (3);
	}
	return (0);
}
