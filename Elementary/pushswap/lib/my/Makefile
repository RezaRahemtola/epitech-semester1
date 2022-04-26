##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Task01
##

SRC = my_putchar.c \
	my_strlen.c  \
	my_putstr.c \
	my_getnbr.c \
	my_strcmp.c \
	my_put_nbr.c

OBJ = $(SRC:.c=.o)

NAME = libmy.a

all:	$(NAME)

$(NAME): 	$(OBJ)
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

.PHONY: all clean fclean re
