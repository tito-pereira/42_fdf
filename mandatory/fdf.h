/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:40:58 by tibarbos          #+#    #+#             */
/*   Updated: 2023/10/23 16:01:56 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "../getnext/get_next_line.h"
# include <stdlib.h>
# include <math.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define RED	0x00FF0000
# define GREEN	0x0000FF00
# define YELLOW	0x00FFFF00
# define BROWN	0x00964B00
# define BLUE	0x000000FF
# define LBLUE	0x006060FF
# define WHITE	0x00FFFFFF
# define BLACK	0x00000000
# define MVCAM	50
# define SCALE	2
# define ZOOM	3
# define WIDTH	1200
# define HEIGHT	800

typedef struct s_image {
	void	*ptr;
	char	*data;
	int		bpp;
	int		sl;
	int		ed;
}	t_image;

typedef struct s_mlx {
	void	*mlx;
	void	*win;
	void	*img;
}	t_mlx;

typedef struct s_grid {
	int	rows;
	int	lines;
	int	total;
	int	maxz;
	int	*heights;
}	t_grid;

typedef struct s_point {
	int				x;
	int				y;
	int				z;
	int				pixx;
	int				pixy;
	int				pixz;
	struct s_point	*next;
}	t_point;

typedef struct s_lines {
	char			*line;
	struct s_lines	*next;
}	t_lines;

typedef struct s_heights {
	char				**line;
	struct s_heights	*next;
}	t_heights;

typedef struct s_matrix {
	int	x;
	int	y;
}	t_matrix;

typedef struct s_count {
	int				cnt;
	int				reset;
	struct s_count	*nxt;
}	t_count;

typedef struct s_trimat {
	t_matrix	*r;
	t_matrix	*l;
	t_matrix	*s;
}	t_trimat;

typedef struct s_draw {
	t_point		*a;
	t_matrix	*m;
	t_image		*img;
	int			color;
}	t_draw;

typedef struct s_all {
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
// free
void		free_all(t_all *all);
void		free_count(t_count *count);
void		free_grid(t_heights *points, t_lines *lines);
void		free_mat(t_trimat *m);
// utils
int			count_rows(char **points);
t_heights	*new_heights_node(char **str);
t_lines		*new_lines_node(char *str);
// framing
void		display_lines(t_point *pts, t_image *first, t_grid *grid);
void		display_rows(t_point *pts, t_image *first, t_grid *grid);
void		prep_pts(t_all *a, t_trimat *m, int ord);
// draw
void		draw_unvn_off(t_draw *d, t_count *count);
void		draw_unvn_str(t_draw *d, t_count *count);
// matrix
void		draw_line(t_point *a, t_point *b, t_image *img);
void		offset_matrix(t_matrix *m, int *now_x, int *now_y);
void		straight_matrix(t_matrix *m, int *now_x, int *now_y);
int			check_total(int mx, int my);
int			check_offset(int mx, int my);
t_count		*check_count(int offset, int straight);
int			nmb_module(int x);
int			signal(int x);
// count
t_count		*new_count(int value);
void		chk_pos_cntrs(t_count *count);
int			chk_zero_cntrs(t_count *count);
void		f_swap(int *a, int *b);

#endif
