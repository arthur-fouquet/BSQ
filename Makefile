##
## EPITECH PROJECT, 2019
## PSU_my_printf_2019
## File description:
## Makefile
##

SRC	=	src/map_char.c		\
		src/map_2d.c		\
		src/free_2d.c		\
		src/my_getnbr.c		\
		src/error_manag.c	\
		src/map_2d_nbr.c	\
		src/algo.c		\
		src/nb_lines_columns.c	\
		src/main.c		\
		src/from_int_to_char.c	\
		src/my_strlen.c		\

SRC_TEST=	tests/tests_project.c

NAME_TEST =	unit_tests

NAME	=	bsq

CC	=	gcc

CPPFLAGS=       $(INCLUDE)

CFLAGS	=	-Wall -Wextra -g3

OBJ	=	$(SRC:.c=.o)

INCLUDE	=	-I./include

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(INCLUDE) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

test_run:
	make re
	gcc src/my_printf.c $(SRC_TEST) -o $(NAME_TEST) -I./include -L./ -lmy -lcriterion

clean_test:
	rm -f *.gcda
	rm -f *.gcno
	rm -f ./tests/*.o

.PHONY: all clean fclean re test_run
