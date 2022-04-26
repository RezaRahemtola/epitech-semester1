##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Task01
##

SRC = my_putchar.c \
	my_strlen.c  \
	my_strncpy.c \
	my_putstr.c \
	my_getnbr.c \
	my_strcpy.c \
	my_put_nbr.c \
	my_strcmp.c \
	my_revstr.c \
	my_strcat.c \
	my_strdup.c \
	my_int_to_base.c \
	my_printf.c \
	my_printf_flags.c \
	my_printf_l_ll.c \
	my_malloc_2d_array.c

OBJ = $(SRC:.c=.o)

NAME = libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
			@ar rc $(NAME) $(OBJ)
			@mkdir -p ../../include
			@cp my.h ../../include
			@make clean -s

clean:
			@rm -f $(OBJ)
			@find -name "*~" -delete
			@find -name "#*#" -delete

fclean:		clean
			@rm -rf $(NAME)

re:		fclean all

.PHONY: all clean fclean re
