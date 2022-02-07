##
## EPITECH PROJECT, 2022
## antman_project
## File description:
## Makefile
##

SRC = src/antman.c

FLAGS = -Wall -Wextra

OBJ = $(SRC:.c=.o)

NAME = antman

all: $(OBJ)
	make -C lib/my
	gcc $(FLAGS) -o $(NAME) $(OBJ) -I include -L lib/my -lmy
	rm -f $(OBJ)
	make -C lib/my clean

clean:
	rm -f $(OBJ)
	make -C lib/my clean
	rm -f file.txt

fclean: clean
	rm -f $(NAME)

re: fclean all
