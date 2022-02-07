##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## BSQ
##

SRC_PRO = process_info.c

NAME_PRO = process_info

SRC_KILL = kill_it.c

NAME_KILL = kill_it

TEST_NAME = unit_tests

FLAGS = -Wall -Wextra

all:	$(NAME_PRO)

$(NAME_PRO):
			@make re -C lib/my/ -s
			@gcc $(FLAGS) -o $(NAME_PRO) $(SRC_PRO) -I include -L lib/my -lmy
			@gcc $(FLAGS) -o $(NAME_KILL) $(SRC_KILL) -I include -L lib/my -lmy

clean:
			@find -name "*~" -delete -o -name "#*#" -delete

fclean:		clean
			@rm -f $(NAME_PRO) $(NAME_KILL)
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

.PHONY: all clean fclean re fclean_tests tests_run
