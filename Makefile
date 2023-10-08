#cc window_test.c write.c -L../minilibx-linux/ -lmlx -lXext -lX11 -lm

NAME= fdf
CC= cc
CFLAGS= -Wall -Wextra -Werror
RM= rm -rf
SRC= main.c write.c draw_line.c grid.c points.c
LIB= -L../minilibx-linux/ -lmlx -lXext -lX11 -lm
OBJ= main.o write.o draw_line.o grid.o points.o

$(NAME):
	$(CC) $(CFLAGS) $(SRC) $(LIB) -o $(NAME)

all: $(NAME)

gdb:
	$(CC) -g $(CFLAGS) $(SRC) $(LIB) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)