#include "fdf_bonus.h"

t_matrix	*r_matrix(t_point *pts)
{
	t_matrix	*new;
	int			ax;
	int			ay;
	int			bx;
	int			by;

	ax = pts->pixx;
	ay = pts->pixy - pts->pixz;
	pts = pts->next;
	bx = pts->pixx;
	by = pts->pixy - pts->pixz;
	new = malloc(sizeof(t_matrix));
	new->x = (bx - ax);
	new->y = (by - ay);
	return (new);
}

t_matrix	*l_matrix(t_point *pts, t_grid *grid)
{
	t_matrix	*new;
	int			ax;
	int			ay;
	int			bx;
	int			by;
	int			r;

	ax = pts->pixx;
	ay = pts->pixy - pts->pixz;
	r = 0;
	while (r++ < grid->rows)
		pts = pts->next;
	bx = pts->pixx;
	by = pts->pixy - pts->pixz;
	new = malloc(sizeof(t_matrix));
	new->x = (bx - ax);
	new->y = (by - ay);
	return (new);
}

void	choose_function(t_all *all, int function, int order)
{
	if (function == 1)
		move_cam(all, order);
	else if (function == 2)
		zoom(all, order);
	else if (function == 3)
		planar(all, order);
	else if (function == 4)
		isometric(all, order);
	else if (function == 5)
		rotate(all, order);
	else if (function == 6)
		incline(all, order);
}

void	change_frame(t_all *all, int function, int order)
{
	t_image	*new;

	new = malloc(sizeof(t_image));
	new->ptr = mlx_new_image(all->mlx->mlx, WIDTH, HEIGHT);
    choose_function(all, function, order);
	display_lines(all->pts, new, all->grid);
	display_rows(all->pts, new, all->grid);
	mlx_put_image_to_window(all->mlx->mlx, all->mlx->win, new->ptr, 0, 0);
	mlx_destroy_image(all->mlx->mlx, all->mlx->img);
	all->mlx->img = new->ptr;
}