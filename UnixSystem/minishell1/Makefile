##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC =   src/main.c \
		src/parsing.c \
		src/error_handling.c \
		src/input.c \
		src/str_list.c \
		src/minishell.c \
		src/env.c \
		src/builtins/builtins.c \
		src/builtins/cd.c \
		src/builtins/env.c \
		src/builtins/setenv.c \
		src/builtins/unsetenv.c

OBJ =   $(SRC:.c=.o)

NAME =  mysh

CC              =    gcc
CFLAGS          =    -Wall -Wextra
CPPFLAGS        =    -I include
LDFLAGS         =    -L lib/my -lmy

TEST_NAME       =    unit_tests
TEST_PATH       =    tests/*.c
TEST_CSFLAGS    =    --coverage -lcriterion

all:		$(NAME)

$(NAME):	$(OBJ)
			make -C lib/my
			$(CC) $(SRC) -o $(NAME) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)
			@make fclean -C lib/my -s
			@find -name "$(TEST_NAME)*" -delete

re:			fclean all

.PHONY: all clean fclean re tests_run
