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

void	prep_pts(t_point *p, t_grid *g, t_matrix *r, t_matrix *l, t_matrix *s)
{
	int	line;
	int	row;

	line = 0;
	row = 0;
	while (line < g->lines)
	{
		row = 0;
		while (row < g->rows)
		{
			p->pixz = p->pixz;//p->pixz * 2; (-2 * SCALE * p->z)
			p->pixx = s->x + (line * l->x) + (row * r->x); //2 * matrixes
			p->pixy = s->y + (line * l->y) + (row * r->y) + p->pixz;
			p = p->next;
			row++;
		}
		line++;
	}
}

/*while (line < grid->lines)
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