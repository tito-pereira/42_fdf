#include "fdf_bonus.h"

void	rot_left(t_matrix *rm, t_matrix *lm)
{
	int	tmpx;
	int	tmpy;

	tmpx = rm->x;
	tmpy = rm->y;
	if (lm->x == rm->x)
		rm->y *= -1;
	else if (lm->x == (rm->x * (-1)))
		rm->x *= -1;
	else if (rm->y == 0 && lm->x == 0)
	{
		rm->x = 0;
		rm->y = lm->y;
	}
	else if (rm->x == 0 && lm->y == 0)
	{
		rm->x = lm->x;
		rm->y = 0;
	}
	lm->x = tmpx * -1;
	lm->y = tmpy * -1;
}

void	rot_right(t_matrix *rm, t_matrix *lm)
{
	int	tmpx;
	int	tmpy;

	tmpx = rm->x;
	tmpy = rm->y;
	if (lm->x == rm->x)
		rm->x *= -1;
	else if (lm->x == (rm->x * (-1)))
		rm->y *= -1;
	else if (rm->y == 0 && lm->x == 0)
	{
		rm->x = 0;
		rm->y = lm->y * (-1);
	}
	else if (rm->x == 0 && lm->y == 0)
	{
		rm->x = lm->x * (-1);
		rm->y = 0;
	}
	lm->x = tmpx;
	lm->y = tmpy;
}

void    rotate(t_all *all, int order)
{
    t_matrix    *rm;
    t_matrix    *lm;
	t_matrix	*start;

    start = malloc(sizeof(t_matrix));
	rm = r_matrix(all->pts);
    lm = l_matrix(all->pts, all->grid);
	if (order == 1)
		start->x = all->pts->pixx + (all->grid->lines * lm->x);
	if (order == 1)
		start->y = all->pts->pixy + (all->grid->lines * lm->y);
	if (order == 2)
		start->x = all->pts->pixx + (all->grid->lines * rm->x);
	if (order == 2)
		start->y = all->pts->pixy + (all->grid->lines * rm->y);
	if (order == 1)
		rot_right(rm, lm);
	else if (order == 2)
		rot_left(rm, lm);
	prep_pts(all, rm, lm, start, 4);
	free(rm);
    free(lm);
	free(start);
}
