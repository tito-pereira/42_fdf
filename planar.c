#include "fdf.h"

t_matrix	*plan_matrix(t_grid *grid)
{
	t_matrix	*pm;

	pm = malloc(sizeof(t_matrix));
	pm->y = 0;
	if (grid->rows > 200)
		pm->x = 2 * SCALE;
	else if (grid->rows > 100 && grid->rows <= 200)
		pm->x = 4 * SCALE;
	else if (grid->rows > 50 && grid->rows <= 100)
		pm->x = 8 * SCALE;
	else if (grid->rows > 25 && grid->rows <= 50)
		pm->x = 16 * SCALE;
	else if (grid->rows <= 25)
		pm->x = 32 * SCALE;
	return (pm);
}

void	planar(t_all *all)
{
	t_matrix	*row;
	t_matrix	*line;
	t_matrix	*start;

	row = plan_matrix(all->grid);
	line = malloc(sizeof(t_matrix));
	line->x = 0;
	line->y = 0;
	start = malloc(sizeof(t_matrix));
	start->x = (WIDTH / 6);
	start->y = (HEIGHT / 2);
	prep_pts(all, row, line, start, 3);
	free(row);
	free(line);
	free(start);
}

void	do_plan(t_all *all)
{
	t_image	*new;

	new = malloc(sizeof(t_image));
	new->ptr = mlx_new_image(all->mlx->mlx, WIDTH, HEIGHT);
	planar(all);
	display_lines(all->pts, new, all->grid);
	display_rows(all->pts, new, all->grid);
	mlx_put_image_to_window(all->mlx->mlx, all->mlx->win, new->ptr, 0, 0);
	mlx_destroy_image(all->mlx->mlx, all->mlx->img);
	all->mlx->img = new->ptr;
}