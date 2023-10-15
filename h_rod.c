#include "fdf.h"

void    inc_down(t_all *all, char order)
{
    t_matrix    *rm;
    t_matrix    *lm;
	t_matrix	*start;

    rm = row_matrix(all->pts);
    lm = line_matrix(all->pts, all->grid);
    start->x = pts->pixx;
	start->y = pts->pixy;
	if (rm / lm == 2) // 2:1
    else if (rm / lm == 1) //2:2
    else if (rm / lm == 0) //0:qq coisa, 2:0 nao resulta, 0:0 nao resulta
    else if (rm / lm == -2) //-2:1, 2:-1
    prep_pts(all, rm, lm, start, 3);
	free(rm);
    free(lm);
	free(start);
}

void    inc_up(t_all *all, char order)
{
    t_matrix    *rm;
    t_matrix    *lm;
	t_matrix	*start;

    rm = row_matrix(all->pts);
    lm = line_matrix(all->pts, all->grid);
    start->x = pts->pixx;
	start->y = pts->pixy;
	if (rm / lm == 2) // 2:1
    else if (rm / lm == 1) //2:2
    else if (rm / lm == 0) //0:qq coisa, 2:0 nao resulta, 0:0 nao resulta
    else if (rm / lm == -2) //-2:1, 2:-1
    prep_pts(all, rm, lm, start, 3);
	free(rm);
    free(lm);
	free(start);
}

void	incline(t_all *all, char order)
{
	t_image	*new;

	new = malloc(sizeof(t_image));
	new->ptr = mlx_new_image(all->mlx->mlx, WIDTH, HEIGHT);
    if (order == 'l')
        inc_up(all, 'u');
    else if (order == '2')
        inc_down(all, 'd');
	display_lines(all->pts, new, all->grid);
	display_rows(all->pts, new, all->grid);
	mlx_put_image_to_window(all->mlx->mlx, all->mlx->win, new->ptr, 0, 0);
	mlx_destroy_image(all->mlx->mlx, all->mlx->img);
	all->mlx->img = new->ptr;
}