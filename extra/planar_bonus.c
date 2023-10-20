/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   planar_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:47:21 by tibarbos          #+#    #+#             */
/*   Updated: 2023/10/20 17:47:27 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

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
	t_matrix	*row;
	t_matrix	*line;
	t_matrix	*start;

	row = plan_matrix(all->grid);
	line = malloc(sizeof(t_matrix));
	line->x = 0;
	line->y = 0;
	start = malloc(sizeof(t_matrix));
	start->x = (WIDTH / 2) - (all->grid->rows / 2) * row->x;
	start->y = (HEIGHT / 2);
	start->y += nmb_module((row->x + line->x) / 2) * (all->grid->maxz / 2);
	if (start->y > 790)
		start->y = 790;
	if (order == 1)
		prep_pts(all, row, line, start, 5);
	free(row);
	free(line);
	free(start);
}
