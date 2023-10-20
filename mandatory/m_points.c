/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_points.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:39:00 by tibarbos          #+#    #+#             */
/*   Updated: 2023/10/20 15:39:04 by tibarbos         ###   ########.fr       */
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

void	aux(t_point **pts, t_point **org, t_grid *grid, int line, int *total)
{
	int	row;

	row = 0;
	while (row < grid->rows)
	{
		if (*pts == NULL)
		{
			*pts = new_point(grid, row, line, *total);
			*org = *pts;
		}
		else
		{
			(*pts)->next = new_point(grid, row, line, *total);
			*pts = (*pts)->next;
		}
		row++;
		(*total)++;
	}
}

t_point	*create_points(t_grid *grid)
{
    t_point		*pts;
	t_point		*origin;
	int			total;
	int			line;

	total = 0;
	line = 0;
	pts = NULL;
	while (total < grid->total)
	{
		while (line < grid->lines)
		{
			aux(&pts, &origin, grid, line, &total);
			line++;
		}
	}
	return (origin);
}
