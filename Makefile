# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/23 13:46:46 by tibarbos          #+#    #+#              #
#    Updated: 2024/08/02 17:39:51 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fdf

# Compiler && Tools
CC= cc
CFLAGS= -Wall -Wextra -Werror
GDB= cc -g
RM= rm -rf

# Output colors
RED= \e[31m
GREEN= \e[32m
BLUE= \e[34m
WHITE= \e[37m

# Source && Object Files
MAIN= ./src/mandatory/m_main.c
SRC= ./src/mandatory/m_grid.c ./src/mandatory/m_points.c \
	./src/mandatory/m_isometric.c \
	./src/mandatory/m_utils.c ./src/mandatory/m_display.c \
	./src/mandatory/m_free.c \
	./src/mandatory/m_matrix.c ./src/mandatory/m_count.c \
	./src/mandatory/m_write.c \
	./src/mandatory/m_draw_1.c ./src/mandatory/m_draw_2.c
BONUS= ./src/extra/main_bonus.c \
	./src/extra/utils_bonus.c ./src/extra/mv_cam_bonus.c \
	./src/extra/zoom_bonus.c ./src/extra/rotate_bonus.c \
	./src/extra/planar_bonus.c ./src/extra/incline_bonus.c \
	./src/extra/handles_bonus.c
OBJDIR= ./obj
MOBJ= $(MAIN:%.c=$(OBJDIR)/%.o) 
OBJ= $(SRC:%.c=$(OBJDIR)/%.o)
B_OBJ= $(BONUS:%.c=$(OBJDIR)/%.o)

# Includes
LIB1= -L./minilibx-linux/ -lmlx -lXext -lX11 -lm
LIB2= -L./include/get_next_line/ -lget
LIB3= -L./include/libft/ -lft
A_LIB= $(LIB1) $(LIB2) $(LIB3)
AR= ar -rcs
ARCH= libfdf.a
LFDF= -L. -lfdf

.PHONY: pack trygdb all bonus clean fclean re

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(MOBJ) $(OBJ)
	@make -C ./include/libft
	@make -C ./include/get_next_line
	@make -C ./minilibx-linux
	@$(CC) $(CFLAGS) $(MOBJ) $(OBJ) $(A_LIB) -o $(NAME)
	@echo "$(BLUE)fdf: $(GREEN)program compiled$(WHITE)"

pack: $(OBJ)
	@$(AR) $(ARCH) $(OBJ)

trygdb:
	@$(GDB) $(CFLAGS) $(MAIN) $(SRC) $(A_LIB) -o $(NAME)

all: $(NAME)

bonus:	$(OBJ) $(B_OBJ)
	@make -C ./libft
	@make -C ./get_next_line
	@make -C ./minilibx-linux
	@$(CC) $(CFLAGS) $(OBJ) $(B_OBJ) $(A_LIB) -o $(NAME)
	@echo "$(BLUE)fdf: $(GREEN)program bonus compiled$(WHITE)"

clean:
	@cd ./libft && make -s clean
	@cd ./get_next_line && make -s clean
	@$(RM) $(MOBJ) $(OBJ) ${B_OBJ}
	@echo "$(BLUE)fdf: $(RED)object files removed$(WHITE)"

fclean: clean
	@cd ./libft && make -s fclean
	@cd ./get_next_line && make -s fclean
	@$(RM) $(NAME) $(ARCH)
	@echo "$(BLUE)fdf: $(RED)program and object files removed$(WHITE)"

re: fclean all
