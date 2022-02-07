##
## EPITECH PROJECT, 2022
## antman_project
## File description:
## Makefile
##

SRC = src/giantman.c

FLAGS = -Wall -Wextra

CPPFLAG = -I include/

LIB = -L lib/my -lmy

OBJ = $(SRC:.c=.o)

NAME = giantman

all: $(OBJ)
	make -C lib/my
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(CPPFLAG) $(LIB)
	rm -f $(OBJ)
	make -C lib/my clean

clean:
	rm -f $(OBJ)
	make -C lib/my clean
	rm -f file.txt

fclean: clean
	rm -f $(NAME)

re: fclean all
