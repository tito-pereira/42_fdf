#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "../getnext/get_next_line.h"
# include "../mandatory/fdf.h"

//bonus
void		change_frame(t_all *all, int function, int order);
void		move_cam(t_all *all, int order);
void		zoom(t_all *all, int order);
void		planar(t_all *all, int order);
void		rotate(t_all *all, int order);
void		incline(t_all *all, int order);
t_matrix	*r_matrix(t_point *pts);
t_matrix	*l_matrix(t_point *pts, t_grid *grid);
void	    invert_z(t_point *pts);

#endif