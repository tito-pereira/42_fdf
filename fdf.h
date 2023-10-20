#ifndef FDF_H
# define FDF_H

# include "./minilibx-linux/mlx.h"
# include "./libft/libft.h"
# include "./getnext/get_next_line.h"
# include <stdio.h> //printf caseira (acho q n preciso, talvez so p msgs erro?)
# include <stdlib.h>
# include <math.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define	RED		0x00FF0000
# define	GREEN	0x0000FF00
# define	YELLOW	0x00FFFF00
# define	BROWN	0x00964B00
# define	BLUE	0x000000FF
# define	LBLUE	0x006060FF
# define	WHITE	0x00FFFFFF
# define	BLACK	0x00000000
# define	MVCAM	50
# define	SCALE	2
# define	ZOOM	3
# define	WIDTH	1200
# define	HEIGHT	800

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
	int	pixz;
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
	t_point	*pts;
}	t_all;

int			check_file(char *name);
void		write_image(t_image *img, int x, int y, int color);
t_grid		*create_grid(char *arg);
t_point		*create_points(t_grid *grid);
void		new_iso(t_all *all);
void		isometric(t_all *all, int order);
//utils
int			count_rows(char **points);
int			count_lines(t_lines *lines);
t_heights	*new_heights_node(char **str);
t_lines		*new_lines_node(char *str);
// framing
void		display_lines(t_point *pts, t_image *first, t_grid *grid);
void		display_rows(t_point *pts, t_image *first, t_grid *grid);
void		prep_pts(t_all *a, t_matrix *r, t_matrix *l, t_matrix *s, int order);
// matrix
void		draw_line(t_point *a, t_point *b, t_image *img);
void		offset_matrix(t_matrix *m, int *now_x, int *now_y);
void		straight_matrix(t_matrix *m, int *now_x, int *now_y);
int			check_total(int mx, int my);
int			check_offset(int mx, int my);
t_count		*check_count(int offset, int straight);
int			nmb_module(int x);
int			signal(int x);
//count
t_count 	*new_count(int value);
void		chk_pos_cntrs(t_count *count);
int 		chk_zero_cntrs(t_count *count);
void		f_swap(int *a, int *b);
//bonus
void		change_frame(t_all *all, int function, int order);
void		move_cam(t_all *all, int order);
void		zoom(t_all *all, int order);
void		planar(t_all *all, int order);
void		rotate(t_all *all, int order);
void		incline(t_all *all, int order);
t_matrix	*r_matrix(t_point *pts);
t_matrix	*l_matrix(t_point *pts, t_grid *grid);

#endif

/*
.norm
.valgrind
--

- onde fica a pasta do minilibx? dentro do meu repositorio?
*/

//-------------------

/*
Makefile e executavel tem de ser no root do repositorio
however, posso ter as pastas que quiser para o resto
uma mandatory, outra bonus, etc

If your project allows you to use your libft, you must copy its sources and its
associated Makefile in a libft folder with its associated Makefile. Your project’s
Makefile must compile the library by using its Makefile, then compile the project.
libft
. inside a libft folder c o seu libft Makefile
. o make do fdf deve fazer make no libft primeiro
. bonus com os seus _bonus.c e .h
*/

/* ACABAR MANDATORIO
. como fechar a window no X (ver githubs porque nao e c minilibx)
evento 33 em vez do evento 17? ja e uma pista
*/