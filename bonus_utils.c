#include "fdf.h"

t_matrix	*r_matrix(t_point *pts)
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
	new = malloc(sizeof(t_matrix));
	new->x = (bx - ax);
	new->y = (by - ay);
	return (new);
}

t_matrix	*l_matrix(t_point *pts, t_grid *grid)
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
	new = malloc(sizeof(t_matrix));
	new->x = (bx - ax);
	new->y = (by - ay);
	return (new);
}