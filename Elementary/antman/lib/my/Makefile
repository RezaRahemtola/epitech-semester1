##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Task01
##

SRC = src/my_putchar.c \
	  src/my_strlen.c  \
	  src/my_strncpy.c \
	  src/my_putstr.c \
	  src/my_getnbr.c \
	  src/my_strcpy.c \
	  src/my_put_nbr.c \
	  src/my_strncmp.c \
	  src/my_compute_power_rec.c \
	  src/my_strcmp.c \
	  src/my_revstr.c \
	  src/my_strcat.c \
	  src/my_strstr.c \
	  src/my_strdup.c \
	  src/my_int_to_base.c \
	  src/my_printf.c \
	  src/my_printf_flags.c \
	  src/my_printf_l_ll.c \
	  src/my_malloc_str.c \

OBJ_PATH = my_putchar.o \
	       my_strlen.o  \
	       my_strncpy.o \
	       my_putstr.o \
	       my_getnbr.o \
	       my_strcpy.o \
	       my_put_nbr.o \
	       my_strncmp.o \
	       my_compute_power_rec.o \
	       my_strcmp.o \
	       my_revstr.o \
	       my_strcat.o \
	       my_strstr.o \
	       my_strdup.o \
	       my_int_to_base.o \
	       my_printf.o \
	       my_printf_flags.o \
	       my_printf_l_ll.o \
		   my_malloc_str.o \

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
