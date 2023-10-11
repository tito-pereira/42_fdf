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
# define	SLOPE	0.05
# define	SCALE	4
# define	WIDTH	1200
# define	HEIGHT	800

//eventos do rato e vetores (zoom, lateral, rotate)
//cores
//retirar a ultima linha
//nova draw_line

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

typedef	struct s_all {
	t_mlx	*mlx;
	t_grid	*grid;
	t_point	*points;
}	t_all;

void	write_image(t_image *img, int x, int y, int color);
t_grid	*create_grid(char *arg);
t_point	*create_points(t_grid *grid);
void	draw_line(t_point *a, t_point *b, t_image *img);// t_grid *g);
void    display_iso(t_mlx *mlx, t_point *pts, t_grid *grid, t_image *first);

#endif