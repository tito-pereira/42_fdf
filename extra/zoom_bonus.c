/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:48:23 by tibarbos          #+#    #+#             */
/*   Updated: 2023/10/20 18:00:01 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

t_matrix	*row_matrix(t_point *pts, int order)
{
	t_matrix	*new;

	new = r_matrix(pts);
	if (new->x * 2 > INT_MAX || new->y * 2 > INT_MAX
		|| (new->x > 0 && new->x / 4 == 0 && order == 2)
		|| (new->y > 0 && new->y / 4 == 0 && order == 2))
	{
		free (new);
		return (NULL);
	}
	if (order == 1)
	{
		new->x *= 2;
		new->y *= 2;
	}
	else if (order == 2)
	{
		new->x = new->x / 2;
		new->y = new->y / 2;
	}
	return (new);
}

t_matrix	*line_matrix(t_point *pts, t_grid *grid, int order)
{
	t_matrix	*new;

	new = l_matrix(pts, grid);
	if (new->x * 2 > INT_MAX || new->y * 2 > INT_MAX
		|| (new->x > 0 && new->x / 4 == 0 && order == 2)
		|| (new->y > 0 && new->y / 4 == 0 && order == 2))
	{
		free (new);
		return (NULL);
	}
	if (order == 1)
	{
		new->x *= 2;
		new->y *= 2;
	}
	else if (order == 2)
	{
		new->x = new->x / 2;
		new->y = new->y / 2;
	}
	return (new);
}

void	start_out(t_all *all, t_matrix *rm, t_matrix *lm, t_matrix *start)
{
	if (lm->x == (rm->x * (-1)))
	{
		start->x = all->pts->pixx;
		start->y = all->pts->pixy + (all->grid->lines * (lm->y / 2));
	}
	else if (lm->x == rm->x)
	{
		start->x = all->pts->pixx + (all->grid->rows * (rm->x / 2));
		start->y = all->pts->pixy;
	}
	else if (rm->y == 0 && lm->x == 0)
	{
		start->x = all->pts->pixx + (all->grid->rows * (rm->x / 2));
		start->y = all->pts->pixy + (all->grid->lines * (lm->y / 2));
	}
	else if (rm->x == 0 && lm->y == 0)
	{
		start->x = all->pts->pixx + (all->grid->rows * (lm->x / 2));
		start->y = all->pts->pixy + (all->grid->lines * (rm->y / 2));
	}
}

void	start_in(t_all *all, t_matrix *rm, t_matrix *lm, t_matrix *start)
{
	if (lm->x == (rm->x * (-1)))
	{
		start->x = all->pts->pixx;
		start->y = all->pts->pixy - (all->grid->lines * (lm->y / 4));
	}
	else if (lm->x == rm->x)
	{
		start->x = all->pts->pixx - (all->grid->rows * (rm->x / 4));
		start->y = all->pts->pixy;
	}
	else if (rm->y == 0 && lm->x == 0)
	{
		start->x = all->pts->pixx - (all->grid->rows * (rm->x / 4));
		start->y = all->pts->pixy - (all->grid->lines * (lm->y / 4));
	}
	else if (rm->x == 0 && lm->y == 0)
	{
		start->x = all->pts->pixx - (all->grid->rows * (lm->x / 4));
		start->y = all->pts->pixy - (all->grid->lines * (rm->y / 4));
	}
}

void	zoom(t_all *all, int order)
{
	t_matrix	*row;
	t_matrix	*line;
	t_matrix	*start;

	row = row_matrix(all->pts, order);
	if (row == NULL)
		return ;
	line = line_matrix(all->pts, all->grid, order);
	if (line == NULL)
		return ;
	start = malloc(sizeof(t_matrix));
	if (order == 1)
		start_in(all, row, line, start);
	else if (order == 2)
		start_out(all, row, line, start);
	prep_pts(all, row, line, start, order);
	free(row);
	free(line);
	free(start);
}
