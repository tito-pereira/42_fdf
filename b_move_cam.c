#include "fdf.h"

void	move_cam(t_all *all, int order)
{
	int mx;
	int my;
	t_point	*iter;

	mx = 0;
	my = 0;
	iter = all->pts;
	if (order == 1)
		my = -1 * MVCAM;
	else if (order == 2)
		mx = -1 * MVCAM;
	else if (order == 3)
		my = 1 * MVCAM;
	else if (order == 4)
		mx = 1 * MVCAM;
	while (iter != NULL)
	{
		iter->pixx += mx;
		iter->pixy += my;
		iter = iter->next;
	}
}

/*
void	move_cam(t_all *all, char order)
{
	t_image	*new;

	new = malloc(sizeof(t_image));
	new->ptr = mlx_new_image(all->mlx->mlx, WIDTH, HEIGHT);
	if (order == 'w')
		cam_change(all->pts, 1);
	else if (order == 'a')
		cam_change(all->pts, 2);
	else if (order == 's')
		cam_change(all->pts, 3);
	else if (order == 'd')
		cam_change(all->pts, 4);
	display_lines(all->pts, new, all->grid);
	display_rows(all->pts, new, all->grid);
	mlx_put_image_to_window(all->mlx->mlx, all->mlx->win, new->ptr, 0, 0);
	mlx_destroy_image(all->mlx->mlx, all->mlx->img);
	all->mlx->img = new->ptr;
}*/