#include "fdf.h"

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

/*void	rot_aux(t_all *all, t_matrix *rm, t_matrix *lm, t_matrix *start)
{
	int	z;

	z = 0;
	if (nmb_module(rm->y) == nmb_module(lm->x)
		|| nmb_module(rm->x) == nmb_module(lm->y))
		z = 0;
	else
		z = 4;
	prep_pts(all, rm, lm, start, z);
}*/

void    rotate(t_all *all, int order)
{
    t_matrix    *rm;
    t_matrix    *lm;
	t_matrix	*start;

    start = malloc(sizeof(t_matrix));
	rm = r_matrix(all->pts);
    lm = l_matrix(all->pts, all->grid);
	if (order == 1)
		start->x = all->pts->pixx + (all->grid->lines * lm->x); //right start
	if (order == 1)
		start->y = all->pts->pixy + (all->grid->lines * lm->y); //right start
	if (order == 2)
		start->x = all->pts->pixx + (all->grid->lines * rm->x); //left start
	if (order == 2)
		start->y = all->pts->pixy + (all->grid->lines * rm->y); //left start
	if (order == 1)
		rot_right(rm, lm);
	else if (order == 2)
		rot_left(rm, lm);
	//rot_aux(all, rm, lm, start);
	prep_pts(all, rm, lm, start, 4);
	free(rm);
    free(lm);
	free(start);
}

/*void	do_rot(t_all *all, char order)
{
	t_image	*new;

	new = malloc(sizeof(t_image));
	new->ptr = mlx_new_image(all->mlx->mlx, WIDTH, HEIGHT);
    if (order == 'r')
        rotate(all, 1);
    else if (order == 'l')
		rotate(all, 2);
	display_lines(all->pts, new, all->grid);
	display_rows(all->pts, new, all->grid);
	mlx_put_image_to_window(all->mlx->mlx, all->mlx->win, new->ptr, 0, 0);
	mlx_destroy_image(all->mlx->mlx, all->mlx->img);
	all->mlx->img = new->ptr;
}*/

/*
preciso de altura zero (ordem 0) no ultimo grau de
inclinação

rodar sobre a sua propria axis vs rodar na camara
eu faço rodar na sua propria axis, nao faço o outro
mas nao deve ser mt dificil mas agr n faço

if (order == 1)
	{
		start->x = all->pts->pixx + (all->grid->lines * lm->x); //right start
		start->y = all->pts->pixy + (all->grid->lines * lm->y); //right start
	}
	else if (order == 2)
	{
		start->x = all->pts->pixx + (all->grid->lines * rm->x); //left start
		start->y = all->pts->pixy + (all->grid->lines * rm->y); //left start
	}

void	rot_aux(t_matrix *rm, t_matrix *lm)
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

if (order == 1)
{
	start->x = all->pts->pixx + (all->grid->lines * lm->x); //right start
	start->y = all->pts->pixy + (all->grid->lines * lm->y); //right start
}
else if (order == 2)
{
	start->x = all->pts->pixx + (all->grid->lines * lm->x); //left start
	start->y = all->pts->pixy + (all->grid->lines * lm->y); //left start
}
//quadrantes verticais
if (pts->x < (grid->rows / 2))
if (pts->y < (grid->lines / 2))
//
if (pts->x < (grid->rows / 2) && pts->y < (grid->lines / 2))
else if (pts->x < (grid->rows / 2) && pts->y >= (grid->lines / 2))
else if (pts->x >= (grid->rows / 2) && pts->y < (grid->lines / 2))
else if (pts->x >= (grid->rows / 2) && pts->y >= (grid->lines / 2))
void	prep_pts(t_all *a, t_matrix *r, t_matrix *l, t_matrix *s, int order)

void	change display(t_all *all, char order, void (*f)(t_all *, int))
{
	t_image	*new;

	new = malloc(sizeof(t_image));
	new->ptr = mlx_new_image(all->mlx->mlx, WIDTH, HEIGHT);
    f(all, order);
	display_lines(all->pts, new, all->grid);
	display_rows(all->pts, new, all->grid);
	mlx_put_image_to_window(all->mlx->mlx, all->mlx->win, new->ptr, 0, 0);
	mlx_destroy_image(all->mlx->mlx, all->mlx->img);
	all->mlx->img = new->ptr;
}

void	zoom(t_all *all, char order)
{
	if (order == 'i')
		cam_zoom(all, 1);
	else if (order == 'o')
		cam_zoom(all, 2);
}

void	move_cam(t_all *all, char order)
{
	if (order == 'w')
		cam_change(all->pts, 1);
	else if (order == 'a')
		cam_change(all->pts, 2);
	else if (order == 's')
		cam_change(all->pts, 3);
	else if (order == 'd')
		cam_change(all->pts, 4);
}
*/