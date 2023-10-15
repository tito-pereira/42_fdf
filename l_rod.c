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
    start->x = pts->pixx + (all->grid->rows * rm->x);
	start->y = pts->pixy + (all->grid->rows * rm->y);
	if (rm / lm == 2) // 2:1
    else if (rm / lm == 1) //2:2
    else if (rm / lm == 0) //0:qq coisa, 2:0 nao resulta, 0:0 nao resulta
    else if (rm / lm == -2) //-2:1, 2:-1
    prep_pts(all, rm, lm, start, 3);
	free(rm);
    free(lm);
	free(start);
}

void    rot_right(t_all *all, char order)
{
    t_matrix    *rm;
    t_matrix    *lm;
	t_matrix	*start;

    rm = row_matrix(all->pts);
    lm = line_matrix(all->pts, all->grid);
    start->x = pts->pixx + (all->grid->rows * lm->x);
	start->y = pts->pixy + (all->grid->rows * lm->y);
	if (rm / lm == 2) // 2:1
    else if (rm / lm == 1) //2:2
    else if (rm / lm == 0) //0:qq coisa, 2:0 nao resulta, 0:0 nao resulta
    else if (rm / lm == -2) //-2:1, 2:-1
    prep_pts(all, rm, lm, start, 3);
	free(rm);
    free(lm);
	free(start);
}

void	rotate(t_all *all, char order)
{
	t_image	*new;

	new = malloc(sizeof(t_image));
	new->ptr = mlx_new_image(all->mlx->mlx, WIDTH, HEIGHT);
    if (order == 'l')
        rot_right(all, 'r');
    else if (order == '2')
        rot_left(all, 'l');
	display_lines(all->pts, new, all->grid);
	display_rows(all->pts, new, all->grid);
	mlx_put_image_to_window(all->mlx->mlx, all->mlx->win, new->ptr, 0, 0);
	mlx_destroy_image(all->mlx->mlx, all->mlx->img);
	all->mlx->img = new->ptr;
}

/*
a componente x da rotação é sempre 2 (denom positivo)
ou -2 (denom negativo)
o que pode variar é a componente y
(0, 1, 2, 1, 0) consoante a incline
se calhar faço primeiro a incline visto que o rotate vai depender dele
e para alem disso, dividir em quadrantes porque tenho 4 vetores diferentes
para cada rotação (a volta de um eixo central , 4 rotações para uma volta
completa)
sao x vetores para x rotações necessarios p uma volta completa

para ja fazer sem o change display, estudo pointers p funçoes no fim

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