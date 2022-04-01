##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC = src/main.c \
	  src/disp_studio.c \
	  src/menu.c \
	  src/window.c \
	  src/events.c \
	  src/game_obj.c \
	  src/game/end_screens.c \
	  src/game/game.c \
	  src/game/move_objects.c \
	  src/game/pause.c

NAME = my_runner

CFLAGS      =  -Wall -Wextra
CPPFLAGS    =  -I include -L lib/my -lmy -lm
CSFML_FLAGS =  -L lib/mycsfml -lmycsfml \
			   -l csfml-graphics -l csfml-window -l csfml-system -l csfml-audio

TEST_NAME   =  unit_tests
TEST_SRC    =  $(SRC)
TEST_PATH   =  tests/*.c
TEST_FLAGS  =  --coverage -lcriterion

all:	$(NAME)

$(NAME):
			@make re -C lib/my/ -s
			@make re -C lib/mycsfml/ -s
			@gcc -o $(NAME) $(SRC) $(CFLAGS) $(CPPFLAGS) $(CSFML_FLAGS)

clean:
			@find -name "*~" -delete -o -name "#*#" -delete

fclean:		clean
			@rm -f $(NAME)
			@find -name "$(TEST_NAME)*" -delete

re:			fclean all

fclean_tests:	clean
				@find -name "$(TEST_NAME)*" -delete

tests_run:
			@make re -C lib/my/ -s
			@make re -C lib/mycsfml/ -s
			@make fclean_tests -s
			@gcc -o $(TEST_NAME) $(TEST_SRC) $(TEST_PATH) $(TEST_FLAGS)
			@./$(TEST_NAME)

.PHONY: all clean fclean re fclean_tests tests_run
