/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:47:39 by tibarbos          #+#    #+#             */
/*   Updated: 2023/10/24 12:50:58 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

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

void	rotate(t_all *all, int order)
{
	t_trimat	*m;

	m = malloc(sizeof(t_trimat));
	m->s = malloc(sizeof(t_matrix));
	m->r = r_matrix(all->pts);
	m->l = l_matrix(all->pts, all->grid);
	if (order == 1)
		m->s->x = all->pts->pixx + (all->grid->lines * m->l->x);
	if (order == 1)
		m->s->y = (all->pts->pixy - all->pts->pixz) + (all->grid->lines * m->l->y);
	if (order == 2)
		m->s->x = all->pts->pixx + (all->grid->lines * m->r->x);
	if (order == 2)
		m->s->y = all->pts->pixy + (all->grid->lines * m->r->y);
	if (order == 1)
		rot_right(m->r, m->l);
	else if (order == 2)
		rot_left(m->r, m->l);
	prep_pts(all, m, 4);
	free_mat(m);
}
