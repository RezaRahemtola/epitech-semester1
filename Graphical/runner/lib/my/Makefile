##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Task01
##

SRC = src/my_strlen.c  \
	  src/my_int_to_base.c \
	  src/my_put_nbr.c \
	  src/my_putchar.c \
	  src/my_strcpy.c \
	  src/my_putstr.c \
	  src/my_strcat.c \
	  src/my_strcmp.c \
	  src/my_revstr.c \
	  src/my_strdup.c \
	  src/my_printf.c \
	  src/my_printf_flags.c \
	  src/my_printf_l_ll.c

OBJ = $(SRC:.c=.o)

NAME = libmy.a
CPPFLAGS = -I include

all:	$(NAME)

$(NAME): 	$(OBJ)
			@ar rc $(NAME) $(OBJ)
			@mkdir -p ../../include
			@cp include/my.h ../../include
			@make clean -s

clean:
			@rm -f $(OBJ_PATH)
			@find -name "*~" -delete
			@find -name "#*#" -delete

fclean:		clean
			@rm -rf $(NAME)

re:		fclean all

.PHONY: all clean fclean re
