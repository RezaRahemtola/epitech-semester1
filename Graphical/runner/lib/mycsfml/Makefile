##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## MY CSFML
##

SRC = src/audio.c \
	  src/clock.c \
	  src/color.c \
	  src/draw.c \
	  src/elements.c \
	  src/events.c \
	  src/framebuffer.c \
	  src/game_object/create_destroy.c \
	  src/game_object/display.c \
	  src/game_object/move.c \
	  src/game_object/utils.c \
	  src/text.c \
	  src/window.c

SRC_H = include/mycsfml_all.h \
		include/mycsfml_audio.h \
		include/mycsfml_clock.h \
		include/mycsfml_color.h \
		include/mycsfml_draw.h \
		include/mycsfml_elements.h \
		include/mycsfml_events.h \
		include/mycsfml_framebuffer.h \
		include/mycsfml_game_obj.h \
		include/mycsfml_text.h \
		include/mycsfml_window.h

OBJ = $(SRC:.c=.o)

NAME = libmycsfml.a
CPPFLAGS = -I include

all:	$(NAME)

$(NAME): 	$(OBJ)
			@ar rc $(NAME) $(OBJ)
			@mkdir -p ../../include
			@cp $(SRC_H) ../../include
			@make clean -s

clean:
			@rm -f $(OBJ_PATH)
			@find -name "*~" -delete
			@find -name "#*#" -delete

fclean:		clean
			@rm -rf $(NAME)

re:		fclean all

.PHONY: all clean fclean re
