#include "fdf_bonus.h"

t_matrix	*plan_matrix(t_grid *grid)
{
	t_matrix	*pm;

	pm = malloc(sizeof(t_matrix));
	pm->y = 0;
	if (grid->rows > 200)
		pm->x = 2;
	else if (grid->rows > 100 && grid->rows <= 200)
		pm->x = 4;// * SCALE;
	else if (grid->rows > 50 && grid->rows <= 100)
		pm->x = 8;// * SCALE;
	else if (grid->rows > 25 && grid->rows <= 50)
		pm->x = 16;// * SCALE;
	else if (grid->rows <= 25)
		pm->x = 32;// * SCALE;
	return (pm);
}

void	planar(t_all *all, int order)
{
	t_matrix	*row;
	t_matrix	*line;
	t_matrix	*start;

	row = plan_matrix(all->grid);
	line = malloc(sizeof(t_matrix));
	line->x = 0;
	line->y = 0;
	start = malloc(sizeof(t_matrix));
	start->x = (WIDTH / 12);
	if (all->grid->rows > 200)
		start->x = 50;
	start->y = (HEIGHT / 8) * 7;
	if (order == 1)
		prep_pts(all, row, line, start, 5);
	free(row);
	free(line);
	free(start);
}

/*
devia arranjar uma max height para usar aqui na posição inicial

(-1 * nmb_module((rm->x + lm->x) / 2) * iter->z)

max_height = iter->z
(rm->x / 2) * max_height e fazer contas por aí
*/