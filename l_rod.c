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

void	rot_aux(t_matrix *rm, t_matrix *l, int order)
{
	int	tmpx;
	int	tmpy;

	tmpx = rm->x;
	tmpy = rm->y;
	if ((lm->x == rm->x && order == 1)
		|| (lm->x == (rm->x * (-1)) && order == 2)) // && order == 1//Ar = Bl
		rm->x *= -1;
	else if ((lm->x == (rm->x * (-1)) && order == 1)
		|| (lm->x == rm->x && order == 2)) // && order == 1 //Br = Al
		rm->y *= -1;
	//else if (lm->x == rm->x && order == 2) // Al, condicoes A, vetor B
	//else if (lm->x == (rm->x * (-1)) && order == 2) // Bl, condicoes B, vetor A
	else if (rm->y == 0 && lm->x == 0) //Cr = Cl
	{
		rm->x = 0;
		rm->y = lm->y * (-1);
	}
	else if (rm->x == 0 && lm->y == 0) //Dr = Dl
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
	rm = row_matrix(all->pts);
    lm = line_matrix(all->pts, all->grid);
	if (order == 1)
	{
		start->x = pts->pixx + (all->grid->rows * lm->x); //right start
		start->y = pts->pixy + (all->grid->rows * lm->y); //right start
	}
	else if (order == 2)
	{
		start->x = pts->pixx + (all->grid->rows * rm->x); //left start
		start->y = pts->pixy + (all->grid->rows * rm->y); //left start
	}
	rot_aux(rm, lm, order);
    prep_pts(all, rm, lm, start, 3);
	free(rm);
    free(lm);
	free(start);
}

void	do_rot(t_all *all, char order)
{
	t_image	*new;

	new = malloc(sizeof(t_image));
	new->ptr = mlx_new_image(all->mlx->mlx, WIDTH, HEIGHT);
    if (order == 'l')
        rotate(all, 1);
    else if (order == '2')
        rotate(all, 2);
	display_lines(all->pts, new, all->grid);
	display_rows(all->pts, new, all->grid);
	mlx_put_image_to_window(all->mlx->mlx, all->mlx->win, new->ptr, 0, 0);
	mlx_destroy_image(all->mlx->mlx, all->mlx->img);
	all->mlx->img = new->ptr;
}

/*
. fazer rotate left (nao existe, é igual)
. tentar modular a rotaçao e a aux numa so função
(right e left)

a componente x da rotação é sempre 2 (denom positivo)
ou -2 (denom negativo)
o que pode variar é a componente y
(0, 1, 2, 1, 0) consoante a incline
se calhar faço primeiro a incline visto que o rotate vai depender dele
e para alem disso, dividir em quadrantes porque tenho 4 vetores diferentes
para cada rotação (a volta de um eixo central , 4 rotações para uma volta
completa)
sao x vetores para x rotações necessarios p uma volta completa


//quadrantes verticais
if (pts->x < (grid->rows / 2))
if (pts->y < (grid->lines / 2))
//
if (pts->x < (grid->rows / 2) && pts->y < (grid->lines / 2))
else if (pts->x < (grid->rows / 2) && pts->y >= (grid->lines / 2))
else if (pts->x >= (grid->rows / 2) && pts->y < (grid->lines / 2))
else if (pts->x >= (grid->rows / 2) && pts->y >= (grid->lines / 2))
void	prep_pts(t_all *a, t_matrix *r, t_matrix *l, t_matrix *s, int order)

void    rot_left(t_all *all, char order)
{
    t_matrix    *rm;
    t_matrix    *lm;
	t_matrix	*start;

    rm = row_matrix(all->pts);
    lm = line_matrix(all->pts, all->grid);
    start->x = pts->pixx + (all->grid->rows * rm->x); //left start
	start->y = pts->pixy + (all->grid->rows * rm->y); //left start
	rot_aux(rm, lm);
    prep_pts(all, rm, lm, start, 3);
	free(rm);
    free(lm);
	free(start);
}

void	change display(t_all *all, char order, void(*f))
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