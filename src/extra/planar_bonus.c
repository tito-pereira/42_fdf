/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   planar_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:47:21 by tibarbos          #+#    #+#             */
/*   Updated: 2024/08/02 12:14:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf_bonus.h"

t_matrix	*plan_matrix(t_grid *grid)
{
	t_matrix	*pm;

	pm = malloc(sizeof(t_matrix));
	pm->y = 0;
	if (grid->rows > 200)
		pm->x = 2;
	else if (grid->rows > 100 && grid->rows <= 200)
		pm->x = 4;
	else if (grid->rows > 50 && grid->rows <= 100)
		pm->x = 8;
	else if (grid->rows > 25 && grid->rows <= 50)
		pm->x = 16;
	else if (grid->rows <= 25)
		pm->x = 32;
	return (pm);
}

void	planar(t_all *all, int order)
{
	t_trimat	*m;

	m = malloc(sizeof(t_trimat));
	m->r = plan_matrix(all->grid);
	m->l = malloc(sizeof(t_matrix));
	m->l->x = 0;
	m->l->y = 0;
	m->s = malloc(sizeof(t_matrix));
	m->s->x = (WIDTH / 2) - (all->grid->rows / 2) * m->r->x;
	m->s->y = (HEIGHT / 2);
	m->s->y += nmb_module((m->r->x + m->l->x) / 2) * (all->grid->maxz / 2);
	if (m->s->y > 790)
		m->s->y = 790;
	if (order == 1)
		prep_pts(all, m, 5);
	free_mat(m);
}
