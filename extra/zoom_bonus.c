#include "fdf_bonus.h"

t_matrix	*row_matrix(t_point *pts, int order)
{
	t_matrix	*new;

	new = r_matrix(pts);
	if (new->x * 2 > INT_MAX || new->y * 2 > INT_MAX
		|| (new->x > 0 && new->x / 4 == 0 && order == 2)
		|| (new->y > 0 && new->y / 4 == 0 && order == 2))
		{
			free (new);
			return (NULL);
		}
	if (order == 1)
	{
		new->x *= 2;
		new->y *= 2;
	}
	else if (order == 2)
	{
		new->x = new->x / 2;
		new->y = new->y / 2;
	}
	return (new);
}

t_matrix	*line_matrix(t_point *pts, t_grid *grid, int order)
{
	t_matrix	*new;

	new = l_matrix(pts, grid);
	if (new->x * 2 > INT_MAX || new->y * 2 > INT_MAX
		|| (new->x > 0 && new->x / 4 == 0 && order == 2)
		|| (new->y > 0 && new->y / 4 == 0 && order == 2))
		{
			free (new);
			return (NULL);
		}
	if (order == 1)
	{
		new->x *= 2;
		new->y *= 2;
	}
	else if (order == 2)
	{
		new->x = new->x / 2;
		new->y = new->y / 2;
	}
	return (new);
}

void	def_start_out(t_all *all, t_matrix *rm, t_matrix *lm, t_matrix *start)
{
	//printf("out\n");
	if (lm->x == (rm->x * (-1)))
	{
		//printf("iso move y\n");
		start->x = all->pts->pixx;
		start->y = all->pts->pixy + (all->grid->lines * (lm->y / 2));			
	}
	else if (lm->x == rm->x)
	{
		//printf("iso move x\n");
		//printf("lmx %d rmx %d\n", lm->x, rm->x);
		//printf("before x:%d y:%d\n", all->pts->pixx, all->pts->pixy);
		start->x = all->pts->pixx + (all->grid->rows * (rm->x / 2));
		start->y = all->pts->pixy;
		//printf("after x:%d y:%d\n", start->x, start->y);
	}
	/*else if ((rm->y == 0 && lm->x == 0) || (rm->x == 0 && lm->y == 0))
	{
		start->x = all->pts->pixx + (all->grid->rows * (rm->x / 2));
		start->y = all->pts->pixy + (all->grid->lines * (lm->y / 2));
	}*/
	else if (rm->y == 0 && lm->x == 0)
	{
		//printf("plan move y=0\n");
		//printf("lmy %d rmx %d\n", lm->y, rm->x);
		//printf("before x:%d y:%d\n", all->pts->pixx, all->pts->pixy);
		start->x = all->pts->pixx + (all->grid->rows * (rm->x / 2));
		start->y = all->pts->pixy + (all->grid->lines * (lm->y / 2));
		//printf("after x:%d y:%d\n", start->x, start->y);
	}
	else if (rm->x == 0 && lm->y == 0)
	{
		//printf("plan move x=0\n");
		//printf("lmx %d rmy %d\n", lm->x, rm->y);
		//printf("before x:%d y:%d\n", all->pts->pixx, all->pts->pixy);
		start->x = all->pts->pixx + (all->grid->rows * (lm->x / 2));
		start->y = all->pts->pixy + (all->grid->lines * (rm->y / 2));
		//printf("after x:%d y:%d\n", start->x, start->y);
	}
}

/*
parece tar bem, depois confirmar
*/

void	def_start_in(t_all *all, t_matrix *rm, t_matrix *lm, t_matrix *start)
{
	//printf("in\n");
	if (lm->x == (rm->x * (-1)))
	{
		//printf("iso move y\n");
		start->x = all->pts->pixx;
		start->y = all->pts->pixy - (all->grid->lines * (lm->y / 4));
	}
	else if (lm->x == rm->x)
	{
		//printf("iso move x\n");
		//printf("lmx %d rmx %d\n", lm->x, rm->x);
		//printf("before x:%d y:%d\n", all->pts->pixx, all->pts->pixy);
		start->x = all->pts->pixx - (all->grid->rows * (rm->x / 4));
		start->y = all->pts->pixy;
		//printf("after x:%d y:%d\n", start->x, start->y);
	}
	else if (rm->y == 0 && lm->x == 0)
	{
		//printf("plan move y=0\n");
		//printf("lmy %d rmx %d\n", lm->y, rm->x);
		//printf("before x:%d y:%d\n", all->pts->pixx, all->pts->pixy);
		start->x = all->pts->pixx - (all->grid->rows * (rm->x / 4));
		start->y = all->pts->pixy - (all->grid->lines * (lm->y / 4));
		//printf("after x:%d y:%d\n", start->x, start->y);
	}
	else if (rm->x == 0 && lm->y == 0)
	{
		//printf("plan move x=0\n");
		//printf("lmx %d rmy %d\n", lm->x, rm->y);
		//printf("before x:%d y:%d\n", all->pts->pixx, all->pts->pixy);
		start->x = all->pts->pixx - (all->grid->rows * (lm->x / 4));
		start->y = all->pts->pixy - (all->grid->lines * (rm->y / 4));
		//printf("after x:%d y:%d\n", start->x, start->y);
	}
}

/*
. zoom out planar

o segredo para aquele zoom simetrico e perfeito e mudar apenas o y
sendo que, ou o row ou a line vao SER um dos pontos que mexe na
vertical, experimentar mudar na horizontal simetrico a vertical
*/

void	zoom(t_all *all, int order)
{
	t_matrix	*row;
	t_matrix	*line;
	t_matrix	*start;

	row = row_matrix(all->pts, order);
	if (row == NULL)
		return;
	line = line_matrix(all->pts, all->grid, order);
	if (line == NULL)
		return;
	start = malloc(sizeof(t_matrix));
	if (order == 1)
		def_start_in(all, row, line, start);
	else if (order == 2)
		def_start_out(all, row, line, start);
	prep_pts(all, row, line, start, order);
	free(row);
	free(line);
	free(start);
}

/*
void	define_start(t_all *all, int order, t_matrix *rm, t_matrix *lm, t_matrix *start)
{
	if (order == 1)
	{
		if ((lm->x == (rm->x * (-1))) || (lm->x == rm->x))
		{
			start->x = all->pts->pixx;
			start->y = all->pts->pixy - (all->grid->lines * (lm->y / 4));
		}
		else if ((rm->y == 0 && lm->x == 0) || (rm->x == 0 && lm->y == 0))
		{
			start->x = all->pts->pixx - (all->grid->rows * (rm->x / 4));
			start->y = all->pts->pixy - (all->grid->lines * (lm->y / 4));
		}
	}
	else if (order == 2)
	{
		if ((lm->x == (rm->x * (-1))) || (lm->x == rm->x)) //iso
		{
			if (rm->y > 0)
			{
				start->x = all->pts->pixx;
				start->y = all->pts->pixy + (all->grid->lines * (lm->y / 2));
			}
			else if (rm->y <= 0)
			{
				start->x = all->pts->pixx + (all->grid->rows * (rm->x / 2));
				start->y = all->pts->pixy;
			}
		}
		else if ((rm->y == 0 && lm->x == 0) || (rm->x == 0 && lm->y == 0)) //plan
		{
			start->x = all->pts->pixx + (all->grid->rows * (rm->x / 2));
			start->y = all->pts->pixy + (all->grid->lines * (lm->y / 2));
		}
	}
}
}*/