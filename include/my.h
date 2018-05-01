/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#ifndef MY_H
#define MY_H

#include <unistd.h>
#include <stdlib.h>

int my_putchar(char c);
int my_putstr(char *str);
int my_getnbr(char *str);
int my_put_nbr(int nb);
int turn(char *map, char **argv);
int verif_line_player(char *gnl_line, char **argv);
int verif_matches_player(char *map, char *gnl_line, char *gnl_matches, char **argv);
int end_match_ia(char *map, int i);
int check_stick(char *map);

char *my_get_next_line(int fd);
char *remove_match_player(char *map, char *gnl_line, char *gnl_matches);
char *turn_player(char *map, char **argv);
char *turn_ia(char *map, char **argv);
char *remove_matches_ia(char *map, int line);
char *check_map_turn_player (char *map, char *map_save, char **argv);

void error_matches(int matches, char *map, int position, int argc, char **argv);
void error_line(int line, char *map, int argc, char**argv);
void put_play(char *gnl_matches, char *gnl_line);

int my_strlen(char const *str);
int verif_player(char *map, int line, int matches);
int end_match(char *map, int i);
int verif_line_ia(char *map, int line);

#endif
