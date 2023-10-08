#ifndef FDF_H
# define FDF_H

# include "../minilibx-linux/mlx.h"
# include <stdio.h> //printf caseira (acho q n preciso, talvez so p msgs erro?)
# include <stdlib.h>
# define	RED		0x00FF0000
# define	GREEN	0x0000FF00 //altitude acima de 0
# define	BLUE	0x000000FF //altitude abaixo de 0
# define	WHITE	0x00FFFFFF //grelha
# define	BLACK	0x00000000 //apagar pixel

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
	t_point	*next;
}	t_point;

typedef	struct s_all {
	t_mlx	*mlx;
	t_grid	*grid;
	t_point	*points;
}	t_all;

void	write_image(t_image *img, int x, int y, int color);
t_grid	*create_grid(char *arg);
t_point	*create_points(t_grid *grid);
void	draw_line(t_point *a, t_point *b, t_image *img);
void	img_av_central(t_image *img, char *n);
void	img_key_central(t_image *img, int n);

#endif