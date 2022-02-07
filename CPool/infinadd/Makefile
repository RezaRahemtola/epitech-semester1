##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## InfinAdd
##

SRC = main.c \
	 infin_add.c \
	 utils.c

NAME = infin_add

all:	$(NAME)

$(NAME):
			$(MAKE) -C lib/my/
			gcc -Wall -Wextra -o $(NAME) $(SRC) -L lib/my -lmy

clean:
			find -name "*~" -delete
			find -name "unit_tests*" -delete

fclean:		clean
			rm -f $(NAME)

re:		fclean all

tests_run:
		$(MAKE) -C lib/my/
		gcc -Wall -Wextra -o unit_tests infin_add.c utils.c \
		tests/test_infin_add.c -L lib/my -lmy -lcriterion --coverage
		./unit_tests
