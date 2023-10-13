
NAME= fdf
CC= cc
CFLAGS= -Wall -Wextra -Werror
RM= rm -rf
SRC= main.c grid.c points.c isometric.c \
	draw_line.c matrix.c count.c write.c bonus.c
LIB= -L../minilibx-linux/ -lmlx -lXext -lX11 -lm
LIB2= -L./getnext/ -lget
LIB3= -L./libft/ -lft
OBJ= ${SRC:.c=.o}

$(NAME):
	$(CC) $(CFLAGS) $(SRC) $(LIB) $(LIB2) $(LIB3) -o $(NAME)

all: $(NAME)

gdb:
	$(CC) -g $(CFLAGS) $(SRC) $(LIB) $(LIB2) $(LIB3) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all