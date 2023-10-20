
NAME= fdf
CC= cc
CFLAGS= -Wall -Wextra -Werror
GDB= cc -g
RM= rm -rf
MAIN= ./mandatory/m_main.c
SRC= ./mandatory/m_grid.c ./mandatory/m_points.c ./mandatory/m_isometric.c \
	./mandatory/m_utils.c ./mandatory/m_display.c ./mandatory/m_draw_line.c \
	./mandatory/m_matrix.c ./mandatory/m_count.c ./mandatory/m_write.c \
	./mandatory/m_free.c
BONUS= ./extra/main_bonus.c \
	./extra/utils_bonus.c ./extra/mv_cam_bonus.c \
	./extra/zoom_bonus.c ./extra/rotate_bonus.c \
	./extra/planar_bonus.c ./extra/incline_bonus.c
LIB1= -L./minilibx-linux/ -lmlx -lXext -lX11 -lm
LIB2= -L./getnext/ -lget
LIB3= -L./libft/ -lft
A_LIB= $(LIB1) $(LIB2) $(LIB3)
AR= ar -rcs
ARCH= libfdf.a
LFDF= -L. -lfdf
MOBJ= ${MAIN:.c=.o} 
OBJ= ${SRC:.c=.o}
B_OBJ= ${BONUS:.c=.o}

all: $(NAME)

$(NAME): $(MOBJ) $(OBJ)
	make -C ./libft
	make -C ./getnext
	make -C ./minilibx-linux
	$(CC) $(CFLAGS) $(MOBJ) $(OBJ) $(A_LIB) -o $(NAME)

wire: $(OBJ)
	$(AR) $(ARCH) $(OBJ)

gdb:
	$(GDB) $(CFLAGS) $(MAIN) $(SRC) $(A_LIB) -o $(NAME)

clean:
	cd ./libft && make clean
	cd ./getnext && make clean
	$(RM) $(MOBJ) $(OBJ) ${B_OBJ}

fclean: clean
	cd ./libft && make fclean
	cd ./getnext && make fclean
	$(RM) $(NAME) $(ARCH)

re: fclean all

.PHONY: bonus

bonus:	$(OBJ) $(B_OBJ)
	make -C ./libft
	make -C ./getnext
	$(CC) $(CFLAGS) $(OBJ) $(B_OBJ) $(A_LIB) -o $(NAME)

