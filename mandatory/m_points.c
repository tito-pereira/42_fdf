/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_points.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:39:00 by tibarbos          #+#    #+#             */
/*   Updated: 2023/10/20 18:55:42 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	*new_point(t_grid *grid, int row, int line, int total)
{
	t_point	*new;

	new = malloc(sizeof(t_point));
	new->x = row;
	new->y = line;
	new->z = grid->heights[total];
	new->pixx = 0;
	new->pixy = 0;
	new->pixz = 0;
	new->next = NULL;
	return (new);
}

void	aux(t_point **pts, t_point **org, t_grid *grid, t_matrix *totline)
{
	int	row;

	row = 0;
	while (row < grid->rows)
	{
		if (*pts == NULL)
		{
			*pts = new_point(grid, row, totline->y, totline->x);
			*org = *pts;
		}
		else
		{
			(*pts)->next = new_point(grid, row, totline->y, totline->x);
			*pts = (*pts)->next;
		}
		row++;
		totline->x++;
	}
}

t_point	*create_points(t_grid *grid)
{
	t_point		*pts;
	t_point		*origin;
	t_matrix	*totline;

	totline = malloc(sizeof(t_matrix));
	totline->x = 0;
	totline->y = 0;
	pts = NULL;
	while (totline->x < grid->total)
	{
		while (totline->y < grid->lines)
		{
			aux(&pts, &origin, grid, totline);
			totline->y++;
		}
	}
	free (totline);
	return (origin);
}
