/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_isometric.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:38:01 by tibarbos          #+#    #+#             */
/*   Updated: 2023/10/23 13:51:40 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_matrix(t_grid *grid, int *x, int *y)
{
	float	d;

	d = sqrt(pow(grid->rows, 2) + pow(grid->lines, 2));
	if (d > 120)
	{
		*x = 2 * SCALE;
		*y = 1 * SCALE;
	}
	else if (d > 60 && d <= 120)
	{
		*x = 4 * SCALE;
		*y = 2 * SCALE;
	}
	else if (d > 30 && d <= 60)
	{
		*x = 8 * SCALE;
		*y = 4 * SCALE;
	}
	else if (d <= 30)
	{
		*x = 16 * SCALE;
		*y = 8 * SCALE;
	}
}

void	offset_height(t_all *all, t_trimat *m)
{
	int	off;

	off = nmb_module(m->r->x / 2) * (all->grid->maxz / 2);
	if (off > 390)
		off = 390;
	m->s->y += off;
}

void	isometric(t_all *all, int order)
{
	t_trimat	*m;

	m = malloc(sizeof(t_trimat));
	m->r = malloc(sizeof(t_matrix));
	m->l = malloc(sizeof(t_matrix));
	m->s = malloc(sizeof(t_matrix));
	get_matrix(all->grid, &(m->r->x), &(m->r->y));
	m->l->x = -1 * m->r->x;
	m->l->y = m->r->y;
	m->s->x = (WIDTH / 2) - ((all->grid->rows / 2) * m->r->x);
	m->s->y = (HEIGHT / 2) - ((all->grid->rows / 2) * m->r->y);
	m->s->x -= (all->grid->lines / 2) * m->l->x;
	m->s->y -= (all->grid->lines / 2) * m->l->y;
	offset_height(all, m);
	if (order == 1)
		prep_pts(all, m, 3);
	free_mat(m);
}

void	new_iso(t_all *all)
{
	t_image	*first;

	first = malloc(sizeof(t_image));
	first->ptr = mlx_new_image(all->mlx->mlx, WIDTH, HEIGHT);
	isometric(all, 1);
	display_lines(all->pts, first, all->grid);
	display_rows(all->pts, first, all->grid);
	all->mlx->img = first->ptr;
	mlx_put_image_to_window(all->mlx->mlx, all->mlx->win, all->mlx->img, 0, 0);
	free (first);
}
