/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_matrix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:38:34 by tibarbos          #+#    #+#             */
/*   Updated: 2024/08/02 12:16:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	offset_matrix(t_matrix *m, int *now_x, int *now_y)
{
	if (m->x > 0)
	{
		(*now_x)++;
		m->x--;
	}
	if (m->x < 0)
	{
		(*now_x)--;
		m->x++;
	}
	if (m->y > 0)
	{
		(*now_y)++;
		m->y--;
	}
	if (m->y < 0)
	{
		(*now_y)--;
		m->y++;
	}
}

void	straight_matrix(t_matrix *m, int *now_x, int *now_y)
{
	if (nmb_module(m->x) > nmb_module(m->y))
	{
		(*now_x) += signal(m->x);
		m->x -= signal(m->x);
	}
	else if (nmb_module(m->y) > nmb_module(m->x))
	{
		(*now_y) += signal(m->y);
		m->y -= signal(m->y);
	}
}

int	check_total(int mx, int my)
{
	int	total;

	total = 0;
	if (nmb_module(mx) > nmb_module(my))
		total = nmb_module(mx);
	else if (nmb_module(my) > nmb_module(mx))
		total = nmb_module(my);
	return (total);
}

int	check_offset(int mx, int my)
{
	int	offset;

	offset = 0;
	if (nmb_module(mx) >= nmb_module(my))
		offset = nmb_module(my);
	else if (nmb_module(my) > nmb_module(mx))
		offset = nmb_module(mx);
	return (offset);
}

t_count	*check_count(int offset, int straight)
{
	t_count	*count;
	t_count	*first;
	int		rest;

	count = new_count(0);
	first = count;
	rest = 0;
	if (straight > offset)
		f_swap(&offset, &straight);
	if (offset == 0 || straight == 0)
		return (count);
	if (offset >= straight)
	{
		count->cnt = offset / straight;
		count->reset = count->cnt;
		rest = offset % straight;
		while (rest != 0)
		{
			count->nxt = new_count((offset / rest));
			count = count->nxt;
			rest = offset % rest;
		}
	}
	return (first);
}
