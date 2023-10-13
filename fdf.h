#ifndef FDF_H
# define FDF_H

# include "../minilibx-linux/mlx.h"
# include "./libft/libft.h"
# include "./getnext/get_next_line.h"
# include <stdio.h> //printf caseira (acho q n preciso, talvez so p msgs erro?)
# include <stdlib.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define	RED		0x00FF0000
# define	GREEN	0x0000FF00 //altitude acima de 0
# define	BLUE	0x000000FF //altitude abaixo de 0
# define	WHITE	0x00FFFFFF //grelha
# define	BLACK	0x00000000 //apagar pixel
# define	MVCAM	20
# define	SCALE	3
# define	ZOOM	3
# define	WIDTH	1200
# define	HEIGHT	800

//eventos do rato e vetores (esc, rato, zoom, lateral, rotate)
//fechar sem dar segfault
//cores
//bonus (zoom, direcoes, reset iso, )
//ver se bonus tem q compilar diferente

typedef	struct	s_image {
	void	*ptr;
	char	*data;
	int	bpp;
	int	sline;
	int	endian;
}	t_image;

typedef	struct s_mlx {
	void	*mlx;
	void	*win;
	void	*img;
}	t_mlx;

typedef	struct s_grid {
	int	rows;
	int	lines;
	int	total;
	int	*heights;
}	t_grid;

typedef	struct s_point {
	int	x;
	int	y;
	int	z;
	int	pixx;
	int	pixy;
	struct s_point	*next;
}	t_point;

typedef	struct s_lines {
	char	*line;
	struct s_lines	*next;
}	t_lines;

typedef	struct s_heights {
	char	**line;
	struct s_heights	*next;
}	t_heights;

typedef	struct s_matrix {
	int	x;
	int	y;
}	t_matrix;

typedef	struct s_count {
	int	cnt;
	int	reset;
	struct s_count	*nxt;
}	t_count;

typedef	struct s_all {
	t_mlx	*mlx;
	t_grid	*grid;
	t_point	*points;
}	t_all;

void	write_image(t_image *img, int x, int y, int color);
t_grid	*create_grid(char *arg);
t_point	*create_points(t_grid *grid);
void	old_draw(t_point *a, t_point *b, t_image *img);
void    display_iso(t_mlx *mlx, t_point *pts, t_grid *grid, t_image *first);
// frame change
void	display_lines(t_point *pts, t_image *first, t_grid *grid);
void	display_rows(t_point *pts, t_image *first, t_grid *grid);
// matrix
void	draw_line(t_point *a, t_point *b, t_image *img);
void	offset_matrix(t_matrix *m, int *now_x, int *now_y);
void	straight_matrix(t_matrix *m, int *now_x, int *now_y);
int		check_total(int mx, int my);
int		check_offset(int mx, int my);
t_count	*check_count(int offset, int straight);
int		module(int x);
int		signal(int x);
//count
t_count *new_count(int value);
void	chk_pos_cntrs(t_count *count);
int 	chk_zero_cntrs(t_count *count);
void	f_swap(int *a, int *b);
//bonus
void	move_cam(t_all *all, char order);
void	zoom(t_all *all, char order);

#endif

/*
bonus (zoom, direcoes, reset iso, )

acho que vou separar a parte do display ou pelo menos usar as
put lines e put rows depois de mudar os vetores
*/