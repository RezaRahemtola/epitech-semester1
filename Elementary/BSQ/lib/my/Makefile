##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Task01
##

SRC = my_getnbr.c \
	my_strncat.c

OBJ = $(SRC:.c=.o)

NAME = libmy.a

all:	$(NAME)

$(NAME):
			@gcc -c $(SRC)
			@ar rc $(NAME) $(OBJ)
			@mkdir -p ../../include
			@cp my.h ../../include
			@make clean -s

clean:
			@rm -f $(OBJ)
			@find -name "*~" -delete
			@find -name "#*#" -delete

fclean:		clean
			@rm -rf $(NAME)

re:		fclean all
