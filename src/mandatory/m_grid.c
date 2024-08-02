/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_grid.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:37:42 by tibarbos          #+#    #+#             */
/*   Updated: 2024/08/02 12:16:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

t_lines	*proc_lines(int fd, t_grid *grid)
{
	t_lines	*new;
	t_lines	*iter;

	new = new_lines_node(get_next_line(fd));
	iter = new;
	if (new->line)
		grid->lines++;
	while (1)
	{
		iter->next = new_lines_node(get_next_line(fd));
		iter = iter->next;
		if (iter->line == NULL)
			break ;
		grid->lines++;
	}
	return (new);
}

t_heights	*proc_points(t_lines *lines)
{
	t_heights	*points;
	t_heights	*iter;

	points = new_heights_node(ft_split(lines->line, ' '));
	lines = lines->next;
	iter = points;
	while (lines->line != NULL)
	{
		iter->next = new_heights_node(ft_split(lines->line, ' '));
		iter = iter->next;
		lines = lines->next;
	}
	return (points);
}

int	*proc_heights(t_heights *points, t_grid *grid)
{
	int	*heights;
	int	word;
	int	total;

	word = 0;
	total = 0;
	heights = malloc(grid->total * sizeof(int));
	while (points != NULL)
	{
		word = 0;
		while (points->line[word] != NULL)
		{
			heights[total] = ft_atoi(points->line[word]);
			if (heights[total] > grid->maxz)
				grid->maxz = heights[total];
			word++;
			total++;
		}
		points = points->next;
	}
	return (heights);
}

t_grid	*create_grid(char *arg)
{
	t_grid		*grid;
	int			fd;
	t_heights	*points;
	t_lines		*lines;

	grid = malloc(sizeof(t_grid));
	grid->heights = NULL;
	grid->rows = 0;
	grid->lines = 0;
	grid->total = 0;
	grid->maxz = 0;
	fd = open(arg, O_RDONLY);
	lines = proc_lines(fd, grid);
	points = proc_points(lines);
	grid->rows = count_rows(points->line);
	grid->total = grid->lines * grid->rows;
	grid->heights = proc_heights(points, grid);
	close (fd);
	free_grid(points, lines);
	return (grid);
}
