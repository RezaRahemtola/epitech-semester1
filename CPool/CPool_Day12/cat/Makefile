##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Task01
##

SRC = main.c

OBJ = $(SRC:.c=.o)

NAME = cat

all:	$(NAME)

$(NAME):	$(OBJ)
			$(MAKE) -C ../lib/my/
			gcc -Wall -Wextra -Werror -o $(NAME) $(OBJ) -L ../lib/my -lmy

clean:
			rm -f $(OBJ)
			find -name "*~" -delete

fclean:		clean
			rm -rf $(NAME)

re:		fclean all
