##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Bistro-matic
##

SRC = main.c \
	  clean_ops.c \
	  infin_add.c \
	  infin_sub.c \
	  infin_mult.c \
	  syntax_checks.c \
	  eval_expr/number.c \
	  eval_expr/summands.c \
	  eval_expr/factors.c \
	  eval_expr/eval_expr.c \
	  eval_expr/parenthesis.c \
	  eval_expr/utils.c

SRC_TEST = clean_ops.c \
		   infin_add.c \
		   infin_sub.c \
		   infin_mult.c \
		   eval_expr/number.c \
		   eval_expr/summands.c \
		   eval_expr/factors.c \
		   eval_expr/eval_expr.c \
		   eval_expr/utils.c \
		   eval_expr/parenthesis.c

NAME = calc

TEST_NAME = unit_tests

FLAGS = -Wall -Wextra

all:	$(NAME)

$(NAME):
			@make re -C lib/my/ -s
			@gcc $(FLAGS) -o $(NAME) $(SRC) -I include -L lib/my -lmy

clean:
			@find -name "*~" -delete -o -name "#*#" -delete

fclean:		clean
			@rm -f $(NAME)
			@find -name "$(TEST_NAME)*" -delete

re:			fclean all

fclean_tests:	clean
				@find -name "$(TEST_NAME)*" -delete

tests_run:
			@make re -C lib/my/ -s
			@make fclean_tests -s
			@gcc $(FLAGS) -o $(TEST_NAME) $(SRC_TEST) \
			tests/*.c -I include -L lib/my -lmy --coverage -lcriterion
			@./$(TEST_NAME)
