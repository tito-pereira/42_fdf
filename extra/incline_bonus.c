#include "fdf_bonus.h"


int	inc_down_iso(t_matrix *rm, t_matrix *lm)
{
	if ((lm->x == -rm->x)
		&& (!(rm->y != 0 && rm->x / rm->y == 1)))
	{
		rm->y += (rm->x / 2);
		lm->y += (rm->x / 2);
		if (rm->y != 0 && nmb_module(rm->x) / nmb_module(rm->y) == 1)
			return (0);
		else if (rm->y == 0)
			return (33);
		return (3);
	}
	else if ((lm->x == rm->x)
		&& (!(rm->y != 0 && rm->x / rm->y == -1)))
	{
		rm->y -= (rm->x / 2);
		lm->y += (rm->x / 2);
		if (rm->y != 0 && nmb_module(rm->x) / nmb_module(rm->y) == 1)
			return (0);
		else if (rm->y == 0)
			return (33);
		return (3);
	}
	return (-1);
}

int	inc_down_plan(t_matrix *rm, t_matrix *lm)
{
	if ((rm->y == 0 && lm->x == 0)
		&& (!(lm->y != 0 && rm->x / lm->y == 1)))
	{
		lm->y += (rm->x / 2);
		if (lm->y != 0 && nmb_module(rm->x) / nmb_module(lm->y) == 1)
			return (0);
		else if (lm->y == 0)
			return (55);
		return (5);
	}
	else if ((rm->x == 0 && lm->y == 0)
		&& (!(rm->y != 0 && lm->x / rm->y == 1)))
	{
		rm->y += (lm->x / 2);
		if (rm->y != 0 && nmb_module(lm->x) / nmb_module(rm->y) == 1)
			return (0);
		else if (rm->y == 0)
			return (55);
		return (5);
	}
	return (inc_down_iso(rm, lm));
}

int	inc_up_iso(t_matrix *rm, t_matrix *lm)
{
	if ((lm->x == -rm->x) && (!(rm->y != 0 && rm->x / rm->y == -1)))
	{
		rm->y -= (rm->x / 2);
		lm->y -= (rm->x / 2);
		if (rm->y != 0 && nmb_module(rm->x) / nmb_module(rm->y) == 1)
			return (0);
		else if (rm->y == 0)
			return (33);
		return (3);
	}
	else if ((lm->x == rm->x) && (!(rm->y != 0 && rm->x / rm->y == 1)))
	{
		rm->y += (rm->x / 2);
		lm->y -= (rm->x / 2);
		if (rm->y != 0 && nmb_module(rm->x) / nmb_module(rm->y) == 1)
			return (0);
		else if (rm->y == 0)
			return (33);
		return (3);
	}
	return (-1);
}

int	inc_up_plan(t_matrix *rm, t_matrix *lm)
{
	if ((rm->y == 0 && lm->x == 0)
		&& (!(lm->y != 0 && rm->x / lm->y == -1)))
	{
		lm->y -= (rm->x / 2);
		if (lm->y != 0 && nmb_module(rm->x) / nmb_module(lm->y) == 1)
			return (0);
		else if (lm->y == 0)
			return (55);
		return (5);
	}
	else if ((rm->x == 0 && lm->y == 0)
		&& (!(rm->y != 0 && lm->x / rm->y == -1)))
	{
		rm->y -= (lm->x / 2);
		if (rm->y != 0 && nmb_module(lm->x) / nmb_module(rm->y) == 1)
			return (0);
		else if (rm->y == 0)
			return (55);
		return (5);
	}
	return (inc_up_iso(rm, lm));
}

void    incline(t_all *all, int order)
{
    t_matrix    *rm;
    t_matrix    *lm;
	t_matrix	*start;
	int			z;

    rm = r_matrix(all->pts);
	z = 0;
	start = malloc(sizeof(t_matrix));
	lm = l_matrix(all->pts, all->grid);
	if (order == 1)
		z = inc_up_plan(rm, lm);
	else if (order == 2)
		z = inc_down_plan(rm, lm);
	start->x = (WIDTH / 2) - ((all->grid->rows / 2) * rm->x) - ((all->grid->lines / 2) * lm->x);
	start->y = (HEIGHT / 2) - ((all->grid->rows / 2) * rm->y) - ((all->grid->lines / 2) * lm->y);
    if (z != -1)
		prep_pts(all, rm, lm, start, z);
	free(rm);
    free(lm);
	free(start);
}
