#include <fdf.h>

//void	prep_pts(t_point *p, t_grid *g, t_matrix *r, t_matrix *l, t_matrix *s)
//fazer row matrix e line matrix

void	cam_zoom(t_point *pts, t_grid *grid, int order)
{
	t_matrix	*row;
	t_matrix	*line;
	t_matrix	*start;

	start = malloc(sizeof(t_matrix));
	row = row_matrix(pts, row->x, row->y); //nao esquecer de fazer *2
	line = line_matrix(pts, grid, line->x, line->y); //e malloc
	start->x = pts->pixx;
	start->y = pts->pixy + row->y;
	if (order == 1)
		prep_pts(pts, grid, row, line, start);
	else if (order == 2)
	{
		row->x = row->x / 4;
		row->y = row->y / 4;
		line->x = line->x / 4;
		line->y = line->y / 4;
		start->y = pts->pixy - row->y;
		prep_pts(pts, grid, row, line, start);
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
		cam_zoom(all->points, all->grid, 1);
	else if (order == 'o')
		cam_zoom(all->points, all->grid, 2);
	display_lines(all->points, new, all->grid);
	display_rows(all->points, new, all->grid);
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