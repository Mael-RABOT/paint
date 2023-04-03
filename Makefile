##
## EPITECH PROJECT, 2023
## project
## File description:
## Makefile
##

SRC	=	src/main.c \
		src/paint.c \
		src/display.c \
		src/update_texture.c \
		src/shapes/create_rectangle.c \
		src/shapes/create_sprite.c \
		src/event/main_event.c \
		src/event/button_event.c \
		src/event/drawing_functions.c \
		src/event/mousse_button_pressed.c \
		src/event/mousse_button_released.c \
		src/event/mouse_move.c \
		src/event/brush_type_action.c \
		src/resources/create_button.c \
		src/resources/create_menu.c \
		src/resources/init_window.c \
		src/resources/free_window.c \
		src/resources/free_object.c \
		src/resources/swap_button.c \
		src/resources/init_ui_button.c \
		src/resources/init_ruban.c \
		src/welcome_screen/welcome_screen.c \
		src/save/save_image.c \
		src/save/load_image.c \
		src/save/auto_save.c \
		src/save/set_title.c \
		src/save/concat_layer.c \
		src/drawing/put_pixel.c \
		src/drawing/put_background.c \
		src/drawing/square.c \
		src/drawing/circle.c \
		src/drawing/rectangle.c \
		src/event/key_event.c \
		src/slide_bar/init_slide_bar.c \
		src/slide_bar/callbacks.c \
		src/slide_bar/display_slide_bar.c \
		src/get_path/get_path.c \
		src/button_action/alloc_color.c \
		src/button_action/alloc_color_bg.c \
		src/button_action/alloc_brush.c \
		src/button_action/do_nothing.c \
		src/button_action/save_image.c \
		src/button_action/layer_management.c \
		src/tips/tips.c \
		src/parser.c \
		src/custom_color/custom_color.c \
		src/custom_color/update_color.c \
		src/custom_color/color_slide_bar.c \
		src/brush_size/brush_size_windows.c \
		src/brush_size/size_slide_bar.c \
		src/brush_size/size_event.c \
		src/brush_size/update_size.c \
		src/brush_size/size_button_action.c \
		src/keyboard_input/keyboard_input.c \
		src/layer/create_layer.c \
		src/layer/layer_button.c \
		src/layer/free_layer.c \
		src/layer/layer_management.c \
		src/about/about.c

OBJ_FOLDER	=	obj
OBJ	=	$(SRC:.c=.o)
OBJ_FILES	=	$(addprefix $(OBJ_FOLDER)/, $(notdir $(OBJ)))

CC	=	gcc
CFLAGS	=
FLAGS	= -Wall
CSFML	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio
LIB	=	-L./lib -lmy_string -lmy_printf -lmy_stdlib $(CSFML)
SANITIZE	=	-g
EXE	=	my_paint

all:	$(EXE)

%.o:	%.c
		@$(CC) -o $(OBJ_FOLDER)/$(notdir $@) -c $^ $(CFLAGS) $(FLAGS) $(LIB)

$(EXE):
		@make -C ./lib
		$(CC) -o $(EXE) $(SRC) $(LIB) $(CFLAGS) $(FLAGS) $(LIB)

clean:
		@make -C ./lib clean
		@make -C ./tests clean
		@rm -rf $(OBJ_FILES)
		@rm -rf vgcore*
		@rm -rf *.gcda
		@rm -rf *.gcno

fclean:	clean
		@make -C ./lib fclean
		@make -C ./tests fclean
		@rm -rf $(EXE)

valgrind:	$(OBJ)
			@make -C ./lib
			$(CC) -o $(EXE) $(OBJ_FILES) $(CFLAGS) $(FLAGS) $(LIB) $(SANITIZE)

re:	fclean all

run: all
	./$(EXE) $(ARGS)

resize: all
		./resize.sh $(ARGS)

unit_tests:
			@make -C ./tests

tests_run:	unit_tests
			./tests/mysh_test
