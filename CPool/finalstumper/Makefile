##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## FinalStumper
##

SRC =	main.c \
	    stumper.c	\
	    get_size.c \
		rush1/get_square.c \
		rush1/get_special_case.c \
		rush1/rush1_1.c \
		rush1/rush1_2.c \
		rush1/rush1_3.c \
		rush1/rush1_4.c \
		rush1/rush1_5.c \
		rush1/utils.c

SRC_TEST = stumper.c \
		   get_size.c \
		   rush1/get_square.c \
           rush1/get_special_case.c \
           rush1/rush1_1.c \
           rush1/rush1_2.c \
           rush1/rush1_3.c \
           rush1/rush1_4.c \
           rush1/rush1_5.c \
		   rush1/utils.c

NAME = rush3

TEST_NAME = unit_tests

all:	$(NAME)

$(NAME):
		$(MAKE) -C lib/my/
		gcc -Wall -Wextra -o $(NAME) $(SRC) -I include -L lib/my -lmy

clean:
		find -name "*~" -delete -o -name "#*#" -delete

fclean:	clean
		rm -f $(NAME)
		find -name "$(TEST_NAME)*" -delete

re:		fclean all

fclean_tests: clean
			 find -name "$(TEST_NAME)*" -delete
tests_run:
		$(MAKE) -C lib/my/
		make fclean_tests
		gcc -Wall -Wextra -o $(TEST_NAME) $(SRC_TEST) \
		tests/*.c -I include -L lib/my -lmy --coverage -lcriterion
		./$(TEST_NAME)
