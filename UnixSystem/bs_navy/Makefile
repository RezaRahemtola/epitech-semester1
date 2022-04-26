##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## BSQ
##

SRC_PRO = process_info.c

NAME_PRO = process_info

SRC_KILL = kill_it.c \
		   my_getnbr.c

NAME_KILL = kill_it

FLAGS = -Wall -Wextra

all:	$(NAME_PRO)

$(NAME_PRO):
			@gcc $(FLAGS) -o $(NAME_PRO) $(SRC_PRO) -I include
			@gcc $(FLAGS) -o $(NAME_KILL) $(SRC_KILL) -I include

clean:
			@find -name "*~" -delete -o -name "#*#" -delete

fclean:		clean
			@rm -f $(NAME_PRO) $(NAME_KILL)
			@find -name "$(TEST_NAME)*" -delete

re:			fclean all

.PHONY: all clean fclean re
