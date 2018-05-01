##
## EPITECH PROJECT, 2017
## my_sokoban
## File description:
## sokoban
##

NAME	=	matchstick

SRC	=	SRC/matchstick.c	\
		SRC/turn.c	\
		SRC/remove_match.c	\
		SRC/verif_turn.c	\
		SRC/turn_IA_verif.c	\
		SRC/my_putchar.c	\
		SRC/my_putstr.c	\
		SRC/my_getnbr.c	\
		SRC/my_put_nbr.c	\
		SRC/my_strlen.c	\
		SRC/my_get_next_line.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS +=	-I ./include -W -Wall -Wextra -g -g3

all:	$(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
