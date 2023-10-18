#include "fdf.h"

t_lines	*proc_lines(int fd, t_grid *grid)
{
	int		i;
	t_lines	*new;
	t_lines	*iter;

	i = 0;
	new = new_lines_node(get_next_line(fd));
	iter = new;
	while (1)
	{
		iter->next = new_lines_node(get_next_line(fd));
		iter = iter->next;
		if (iter->line == NULL)
			break ;
		i++;
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
	fd = open(arg, O_RDONLY);
	lines = proc_lines(fd, grid);
	grid->lines = count_lines(lines);
	points = proc_points(lines);
	grid->rows = count_rows(points->line);
	grid->total = grid->lines * grid->rows;
	grid->heights = proc_heights(points, grid);
	close (fd);
	return (grid);
}

/*void	free_pts(char **pts)
{
	int	i;

	i = 0;
	while (pts[i] != NULL)
	{
		free (pts[i]);
		pts[i] = NULL;
		i++;
	}
}

char	**more_mem(char ***pts, int i)
{
	char	**new;
	int		j;

	j = 0;
	new = malloc((i + 1) * sizeof(char *));
	printf("malloc %d\n", (i + 1));
	while (j < i)
	{
		printf("new loop, j=%d\n", j);
		printf("*pts[%d]:%s\n", j, *pts[j]);
		new[j] = ft_strcpy(*pts[j]);
		printf("new[%d]:%s\n", j, new[j]);
		j++;
	}
	free_pts(*pts);
	*pts = NULL;
	return (new);
}*/

/*int	*proc_heights(char ***points, t_grid *grid)
{
	int	size;
	int	line;
	int	word;
	int	i;
	int	*heights;

	line = 0;
	word = 0;
	i = 0;
	size = grid->rows * grid->lines;
	heights = malloc(size * sizeof(int));
	grid->total = size;
	while (points[line] != NULL)
	{
		word = 0;
		while (points[line][word] != NULL)
		{
			heights[i] = ft_atoi(points[line][word]);
			i++;
			word++;
		}
		line++;
	}
	return (heights);
}*/