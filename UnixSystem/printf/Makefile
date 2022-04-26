##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Bistro-matic
##

SRC = my_printf.c \
      flag_functions.c \
      l_ll_flags.c \
      func_flags.c \
      func_flags2.c

SRC_LIB = lib/my_putchar.c \
        lib/my_strlen.c  \
        lib/my_putstr.c \
        lib/my_strcpy.c \
        lib/my_put_nbr.c \
        lib/my_strcmp.c \
        lib/my_revstr.c \
        lib/my_strcat.c \
        lib/my_strdup.c \
        lib/my_int_to_base.c

OBJ = $(SRC:.c=.o)

OBJ_LIB = $(SRC_LIB:.c=.o)

NAME = libmy.a

TEST_NAME = unit_tests

FLAGS = -Wall -Wextra

all:	libmy.a

libmy.a:        $(OBJ) $(OBJ_LIB)
		@ar rc $(NAME) $(OBJ) $(OBJ_LIB)
		@make clean -s

clean:
		@find -name "*~" -delete -o -name "#*#" -delete
	        @rm -f $(OBJ) $(OBJ_LIB)

fclean:		clean
		@rm -f $(NAME)
		@find -name "$(TEST_NAME)*" -delete

re:	fclean libmy.a

tests_run:	fclean libmy.a
		@gcc $(FLAGS) -o $(TEST_NAME) $(SRC) $(SRC_LIB) tests/*.c \
		-I include -L . -lmy --coverage -lcriterion
		@./$(TEST_NAME)
