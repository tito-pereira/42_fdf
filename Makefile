
NAME= fdf
CC= cc
CFLAGS= -Wall -Wextra -Werror
GDB= cc -g
RM= rm -rf
SRC= m_main.c \
	m_grid.c m_points.c m_isometric.c m_utils.c\
	m_display.c m_draw_line.c m_matrix.c m_count.c m_write.c
BONUS= b_main.c \
	m_grid.c m_points.c m_isometric.c m_utils.c\
	m_display.c m_draw_line.c m_matrix.c m_count.c m_write.c \
	b_utils.c b_move_cam.c b_zoom.c b_rotate.c b_planar.c b_incline.c
LIB1= -L../minilibx-linux/ -lmlx -lXext -lX11 -lm
LIB2= -L./getnext/ -lget
LIB3= -L./libft/ -lft
A_LIB= $(LIB1) $(LIB2) $(LIB3)
OBJ= ${SRC:.c=.o}
B_OBJ= ${BONUS:.c=.o}

$(NAME):
	$(CC) $(CFLAGS) $(SRC) $(A_LIB) -o $(NAME)

all: $(NAME)

.PHONY: bonus

bonus:
	$(CC) $(CFLAGS) $(BONUS) $(A_LIB) -o $(NAME)

gdb:
	$(GDB) $(CFLAGS) $(SRC) $(A_LIB) -o $(NAME)

clean:
	$(RM) $(OBJ) ${B_OBJ}

fclean: clean
	$(RM) $(NAME)

re: fclean all