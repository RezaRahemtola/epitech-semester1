##
## EPITECH PROJECT, 2022
## antman_project
## File description:
## Makefile
##

SRC = src/antman.c \
	src/my_getnbr.c

FLAGS = -Wall -Wextra

OBJ = $(SRC:.c=.o)

NAME = antman

all: $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ) -I include
	rm -f $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f file.txt

fclean: clean
	rm -f $(NAME)

re: fclean all
