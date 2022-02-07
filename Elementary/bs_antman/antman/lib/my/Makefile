##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## FIrst makefile
##

SRC =	my_compute_power_rec.c \
		my_compute_square_root.c \
		my_find_prime_sup.c \
		my_getnbr.c \
		my_isneg.c \
		my_is_prime.c \
		my_putchar.c \
		my_put_nbr.c \
		my_putstr.c \
		my_revstr.c \
		my_showmem.c \
		my_showstr.c \
		my_sort_int_array.c \
		my_strcapitalize.c \
		my_strcat.c \
		my_strcmp.c \
		my_strcpy.c \
		my_str_isalpha.c \
		my_str_islower.c \
		my_str_isnum.c \
		my_str_isprintable.c \
		my_str_isupper.c \
		my_strlen.c \
		my_strlowcase.c \
		my_strncat.c \
		my_strncmp.c \
		my_strncpy.c \
		my_strstr.c \
		my_strupcase.c \
		my_swap.c \
		my_printf.c \
		hexadecimal.c \
		octal.c \
		binary.c \
		hexadecimal_maj.c \
		pointer_void.c \
		binary_long.c \
		hexadecimal_long.c \
		hexadecimal_maj_long.c \
		my_put_long.c \
		octal_long.c \
		put_octal.c \
		format.c \
		binary_long_long.c \
		hexadecimal_maj_long_long.c \
		hexadecimal_long_long.c \
		my_put_long_long.c \
		octal_long_long.c \
		my_memset.c

OBJ = $(SRC:.c=.o)

NAME = libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)
	cp my.h ../../include/

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)
	@rm -f ../../$(NAME)

re:	fclean all
