/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_draw_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:36:52 by tibarbos          #+#    #+#             */
/*   Updated: 2023/10/23 15:46:46 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_str(t_draw *d)
{
	int	now_x;
	int	now_y;

	now_x = d->a->pixx;
	now_y = d->a->pixy;
	while (d->m->x != 0 || d->m->y != 0)
	{
		offset_matrix(d->m, &now_x, &now_y);
		write_image(d->img, now_x, now_y, d->color);
	}
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
		{
			offset_matrix(d->m, &now_x, &now_y);
			write_image(d->img, now_x, now_y, d->color);
			if (count->cnt > 0)
				(count->cnt)--;
			chk_pos_cntrs(count);
		}
	}
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
		{
			straight_matrix(d->m, &now_x, &now_y);
			write_image(d->img, now_x, now_y, d->color);
			if (count->cnt > 0)
				(count->cnt)--;
			chk_pos_cntrs(count);
		}
	}
}

int	define_color(t_point *a, t_point *b)
{
	int	medium;

	medium = (a->z + b->z) / 2;
	if (medium <= 0)
		return (LBLUE);
	else if (medium > 0 && medium < 5)
		return (YELLOW);
	else if (medium >= 5 && medium < 30)
		return (GREEN);
	else if (medium >= 30 && medium < 80)
		return (BROWN);
	return (WHITE);
}

t_draw	*create_draw(t_point *a, t_point *b, t_image *img)
{
	t_draw	*d;

	d = malloc(sizeof(t_draw));
	d->a = a;
	d->img = img;
	d->m = malloc(sizeof(t_matrix));
	d->color = define_color(a, b);
	d->m->y = b->pixy - a->pixy;
	d->m->x = b->pixx - a->pixx;
	write_image(d->img, a->pixx, a->pixy, d->color);
	return (d);
}

void	draw_line(t_point *a, t_point *b, t_image *img)
{
	t_draw		*d;
	int			total;
	int			offset;
	int			straight;
	t_count		*count;

	d = create_draw(a, b, img);
	total = check_total(d->m->x, d->m->y);
	offset = check_offset(d->m->x, d->m->y);
	straight = total - offset;
	count = check_count(offset, straight);
	if (count->cnt == 0)
		draw_str(d);
	else
	{
		if (straight >= offset)
			draw_unvn_str(d, count);
		else if (offset >= straight)
			draw_unvn_off(d, count);
	}
	free(d->m);
	free(d);
	free_count(count);
}

/*
void	draw_line(t_point *a, t_point *b, t_image *img)
{
	t_draw		*d;
	int			total;
	int			offset;
	int			straight;
	t_count		*count;

	d = create_draw(a, img);
	d->a = a;
	d->img = img;
	d->m = malloc(sizeof(t_matrix));
	d->color = define_color(a, b);
	d->m->y = b->pixy - a->pixy;
	d->m->x = b->pixx - a->pixx;
	total = check_total(d->m->x, d->m->y);
	offset = check_offset(d->m->x, d->m->y);
	straight = total - offset;
	count = check_count(offset, straight);
	write_image(d->img, a->pixx, a->pixy, d->color);
	if (count->cnt == 0)
		draw_str(d);
	else
	{
		if (straight >= offset)
			draw_unvn_str(d, count);
		else if (offset >= straight)
			draw_unvn_off(d, count);
	}
	free(d->m);
	free(d);
	free_count(count);
}
*/
