#cc window_test.c write.c -L../minilibx-linux/ -lmlx -lXext -lX11 -lm

NAME= fdf
CC= cc
CFLAGS= -wall -wextra -werror
RM= rm -rf
SRC= window_test.c write.cc
OBJ= {.c}

$(NAME):

all:

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)