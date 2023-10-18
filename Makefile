
NAME= fdf
CC= cc
CFLAGS= -Wall -Wextra -Werror
GDB= cc -g
RM= rm -rf
MAIN= ./mandatory/m_main.c
SRC= ./mandatory/m_grid.c ./mandatory/m_points.c ./mandatory/m_isometric.c \
	./mandatory/m_utils.c ./mandatory/m_display.c ./mandatory/m_draw_line.c \
	./mandatory/m_matrix.c ./mandatory/m_count.c ./mandatory/m_write.c
BONUS= ./extra/main_bonus.c \
	./extra/utils_bonus.c ./extra/mv_cam_bonus.c \
	./extra/zoom_bonus.c ./extra/rotate_bonus.c \
	./extra/planar_bonus.c ./extra/incline_bonus.c
LIB1= -L../minilibx-linux/ -lmlx -lXext -lX11 -lm
LIB2= -L./getnext/ -lget
LIB3= -L./libft/ -lft
A_LIB= $(LIB1) $(LIB2) $(LIB3)
AR= ar -rcs
ARCH= libfdf.a
LIBF= -L. -lfdf
MOBJ= ${MAIN:.c=.o} 
OBJ= ${SRC:.c=.o}
B_OBJ= ${BONUS:.c=.o}

all: $(NAME)

$(NAME): $(MOBJ) $(OBJ)
	$(CC) $(CFLAGS) $(MOBJ) $(OBJ) $(A_LIB) -o $(NAME)

wire: $(OBJ)
	$(AR) $(ARCH) $(OBJ)

gdb:
	$(GDB) $(CFLAGS) $(MAIN) $(SRC) $(A_LIB) -o $(NAME)

clean:
	$(RM) $(MOBJ) $(OBJ) ${B_OBJ}

fclean: clean
	$(RM) $(NAME) $(ARCH)

re: fclean all

.PHONY: bonus

bonus:	$(OBJ) $(B_OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(B_OBJ) $(A_LIB) -o $(NAME)

#$(NAME): wire\
	$(CC) $(CFLAGS) $(SRC) $(A_LIB) $(LIBF) -o $(NAME)\
all: $(NAME)
 #libmylibrary.a file1.o file2.o
#	./extra/m_grid.c ./extra/m_points.c ./extra/m_isometric.c \
	./extra/m_utils.c ./extra/m_display.c ./extra/m_draw_line.c \
	./extra/m_matrix.c ./extra/m_count.c ./extra/m_write.c