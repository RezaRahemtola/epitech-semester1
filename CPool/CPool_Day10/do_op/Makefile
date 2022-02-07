##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Task02
##

SRC = $(shell find -name "*.c")

NAME = do-op

all:	$(NAME)

$(NAME):
			gcc -o $(NAME) $(SRC) -L ../lib/my -lmy

clean:
			find -name "*~" -delete

fclean: 	clean
			rm -f $(NAME)

re: 	fclean all
