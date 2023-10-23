/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_draw_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:53:47 by tibarbos          #+#    #+#             */
/*   Updated: 2023/10/23 16:25:06 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	off_aux(t_draw *d, t_count *count, int *now_x, int *now_y)
{
	offset_matrix(d->m, now_x, now_y);
	write_image(d->img, *now_x, *now_y, d->color);
	if (count->cnt > 0)
		(count->cnt)--;
	chk_pos_cntrs(count);
}

void	draw_unvn_off(t_draw *d, t_count *count)
{
	int	now_x;
	int	now_y;

	now_x = d->a->pixx;
	now_y = d->a->pixy;
	while (d->m->x != 0 || d->m->y != 0)
	{
		if (count->cnt == 0)
		{
			straight_matrix(d->m, &now_x, &now_y);
			write_image(d->img, now_x, now_y, d->color);
			if (count->cnt == 0)
				count->cnt = count->reset;
			chk_pos_cntrs(count);
		}
		if (chk_zero_cntrs(count) == 1)
		{
			offset_matrix(d->m, &now_x, &now_y);
			write_image(d->img, now_x, now_y, d->color);
		}
		else
			off_aux(d, count, &now_x, &now_y);
	}
}

void	str_aux(t_draw *d, t_count *count, int *now_x, int *now_y)
{
	straight_matrix(d->m, now_x, now_y);
	write_image(d->img, *now_x, *now_y, d->color);
	if (count->cnt > 0)
		(count->cnt)--;
	chk_pos_cntrs(count);
}

void	draw_unvn_str(t_draw *d, t_count *count)
{
	int	now_x;
	int	now_y;

	now_x = d->a->pixx;
	now_y = d->a->pixy;
	while (d->m->x != 0 || d->m->y != 0)
	{
		if (count->cnt == 0)
		{
			offset_matrix(d->m, &now_x, &now_y);
			write_image(d->img, now_x, now_y, d->color);
			if (count->cnt == 0)
				count->cnt = count->reset;
			chk_pos_cntrs(count);
		}
		if (chk_zero_cntrs(count) == 1)
		{
			straight_matrix(d->m, &now_x, &now_y);
			write_image(d->img, now_x, now_y, d->color);
		}
		else
			str_aux(d, count, &now_x, &now_y);
	}
}
