##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Task01
##

SRC = my_putchar.c \
	my_strlen.c  \
	my_compute_square_root.c \
	my_strncpy.c \
	my_putstr.c \
	my_str_isalpha.c \
	my_is_prime.c \
	my_sort_int_array.c \
	my_swap.c \
	my_str_isnum.c \
	my_getnbr.c \
	my_strncat.c \
	my_strupcase.c \
	my_str_isprintable.c \
	my_str_islower.c \
	my_strcpy.c \
	my_put_nbr.c \
	my_strncmp.c \
	my_strcapitalize.c \
	my_compute_power_rec.c \
	my_str_isupper.c \
	my_strcmp.c \
	my_revstr.c \
	my_isneg.c \
	my_find_prime_sup.c \
	my_strcat.c \
	my_strlowcase.c \
	my_strstr.c \
	my_strdup.c \
	my_int_to_base.c \
	my_printf.c \
	my_printf_flags.c \
	my_printf_l_ll.c \
	my_malloc_2d_array.c \
	my_memset.c

OBJ = $(SRC:.c=.o)

NAME = libmy.a

all:	$(NAME)

$(NAME):
			@gcc -c $(SRC)
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
