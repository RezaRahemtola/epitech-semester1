##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## giantman
##

SRC = src/main.c \
	  src/decomp_lyr.c \
	  src/decomp_html.c \
	  src/decomp_ppm.c \
	  ../src/error_handling.c \
	  ../src/pattern_list.c \
	  ../src/pattern_utils.c

NAME = giantman

TEST_NAME = unit_tests

FLAGS = -Wall -Wextra

all:	$(NAME)

$(NAME):
			@make re -C ../lib/my/ -s
			@gcc $(FLAGS) -o $(NAME) $(SRC) -I include -I ../include \
			-L ../lib/my -lmy

clean:
			@find -name "*~" -delete -o -name "#*#" -delete \
			-o -name "vgcore.*" -delete

fclean:		clean
			@rm -f $(NAME)
			@find -name "$(TEST_NAME)*" -delete

re:			fclean all

fclean_tests:	clean
				@find -name "$(TEST_NAME)*" -delete

tests_run:
			@make re -C ../lib/my/ -s
			@make fclean_tests -s
			@gcc $(FLAGS) -o $(TEST_NAME) $(SRC_TEST) \
			tests/*.c -I include -L ../lib/my -lmy --coverage -lcriterion
			@./$(TEST_NAME)

.PHONY: all clean fclean re fclean_tests tests_run
