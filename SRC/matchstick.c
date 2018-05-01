/*
** EPITECH PROJECT, 2018
** matchstick.c
** File description:
** le matchstick
*/

#include "my.h"

char *remplace_by_pipe(char *map, int first_line)
{
	int mid_first_line = (first_line - 2) / 2;
	int i = 0;

	while (map[i] != ' ')
		i++;
	map[i + mid_first_line] = '|';
	while (map[i] != '\0') {
		if (map[i - first_line - 1] == '|' && map[i] != '*') {
			map[i] = '|';
			map[i - 1] = '|';
			map[i + 1] = '|';
		}
		i++;
	}
	return (map);
}

char *remplace_by_space(char *map, int first_line)
{
	int i = 0;
	int space = 0;

	while (i != first_line)
		i++;
	while (map[i] != '\0') {
		i = i + 2;
		while (space != (first_line - 2)) {
			space++;
			map[i] = ' ';
			i++;
		}
		space = 0;
		i++;
	}
	while (map[--i] != '\n')
		map[i] = '*';
	return (remplace_by_pipe(map, first_line));
}

char *print_board(char **argv)
{
	int board = my_getnbr(argv[1]);
	int first_line = board + (board - 1) + 2;
	char *map = malloc(sizeof(char) * (first_line) * (board + 2) * 2 );
	int line = 0;
	int colum = 0;
	int i = 0;

	while (colum != board + 2) {
		while (line != first_line) {
			map[i] = '*';
			i++;
			line++;
		}
		map[i] = '\n';
		line = 0;
		i++;
		colum++;
	}
	map[i - 1] = '\0';
	return (remplace_by_space(map, first_line));
}

int start_matchstick(char **argv)
{
	char *map = NULL;
	int verif = 0;

	map = print_board(argv);
	my_putstr(map);
	my_putstr("\n");
	verif = turn(map, argv);
	if (verif == 3)
		return (0);
	if (verif == 2)
		return (2);
	if (verif == 1)
		return (1);
	return (0);
}

int main(int argc, char **argv)
{
	int nbr = 0;

	if (argc < 3 || argc > 3) {
		write(1, "Error : ./matchstick <line> <stick>", 36);
		return (84);
	}
	nbr = my_getnbr(argv[1]);
	if (nbr <= 1 || nbr >= 100) {
		write(1, "Error : only between 2 and 99", 30);
		return (84);
	}
	else {
		return (start_matchstick(argv));
	}
	return (0);
}
