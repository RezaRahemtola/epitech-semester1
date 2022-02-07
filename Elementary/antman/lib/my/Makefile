##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Task01
##

SRC = src/my_putchar.c \
	  src/my_strlen.c  \
	  src/my_compute_square_root.c \
	  src/my_strncpy.c \
	  src/my_putstr.c \
	  src/my_str_isalpha.c \
	  src/my_is_prime.c \
	  src/my_sort_int_array.c \
	  src/my_swap.c \
	  src/my_str_isnum.c \
	  src/my_getnbr.c \
	  src/my_strncat.c \
	  src/my_strupcase.c \
	  src/my_str_isprintable.c \
	  src/my_str_islower.c \
	  src/my_strcpy.c \
	  src/my_put_nbr.c \
	  src/my_strncmp.c \
	  src/my_strcapitalize.c \
	  src/my_compute_power_rec.c \
	  src/my_str_isupper.c \
	  src/my_strcmp.c \
	  src/my_revstr.c \
	  src/my_isneg.c \
	  src/my_find_prime_sup.c \
	  src/my_strcat.c \
	  src/my_strlowcase.c \
	  src/my_strstr.c \
	  src/my_strdup.c \
	  src/my_int_to_base.c \
	  src/my_printf.c \
	  src/my_printf_flags.c \
	  src/my_printf_l_ll.c \
	  src/my_malloc_2d_array.c \
	  src/my_malloc_str.c \
	  src/my_str_to_word_array.c

OBJ_PATH = my_putchar.o \
	       my_strlen.o  \
	       my_compute_square_root.o \
	       my_strncpy.o \
	       my_putstr.o \
	       my_str_isalpha.o \
	       my_is_prime.o \
	       my_sort_int_array.o \
	       my_swap.o \
	       my_str_isnum.o \
	       my_getnbr.o \
	       my_strncat.o \
	       my_strupcase.o \
	       my_str_isprintable.o \
	       my_str_islower.o \
	       my_strcpy.o \
	       my_put_nbr.o \
	       my_strncmp.o \
	       my_strcapitalize.o \
	       my_compute_power_rec.o \
	       my_str_isupper.o \
	       my_strcmp.o \
	       my_revstr.o \
	       my_isneg.o \
	       my_find_prime_sup.o \
	       my_strcat.o \
	       my_strlowcase.o \
	       my_strstr.o \
	       my_strdup.o \
	       my_int_to_base.o \
	       my_printf.o \
	       my_printf_flags.o \
	       my_printf_l_ll.o \
	       my_malloc_2d_array.o \
		   my_malloc_str.o \
		   my_str_to_word_array.o

OBJ = $(SRC:.c=.o)

NAME = libmy.a

all:	$(NAME)

$(NAME):
			@gcc -c $(SRC) -I include
			@ar rc $(NAME) $(OBJ_PATH)
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
