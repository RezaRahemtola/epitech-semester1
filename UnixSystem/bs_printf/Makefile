##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Bistro-matic
##

SRC = sources/disp_stdarg.c \
	  sources/sum_numbers.c \
	  sources/sum_strings_length.c

SRC_TEST = tests/tests_disp_stdarg.c \
		   tests/tests_sum_numbers.c \
		   tests/tests_sum_strings_length.c

OBJ = disp_stdarg.o \
	  sum_numbers.o \
	  sum_strings_length.o

NAME = libmy.a

TEST_NAME = unit_tests

FLAGS = -Wall -Wextra

all:	libmy.a

libmy.a:
			@gcc -c $(SRC)
			@ar rc $(NAME) $(OBJ)

clean:
			@find -name "*~" -delete -o -name "#*#" -delete
			@rm -f $(OBJ)

fclean:		clean
			@rm -f $(NAME)
			@find -name "$(TEST_NAME)*" -delete

re:			fclean libmy.a

unit_tests:		fclean libmy.a
				@gcc $(FLAGS) -o $(TEST_NAME) $(SRC) $(SRC_TEST) \
				-I includes -L . -lmy --coverage -lcriterion

tests_run:	unit_tests
			@./$(TEST_NAME)
