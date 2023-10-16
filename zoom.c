#include "fdf.h"

t_matrix	*row_matrix(t_point *pts, int order)
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
	if ((bx - ax) * 2 > INT_MAX || (by - ay) * 2 > INT_MAX
		|| ((bx - ax) > 0 && (bx - ax) / 4 == 0 && order == 2)
		|| ((by - ay) > 0 && (by - ay) / 4 == 0 && order == 2))
		return (NULL);
	new = malloc(sizeof(t_matrix));
	new->x = (bx - ax) * 2;
	new->y = (by - ay) * 2;
	return (new);
}

t_matrix	*line_matrix(t_point *pts, t_grid *grid, int order)
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
	if ((bx - ax) * 2 > INT_MAX || (by - ay) * 2 > INT_MAX
		|| ((bx - ax) > 0 && (bx - ax) / 4 == 0 && order == 2)
		|| ((by - ay) > 0 && (by - ay) / 4 == 0 && order == 2))
		return (NULL);
	new = malloc(sizeof(t_matrix));
	new->x = (bx - ax) * 2;
	new->y = (by - ay) * 2;
	return (new);
}
//colocar intmax

void	cam_zoom(t_all *all, int order)
{
	t_matrix	*row;
	t_matrix	*line;
	t_matrix	*start;

	row = row_matrix(all->pts, order); //nao esquecer de fazer *2
	if (row == NULL)
		return;
	line = line_matrix(all->pts, all->grid, order); //e malloc
	if (line == NULL)
		return;
	//if (line ou row == NULL), return 
	start = malloc(sizeof(t_matrix));
	start->x = all->pts->pixx;
	start->y = all->pts->pixy - all->pts->pixz;// - row->y;
	if (order == 1)
		prep_pts(all, row, line, start, 1);
	else if (order == 2)
	{
		//start->y = all->pts->pixy + row->y;
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
ate consigo utilizar as line matrixes generica, das rotaçoes
e incline, aqui. so preciso de criar uma função auxiliar para:
. fazer as condições de erro
. multiplicar por dois ou dividir por quatro
*/