#include "fdf.h"

void	cam_change(t_point *pts, int order)
{
	int mx;
	int my;

	mx = 0;
	my = 0;
	if (order == 1)
		my = -1;
	else if (order == 2)
		mx = -1;
	else if (order == 3)
		my = 1;
	else if (order == 4)
		mx = 1;
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