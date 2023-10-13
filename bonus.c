#include "fdf.h"

void	cam_change(t_point *pts, int order)
{
	int mx;
	int my;

	mx = 0;
	my = 0;
	if (order == 1)
		my = -1 * MVCAM;
	else if (order == 2)
		mx = -1 * MVCAM;
	else if (order == 3)
		my = 1 * MVCAM;
	else if (order == 4)
		mx = 1 * MVCAM;
	while (pts != NULL)
	{
		pts->pixx += mx;
		pts->pixy += my;
		pts = pts->next;
	}
}

void	move_cam(t_all *all, char order)
{
	t_image	*new;

	new = malloc(sizeof(t_image));
	new->ptr = mlx_new_image(all->mlx->mlx, WIDTH, HEIGHT);
	if (order == 'w')
		cam_change(all->points, 1);
	else if (order == 'a')
		cam_change(all->points, 2);
	else if (order == 's')
		cam_change(all->points, 3);
	else if (order == 'd')
		cam_change(all->points, 4);
	display_lines(all->points, new, all->grid);
	display_rows(all->points, new, all->grid);
	mlx_put_image_to_window(all->mlx->mlx, all->mlx->win, new->ptr, 0, 0);
	mlx_destroy_image(all->mlx->mlx, all->mlx->img);
	all->mlx->img = new->ptr;
}

void	cam_zoom(t_point *pts, int order)
{
	int	ord;

	ord = 1;
	if (order == 2)
		ord *= -1;
	while (pts != NULL)
	{
		if (pts->pixy < (HEIGHT / 2))
			pts->pixy -= (1 * ord * ZOOM);
		else if (pts->pixy > (HEIGHT / 2))
			pts->pixy += (1 * ord * ZOOM);
		if (pts->pixx < (WIDTH / 2))
			pts->pixx -= (2 * ord * ZOOM);
		else if (pts->pixx > (WIDTH / 2))
			pts->pixx += (2 * ord * ZOOM);
		pts = pts->next;
	}
}

void	zoom(t_all *all, char order)
{
	t_image	*new;

	new = malloc(sizeof(t_image));
	new->ptr = mlx_new_image(all->mlx->mlx, WIDTH, HEIGHT);
	if (order == 'i')
		cam_zoom(all->points, 1);
	else if (order == 'o')
		cam_zoom(all->points, 2);
	display_lines(all->points, new, all->grid);
	display_rows(all->points, new, all->grid);
	mlx_put_image_to_window(all->mlx->mlx, all->mlx->win, new->ptr, 0, 0);
	mlx_destroy_image(all->mlx->mlx, all->mlx->img);
	all->mlx->img = new->ptr;
}

/*
eu acho que faço zoom na mesma matriz de 2:1 da visao isometrica

parte superior, y < HEIGHT, -1

*/