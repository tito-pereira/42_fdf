#include "fdf.h"

/*
int	inc_down_iso(t_matrix *rm, t_matrix *lm)
{}

int	inc_down_plan(t_matrix *rm, t_matrix *lm)
{}
*/

int	inc_up_iso(t_matrix *rm, t_matrix *lm)
{
	if ((lm->x == rm->x || lm->x == (rm->x * (-1)))
		&& (!(rm->y < 0 && nmb_module(rm->x) / nmb_module(rm->y) == 1)))
	{
		rm->y -= (nmb_module(rm->x) / 2);
		lm->y -= (nmb_module(rm->x) / 2);
		if (rm->y < 0 && nmb_module(rm->x) / nmb_module(rm->y) == 1)
			return (0);
		else if (rm->y < 0 && nmb_module(rm->x) / nmb_module(rm->y) == 2)
			return (3);
		else if (rm->y == 0)
			return (33);
		return (3);
	}
	return (-1);
}

int	inc_up_plan(t_matrix *rm, t_matrix *lm)
{
	if ((rm->y == 0 && lm->x == 0)
		&& (!(lm->y < 0 && nmb_module(rm->x) / nmb_module(lm->y) == 1)))
	{
		lm->y -= (nmb_module(rm->x) / 2);
		if (lm->y < 0 && nmb_module(rm->x) / nmb_module(lm->y) == 1)
			return (0);
		else if (lm->y < 0 && nmb_module(rm->x) / nmb_module(lm->y) == 2)
			return (5);
		else if (lm->y == 0)
			return (55);
		return (5);
	}
	else if ((rm->x == 0 && lm->y == 0)
		&& (!(rm->y < 0 && nmb_module(lm->x) / nmb_module(rm->y) == 1)))
	{
		rm->y -= (nmb_module(lm->x) / 2);
		if (rm->y < 0 && nmb_module(lm->x) / nmb_module(rm->y) == 1)
			return (0);
		else if (rm->y < 0 && nmb_module(lm->x) / nmb_module(rm->y) == 2)
			return (5);
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
	start->x = all->pts->pixx;
	start->y = all->pts->pixy;
	lm = l_matrix(all->pts, all->grid);
	//printf("before\nrm:%d, %d\nlm:%d, %d\n", rm->x, rm->y, lm->x, lm->y);
	//condicoes de inclinação maxima
	if (order == 1)
		z = inc_up_plan(rm, lm);
	//printf("after\nrm:%d, %d\nlm:%d, %d\n", rm->x, rm->y, lm->x, lm->y);
	//else if (order == 2)
		//z = inc_down();
    if (z != -1)
		prep_pts(all, rm, lm, start, z);
	free(rm);
    free(lm);
	free(start);
}

/*void	do_inc(t_all *all, char order)
{
	t_image	*new;

	new = malloc(sizeof(t_image));
	new->ptr = mlx_new_image(all->mlx->mlx, WIDTH, HEIGHT);
    if (order == 'u')
		incline(all, 1);
	else if (order == 'd')
		incline(all, 2);
	display_lines(all->pts, new, all->grid);
	display_rows(all->pts, new, all->grid);
	mlx_put_image_to_window(all->mlx->mlx, all->mlx->win, new->ptr, 0, 0);
	mlx_destroy_image(all->mlx->mlx, all->mlx->img);
	all->mlx->img = new->ptr;
}*/

/*
int	inc_up_iso(t_matrix *rm, t_matrix *lm)
{
	if ((lm->x == rm->x || lm->x == (rm->x * (-1)))
		&& (!(rm->y < 0 && nmb_module(rm->x) / nmb_module(rm->y) == 1)))
	{
		rm->y -= (nmb_module(rm->x) / 2);
		lm->y -= (nmb_module(rm->x) / 2);
		if (rm->y < 0 && nmb_module(rm->x) / nmb_module(rm->y) == 1)
			return (0);
		else if (rm->y < 0 && nmb_module(rm->x) / nmb_module(rm->y) == 2)
			return (40);
		return (4);
	}
	return (1);
}

int	inc_up_plan(t_matrix *rm, t_matrix *lm)
{
	if ((rm->y == 0 && lm->x == 0)
		&& (!(lm->y < 0 && nmb_module(rm->x) / nmb_module(lm->y) == 1)))
	{
		lm->y -= (nmb_module(rm->x) / 2);
		if (lm->y < 0 && nmb_module(rm->x) / nmb_module(lm->y) == 1)
			return (0);
		else if (lm->y < 0 && nmb_module(rm->x) / nmb_module(lm->y) == 2)
			return (40);
		return (4);
	}
	else if ((rm->x == 0 && lm->y == 0)
		&& (!(rm->y < 0 && nmb_module(lm->x) / nmb_module(rm->y) == 1)))
	{
		rm->y -= (nmb_module(lm->x) / 2);
		if (rm->y < 0 && nmb_module(lm->x) / nmb_module(rm->y) == 1)
			return (0);
		else if (rm->y < 0 && nmb_module(lm->x) / nmb_module(rm->y) == 2)
			return (40);
		return (4);
	}
	return (inc_up_iso(rm, lm));
}

void	inc_up_plan(t_matrix *rm, t_matrix *lm)
{
	else if (rm->y == 0 && lm->x == 0) //C
	{
		if (lm->y > 0 && nmb_module(rm->x) / nmb_module(lm->y) == 2)
			lm->y *= 2;
		else if (lm->y == 0)
			lm->y = (nmb_module(rm->x) / 2) * -1;
		else if (lm->y < 0 && nmb_module(rm->x) / nmb_module(lm->y) == 2)
			lm->y = 0;
		else if (lm->y < 0 && nmb_module(rm->x) / nmb_module(lm->y) == 1)
			lm->y /= 2;
	}
	else if (rm->x == 0 && lm->y == 0) //D
	{
		if (rm->y > 0 && nmb_module(lm->x) / nmb_module(rm->y) == 2)
			rm->y *= 2;
		else if (rm->y == 0)
			rm->y = (nmb_module(lm->x) / 2) * -1;
		else if (rm->y < 0 && nmb_module(lm->x) / nmb_module(rm->y) == 2)
			rm->y = 0;
		else if (rm->y < 0 && nmb_module(lm->x) / nmb_module(rm->y) == 1)
			rm->y /= 2;
	}
}

void	inc_up_plan(t_matrix *rm, t_matrix *lm)
{
	else if (rm->y == 0 && lm->x == 0) //C
	{
		if (!(lm->y < 0 && nmb_module(rm->x) / nmb_module(lm->y) == 1))
			lm->y -= (nmb_module(rm->x) / 2);
	}
	else if (rm->x == 0 && lm->y == 0) //D
	{
		if (!(rm->y < 0 && nmb_module(lm->x) / nmb_module(rm->y) == 1))
			rm->y -= (nmb_module(lm->x) / 2);
	}
}

void	inc_up(t_matrix *rm, t_matrix *lm)
{
	if ((lm->x == rm->x || lm->x == (rm->x * (-1)))
		&& (!(rm->y < 0 && nmb_module(rm->x) / nmb_module(rm->y) == 1)))
			rm->y -= (nmb_module(rm->x) / 2);
	else if ((rm->y == 0 && lm->x == 0)
		&& (!(lm->y < 0 && nmb_module(rm->x) / nmb_module(lm->y) == 1)))
			lm->y -= (nmb_module(rm->x) / 2);
	else if ((rm->x == 0 && lm->y == 0)
		&& (!(rm->y < 0 && nmb_module(lm->x) / nmb_module(rm->y) == 1)))
			rm->y -= (nmb_module(lm->x) / 2);
}
*/