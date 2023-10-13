#include "fdf.h"

t_matrix	*row_matrix(t_point *pts)
{
	t_matrix	*new;
	int			ax;
	int			ay;
	int			bx;
	int			by;

	new = malloc(sizeof(t_matrix));
	ax = pts->pixx;
	ay = pts->pixy - pts->pixz;
	pts = pts->next;
	bx = pts->pixx;
	by = pts->pixy - pts->pixz;
	new->x = (bx - ax) * 2;
	new->y = (by - ay) * 2;
	return (new);
}

t_matrix	*line_matrix(t_point *pts, t_grid *grid)
{
	t_matrix	*new;
	int			ax;
	int			ay;
	int			bx;
	int			by;
	int			r;

	new = malloc(sizeof(t_matrix));
	r = 0;
	ax = pts->pixx;
	ay = pts->pixy - pts->pixz;
	while (r < grid->rows)
	{
		pts = pts->next;
		r++;
	}
	bx = pts->pixx;
	by = pts->pixy - pts->pixz;
	new->x = (bx - ax) * 2;
	new->y = (by - ay) * 2;
	return (new);
}
//verificar iteraçao

void	cam_zoom(t_all *all, int order)
{
	t_matrix	*row;
	t_matrix	*line;
	t_matrix	*start;

	start = malloc(sizeof(t_matrix));
	row = row_matrix(all->pts); //nao esquecer de fazer *2
	line = line_matrix(all->pts, all->grid); //e malloc
	start->x = all->pts->pixx;
	start->y = all->pts->pixy - all->pts->pixz - row->y;
	if (order == 1)
		prep_pts(all, row, line, start, 1);
	else if (order == 2)
	{
		start->y = all->pts->pixy + (2 * row->y);
		row->x = row->x / 4;
		row->y = row->y / 4;
		line->x = line->x / 4;
		line->y = line->y / 4;
		prep_pts(all, row, line, start, 2);
	}
	free(row);
	free(line);
	free(start);
}

void	zoom(t_all *all, char order)
{
	t_image	*new;

	new = malloc(sizeof(t_image));
	new->ptr = mlx_new_image(all->mlx->mlx, WIDTH, HEIGHT);
	if (order == 'i')
		cam_zoom(all, 1);
	else if (order == 'o')
		cam_zoom(all, 2);
	display_lines(all->pts, new, all->grid);
	display_rows(all->pts, new, all->grid);
	mlx_put_image_to_window(all->mlx->mlx, all->mlx->win, new->ptr, 0, 0);
	mlx_destroy_image(all->mlx->mlx, all->mlx->img);
	all->mlx->img = new->ptr;
}

/*
prep_points(pts, grid, mx, my, start)
- usar no iso
- usar no zoom
- usar no rotate
as matrizes mx,my e os starts podem ser t_matrix
t_matrix *start
t_matrix *mx
t_matrix *my

com jeitinho todo o modulo de
new_img, draw, put window, destroy, mlx=new
tambem repetia eu
*/