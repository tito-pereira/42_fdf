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
}

/*void	cam_zoom(t_point *pts, int order)
{
	int	ord;

	ord = 1;
	if (order == 2)
		ord *= -1;
	while (pts != NULL)
	{
		printf("before, x:%d y:%d\n", pts->pixx, pts->pixy);
		if (pts->pixy < (HEIGHT / 2)) {
			printf("y - 1, ");
			pts->pixy -= (1 * ord * ZOOM);
		}
		else if (pts->pixy > (HEIGHT / 2)) {
			printf("y + 1, ");
			pts->pixy += (1 * ord * ZOOM);
		}
		if (pts->pixx < (WIDTH / 2)) {
			printf("x - 2, \n");
			pts->pixx -= (2 * ord * ZOOM);
		}
		else if (pts->pixx > (WIDTH / 2)) {
			printf("x + 2, \n");
			pts->pixx += (2 * ord * ZOOM);
		}
		printf("after, x:%d y:%d\n", pts->pixx, pts->pixy);
		pts = pts->next;
	}
}*/

/*
while (line < grid->lines)
{
	row = 0;
	while (row < grid->rows)
	{
		pts->pixx = (WIDTH / 2) + (line * mxx) + (row * mx);
		pts->pixy = 50 + (line * my) + (row * my) + (-2 * SCALE * pts->z);
		//printf("x:%d y:%d z:%d px:%d py:%d\n", pts->x, pts->y, pts->z, pts->pixx, pts->pixy);
		pts = pts->next;
		row++;
	}
	line++;
}

pts->pixy -= pts->pixz; //tirar a altura do calculo da matrix
pts->pixz mantem se igual na nova atribuição? ou aumenta igual?
acho que aumenta, *2, /2

rmx = 1;
lmx = 1;
rmy = 1;
lmy = 1;
row = 0;
line = 0;
row_matrix(pts, &rmx, &rmy);
line_matrix(pts, grid, &lmx, &lmy);
while (line < grid->lines)
{
	row = 0;
	while (row < grid->rows)
	{
		pts->pixz = pts->pixz * 2;
		pts->pixx = start_x + (2 * lmx) + (2 * rmx);
		pts->pixy = start_y + (2 * rmy) + (2 * rmy) + pts->pixz;
		//printf("x:%d y:%d z:%d px:%d py:%d\n", pts->x, pts->y, pts->z, pts->pixx, pts->pixy);
		pts = pts->next;
		row++;
	}
	line++;
}
*/