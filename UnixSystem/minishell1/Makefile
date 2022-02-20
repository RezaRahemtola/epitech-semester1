##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC_DIR        =    src/

SRC            =    main.c \
					parsing.c \
					input.c \
					execute.c \
					minishell.c \
					builtins/builtins.c \
					builtins/cd.c \
					builtins/env.c \
					builtins/setenv.c \
					builtins/unsetenv.c \
					builtins/exit.c

SRCS           =    $(addprefix $(SRC_DIR), $(SRC))

OBJ            =    $(SRCS:.c=.o)

NAME           =    mysh

CC             =    gcc
CFLAGS         =    -Wall -Wextra
CPPFLAGS       =    -I include
LDFLAGS        =    -L lib/my -L lib/mylist
LDLIBS         =    -lmy -llist

all:		$(NAME)

$(NAME):	$(OBJ) libs
			$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS)

libs:
			make -C lib/my
			make -C lib/mylist

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)
			make fclean -C lib/my -s
			make fclean -C lib/mylist -s

debug:		CFLAGS += -g
debug:		re
			valgrind --track-origins=yes --leak-check=full ./$(NAME)

re:			fclean all

.PHONY: all libs clean fclean debug re
