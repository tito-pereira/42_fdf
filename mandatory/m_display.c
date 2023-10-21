/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_display.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:36:18 by tibarbos          #+#    #+#             */
/*   Updated: 2023/10/20 18:49:00 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	disp_rows_aux(int *line, t_point **fst, t_point **scd, t_point **pts)
{
	*fst = *pts;
	*scd = *pts;
	*line = 0;
	*pts = (*pts)->next;
}

void	display_rows(t_point *pts, t_image *first, t_grid *grid)
{
	int		c;
	int		line;
	int		row;
	t_point	*fst;
	t_point	*scd;

	c = 0;
	row = 0;
	line = 0;
	while (row++ < (grid->rows))
	{
		disp_rows_aux(&line, &fst, &scd, &pts);
		while (line++ < (grid->lines - 1))
		{
			c = 0;
			while (c++ < grid->rows)
				scd = scd->next;
			draw_line(fst, scd, first);
			fst = scd;
		}
	}
}

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

void	height_options(t_point *iter, t_trimat *m, int order)
{
	if (order == 1)
		iter->pixz = iter->pixz * 2;
	else if (order == 2)
		iter->pixz = iter->pixz / 2;
	else if (order == 3)
		iter->pixz = (-1 * nmb_module(m->r->x / 2) * iter->z);
	else if (order == 33)
		iter->pixz = (-1 * nmb_module(m->r->x / 2) * iter->z) * 2;
	else if (order == 4)
		iter->pixz = iter->pixz;
	else if (order == 5)
		iter->pixz = (-1 * nmb_module((m->r->x + m->l->x) / 2) * iter->z);
	else if (order == 55)
		iter->pixz = (-1 * nmb_module((m->r->x + m->l->x) / 2) * iter->z) * 2;
	else if (order == 0)
		iter->pixz = 0;
}

void	prep_pts(t_all *a, t_trimat *m, int ord)
{
	int		line;
	int		row;
	t_point	*iter;

	line = 0;
	row = 0;
	iter = a->pts;
	while (line < a->grid->lines)
	{
		row = 0;
		while (row < a->grid->rows)
		{
			height_options(iter, m, ord);
			iter->pixx = m->s->x + (line * m->l->x) + (row * m->r->x);
			iter->pixy = m->s->y + (line * m->l->y) + (row * m->r->y) + iter->pixz;
			iter = iter->next;
			row++;
		}
		line++;
	}
}

/*
t_trimat	*m;
*/