#include "fdf.h"

void	display_rows(t_point *pts, t_image *first, t_grid *grid)
{
	int	c;
	int	line;
	int	row;
	t_point	*fst;
	t_point	*scd;

	c = 0;
	row = 0;
	line = 0;
	while (row < (grid->rows))
	{
		fst = pts;
		scd = pts;
		while (line < (grid->lines - 1))
		{
			c = 0;
			while (c < grid->rows)
			{
				scd = scd->next;
				c++;
			}
			draw_line(fst, scd, first);
			fst = scd;
			line++;
		}
		row++;
		line = 0;
		pts = pts->next;
	}
}
//experimentar while ++line, while ++c, ou c++ etc

void	display_lines(t_point *pts, t_image *first, t_grid *grid)
{
	int	line;
	int	row;

	line = 0;
	row = 1;
	while (pts != NULL)
	{
		row = 1;
		while (row < grid->rows)
		{
			draw_line(pts, pts->next, first);
			pts = pts->next;
			row++;
		}
		pts = pts->next;
		line++;
	}
}

void	height_options(t_point *iter, int order)
{
	if (order == 1)
		iter->pixz = iter->pixz * 2;
	else if (order == 2)
		iter->pixz = iter->pixz / 2;
	else if (order == 3)
		iter->pixz = (-2 * SCALE * iter->z);
	else if (order == 4)
	{
		if (iter->pixz == 0)
			iter->pixz = (-2 * SCALE * iter->z);
		else
			iter->pixz = iter->pixz;
	}
	else if (order == 5)
		iter->pixz = 0;
}

void	prep_pts(t_all *a, t_matrix *r, t_matrix *l, t_matrix *s, int order)
{
	int	line;
	int	row;
	t_point	*iter;

	line = 0;
	row = 0;
	iter = a->pts;
	while (line < a->grid->lines)
	{
		row = 0;
		while (row < a->grid->rows)
		{
			height_options(iter, order);
			iter->pixx = s->x + (line * l->x) + (row * r->x);
			iter->pixy = s->y + (line * l->y) + (row * r->y) + iter->pixz;
			iter = iter->next;
			row++;
		}
		line++;
	}
}

//change display aqui?

//p->pixz * 2; (-2 * SCALE * p->z)
//if 1, *2, if 2, /2, if 3, ==
/*if (order == 1 || order == 0)
	iter->pixz = iter->pixz * 2 * order;*/
//no entanto preciso de uma order reset para voltar do zero ao isometrico
//ou apenas faço pixy = ... - (pixz) e o z mantem o seu valor e so muda
//ou acresentar um if para o pixy q nao acrescenta o pixz

/*
para altura nula
order 1 || order 0
iter * 2 * order; (resulta tanto para 1 como para zero)

while (line < grid->lines)
{
	row = 0;
	while (row < grid->rows)
	{
		pts->pixz = (-2 * SCALE * pts->z);
		pts->pixx = (WIDTH / 2) + (line * mxx) + (row * mx);
		pts->pixy = (HEIGHT / 4) + (line * my) + (row * my) + pts->pixz;
		//printf("x:%d y:%d z:%d px:%d py:%d\n", pts->x, pts->y, pts->z, pts->pixx, pts->pixy);
		pts = pts->next;
		row++;
	}
	line++;
}*/

/*
void	display_lines(t_point *pts, t_image *first, t_grid *grid)
{
	int	line;
	int	row;

	line = 0;
	row = 1;
	while (pts != NULL)// (line < grid->lines)
	{
		//printf("line %d\n", line);
		row = 1;
		while (row < grid->rows)
		{
			//printf("row %d\n", row);
			//printf("from %d %d to %d %d\n", pts->pixx, pts->pixy, pts->next->pixx, pts->next->pixy);
			draw_line(pts, pts->next, first);
			pts = pts->next;
			row++;
		}
		pts = pts->next;
		line++;
	}
}
//acho que ta a dar

void	display_rows(t_point *pts, t_image *first, t_grid *grid)
{
	int	c;
	int	line;
	int	row;
	t_point	*fst;
	t_point	*scd;

	c = 0;
	row = 0;
	line = 0;
	while (row < (grid->rows))
	{
		fst = pts;
		scd = pts;
		//printf("------row %d of %d------\n", row, grid->rows);
		while (line < (grid->lines - 1))
		{
			c = 0;
			//printf("fx:%d fy:%d sx:%d sy:%d\n", fst->pixx, fst->pixy, scd->pixx, scd->pixy);
			while (c < grid->rows)
			{
				//printf(".");
				scd = scd->next;
				c++;
			}
			//printf("\nc:%d\n", c);
			//printf("ax:%d ay:%d bx:%d by:%d\n", fst->pixx, fst->pixy, scd->pixx, scd->pixy);
			draw_line(fst, scd, first);
			fst = scd;
			line++;
		}
		row++;
		line = 0;
		pts = pts->next;
	}
}*/