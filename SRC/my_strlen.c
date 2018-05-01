/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** mon strlen
*/

int my_strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i = i + 1;
	str[i] = '\0';
	return (i);
}
