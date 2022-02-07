##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## BSQ
##

SRC = my_ls.c \
	  no_option.c \
	  list_option.c \
	  number.c \
	  utils/info.c \
	  utils/time.c \
	  utils/args_parsing.c \
	  utils/list_options.c

SRC_TEST = no_option.c \
		   list_option.c \
		   number.c \
		   utils/info.c \
		   utils/list_options.c \
		   utils/time.c

NAME = my_ls

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

.PHONY: all clean fclean re fclean_tests tests_run
