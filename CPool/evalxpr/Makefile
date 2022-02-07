##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## InfinAdd
##

SRC = number.c \
	  summands.c \
	  factors.c \
	  main.c \
	  eval_expr.c \
	  parenthesis.c \
	  utils.c

SRC_TEST = number.c \
		   summands.c \
		   factors.c \
		   eval_expr.c \
		   utils.c \
		   parenthesis.c

NAME = eval_expr

TEST_NAME = unit_tests

all:	$(NAME)

$(NAME):
			$(MAKE) -C lib/my/
			gcc -Wall -Wextra -o $(NAME) $(SRC) -L lib/my -lmy

clean:
			find -name "*~" -delete -o -name "#*#" -delete

fclean:		clean
			rm -f $(NAME)
			find -name "$(TEST_NAME)*" -delete

re:		fclean all

tests_run:
		$(MAKE) -C lib/my/
		gcc -Wall -Wextra -o $(TEST_NAME) $(SRC_TEST) \
		tests/*.c -L lib/my -lmy --coverage -lcriterion
		./$(TEST_NAME)
