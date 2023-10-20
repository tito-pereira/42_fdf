/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_isometric.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:38:01 by tibarbos          #+#    #+#             */
/*   Updated: 2023/10/20 16:47:07 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_matrix(t_grid *grid, int *x, int *y)
{
	float d;

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

void	offset_height(t_all *all, t_matrix *rm, t_matrix *start)
{
	int	off;

	off = nmb_module(rm->x / 2) * (all->grid->maxz / 2);
	if (off > 390)
		off = 390;
	start->y += off;
}

void    isometric(t_all *all, int order)
{
	t_matrix	*mx;
	t_matrix	*my;
	t_matrix	*start;

	mx = malloc(sizeof(t_matrix));
	my = malloc(sizeof(t_matrix));
	start = malloc(sizeof(t_matrix));
	get_matrix(all->grid, &(mx->x), &(mx->y));
	my->x = -1 * mx->x;
	my->y = mx->y;
	start->x = (WIDTH / 2) - ((all->grid->rows / 2) * mx->x);
	start->y = (HEIGHT / 2) - ((all->grid->rows / 2) * mx->y);
	start->x -= (all->grid->lines / 2) * my->x;
	start->y -= (all->grid->lines / 2) * my->y;
	offset_height(all, mx, start);
	if (order == 1)
		prep_pts(all, mx, my, start, 3);
	free(mx);
	free(my);
	free(start);
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
