/*
** EPITECH PROJECT, 2018
** turn.c
** File description:
** turn for matchstick
*/

#include "my.h"

int check_stick(char *map)
{
	int i = 0;
	int nbr_allu = 0;

	while (map[i] != '\0') {
		if (map[i] == '|')
			nbr_allu++;
		i++;
	}
	return (nbr_allu);
}

void put_play(char *gnl_matches, char *gnl_line)
{
	my_putstr("Player removed ");
	my_put_nbr(my_getnbr(gnl_matches));
	my_putstr(" match(es) from line ");
	my_put_nbr(my_getnbr(gnl_line));
	my_putstr("\n");
}

char *turn_player(char *map, char **argv)
{
	char *gnl_line = NULL;
	char *gnl_matches = NULL;

	my_putstr("Line: ");
	gnl_line = my_get_next_line(0);
	if (gnl_line == NULL)
		return ("3");
	if (verif_line_player(gnl_line, argv) == 3)
		return ("0");
	my_putstr("Matches: ");
	gnl_matches = my_get_next_line(0);
	if (gnl_matches == NULL)
		return ("3");
	if (verif_matches_player(map, gnl_line, gnl_matches, argv) == 3) {
		return ("0");
	}
	put_play(gnl_matches, gnl_line);
	map = remove_match_player(map, gnl_line, gnl_matches);
	return (map);
}

char *turn_ia(char *map, char **argv)
{
	int line_max = my_getnbr(argv[1]);
	int line = 0;
	int verif = 0;

	while (verif == 0) {
		line = rand()%(line_max - 1 + 1) + 1;
		if (verif_line_ia(map, line) == 0)
			verif = 1;
	}
	map = remove_matches_ia(map, line);
	my_putstr("AI removed 1 match(es) from line ");
	my_put_nbr(line);
	my_putstr("\n");
	return (map);
}

int turn(char *map, char **argv)
{
	int nbr_allu = check_stick(map);
	char *map_save = map;

	my_putstr("\n");
	my_putstr("Your turn: \n");
	while (nbr_allu != 0) {
		map = turn_player(map, argv);
		if (map == "3")
			return (0);
		if (map == "0") {
			map = map_save;
			map = turn_player(map, argv);
		}
		my_putstr(map);
		nbr_allu = check_stick(map);
		if (nbr_allu == 0) {
			my_putstr("\nYou lost, too bad...\n");
			return (2);
		}
		my_putstr("\n\nAI's turn...\n");
		map = turn_ia(map, argv);
		my_putstr(map);
		nbr_allu = check_stick(map);
		if (nbr_allu == 0) {
			my_putstr("\nI lost...snif\n");
			return (1);
		}
		map_save = map;
		my_putstr("\n\nYour turn: \n");
	}
	return (0);
}
