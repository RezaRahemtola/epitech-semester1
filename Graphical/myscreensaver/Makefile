##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## BSQ
##

SRC = main.c \
	  utils/window.c \
	  utils/framebuffer.c \
	  utils/coords.c \
	  utils/draw.c \
	  utils/color.c \
	  animations/tunnel_first.c \
	  animations/circle_second.c \
	  animations/lines_third.c \
	  animations/pixel_night_fourth.c \
	  animations/utils.c \
	  animations/anim_info.c

NAME = my_screensaver

TEST_NAME = unit_tests

FLAGS = -Wall -Wextra

all:	$(NAME)

$(NAME):
			@make re -C lib/my/ -s
			@gcc $(FLAGS) -o $(NAME) $(SRC) -I include -L lib/my -lmy -lm \
			-l csfml-graphics -l csfml-window

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
			@make fclean_tests -s
			@gcc $(FLAGS) -o $(TEST_NAME) $(SRC_TEST) \
			tests/*.c -I include -L lib/my -lmy -lm --coverage -lcriterion
			@./$(TEST_NAME)

.PHONY: all clean fclean re fclean_tests tests_run
