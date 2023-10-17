#include "fdf.h"

void	move_cam(t_all *all, int order)
{
	int mx;
	int my;

	mx = 0;
	my = 0;
	printf("moving cam\n");
	if (order == 1)
		my = -1 * MVCAM;
	else if (order == 2)
		mx = -1 * MVCAM;
	else if (order == 3)
		my = 1 * MVCAM;
	else if (order == 4)
		mx = 1 * MVCAM;
	while (all->pts != NULL)
	{
		all->pts->pixx += mx;
		all->pts->pixy += my;
		all->pts = all->pts->next;
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

/*
void	move_cam(t_all *all, char order)
{
	if (order == 'w')
		cam_change(all->pts, 1);
	else if (order == 'a')
		cam_change(all->pts, 2);
	else if (order == 's')
		cam_change(all->pts, 3);
	else if (order == 'd')
		cam_change(all->pts, 4);
}

void	change_display(t_all *all, char order, void(*f))
{
	t_image	*new;

	new = malloc(sizeof(t_image));
	new->ptr = mlx_new_image(all->mlx->mlx, WIDTH, HEIGHT);
    (*f)(all, order);
	display_lines(all->pts, new, all->grid);
	display_rows(all->pts, new, all->grid);
	mlx_put_image_to_window(all->mlx->mlx, all->mlx->win, new->ptr, 0, 0);
	mlx_destroy_image(all->mlx->mlx, all->mlx->img);
	all->mlx->img = new->ptr;
}
*/