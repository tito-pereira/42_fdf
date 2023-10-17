#include "fdf.h"

t_matrix	*row_matrix(t_point *pts, int order)
{
	t_matrix	*new;

	new = r_matrix(pts);
	if (new->x * 2 > INT_MAX || new->y * 2 > INT_MAX
		|| (new->x > 0 && new->x / 4 == 0 && order == 2)
		|| (new->y > 0 && new->y / 4 == 0 && order == 2))
		{
			free (new);
			return (NULL);
		}
	if (order == 1)
	{
		new->x *= 2;
		new->y *= 2;
	}
	else if (order == 2)
	{
		new->x = new->x / 2;
		new->y = new->y / 2;
	}
	return (new);
}

t_matrix	*line_matrix(t_point *pts, t_grid *grid, int order)
{
	t_matrix	*new;

	new = l_matrix(pts, grid);
	if (new->x * 2 > INT_MAX || new->y * 2 > INT_MAX
		|| (new->x > 0 && new->x / 4 == 0 && order == 2)
		|| (new->y > 0 && new->y / 4 == 0 && order == 2))
		{
			free (new);
			return (NULL);
		}
	if (order == 1)
	{
		new->x *= 2;
		new->y *= 2;
	}
	else if (order == 2)
	{
		new->x = new->x / 2;
		new->y = new->y / 2;
	}
	return (new);
}

void	zoom(t_all *all, int order)
{
	t_matrix	*row;
	t_matrix	*line;
	t_matrix	*start;

	row = row_matrix(all->pts, order);
	if (row == NULL)
		return;
	line = line_matrix(all->pts, all->grid, order);
	if (line == NULL)
		return;
	start = malloc(sizeof(t_matrix));
	start->x = all->pts->pixx;
	start->y = all->pts->pixy - all->pts->pixz;// - row->y;
	//start->y = all->pts->pixy + row->y;
	prep_pts(all, row, line, start, order);
	free(row);
	free(line);
	free(start);
}

/*void	zoom(t_all *all, char order)
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
}*/