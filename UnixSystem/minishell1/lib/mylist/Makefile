##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC = src/add.c \
	  src/convert.c \
	  src/destroy.c \
	  src/len.c

OBJ = $(SRC:.c=.o)

NAME = liblist.a

CFLAGS = -Wall -Wextra
CPPFLAGS = -I include

all:		$(NAME)

$(NAME):	$(OBJ)
			ar rc $(NAME) $(OBJ)
			mkdir -p ../../include
			cp include/* ../../include

clean:
			@rm -f $(OBJ)

fclean:		clean
			@rm -rf $(NAME)

re:			fclean all

.PHONY: all clean fclean re
