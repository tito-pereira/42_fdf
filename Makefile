#cc window_test.c write.c -L../minilibx-linux/ -lmlx -lXext -lX11 -lm

NAME= fdf
CC= cc
CFLAGS= -Wall -Wextra -Werror
RM= rm -rf
SRC= window_test.c write.c images.c grid.c
LIB= -L../minilibx-linux/ -lmlx -lXext -lX11 -lm
OBJ= window_test.o write.o images.o grid.o

$(NAME):
	$(CC) $(CFLAGS) $(SRC) $(LIB) -o $(NAME)

all: $(NAME)

gdb:
	$(CC) -g $(CFLAGS) $(SRC) $(LIB) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)