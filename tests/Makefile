##
## EPITECH PROJECT, 2023
## project
## File description:
## Makefile
##

SRC	=

OBJ_FOLDER	=	../obj
OBJ	=	$(SRC:.c=.o)
OBJ_FILES	=	$(addprefix $(OBJ_FOLDER)/, $(notdir $(OBJ)))

CC	=	gcc
CFLAGS	=
FLAGS	=
LIB	=	-L../lib -lmy_string -lmy_printf -lmy_stdlib
TEST_FLAGS	=	--coverage -lcriterion
EXE	=	binary_test

all:	$(EXE)

$(EXE):
		@make -C ../lib
		$(CC) -o $(EXE) $(SRC) $(TEST_FLAGS) $(CFLAGS) $(FLAGS) $(LIB)

clean:
		@rm -rf *.gcda
		@rm -rf *.gcno

fclean:	clean
		@rm -rf $(EXE)

re:	fclean all
