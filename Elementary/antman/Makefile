##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## antman global
##

all:
		@make -C antman/ -s
		@make -C giantman/ -s

clean:
		@find -name "*~" -delete -o -name "#*#" -delete \
		-o -name "vgcore.*" -delete

fclean:		clean
			@make fclean -C antman/ -s
			@make fclean -C giantman/ -s

re:			fclean all

.PHONY: all clean fclean re
