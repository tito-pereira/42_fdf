#include "fdf.h"

char	**proc_lines(int fd, t_grid *grid)
{
	int	i;
	char	**pts;

	i = 0;
	pts = malloc(sizeof(char **));
	while (pts[i] != NULL)
	{
		while (!pts[i])
			pts[i] = get_next_line(fd, 10000);
		i++;
		grid->lines++;
	}
	return (pts);
}

char	***proc_points(char **lines)
{
	char	***points;
	int	i;

	i = 0;
	points = malloc(sizeof(char ***));
	while (lines[i] != NULL)
	{
		points[i] = ft_split(lines[i]);
		i++;
	}
	return (points);
}

int	count_rows(char **points)
{
	int	i;

	i = 0;
	while (points[i] != NULL)
		i++;
	return (i);
}

int	*proc_heights(char ***points, t_grid *grid)
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
		word = 0
		while (points[line][word] != NULL)
		{
			heights[i] = ft_atoi(points[line][word]);
			i++;
			word++;
		}
		line++;
	}
	return (heights);
}

t_grid	*create_grid(char *arg)
{
	t_grid	*grid;
	int		fd;
	int		i;
	char	***points;
	char	**lines;

	//grid = malloc(sizeof(t_grid));
	grid->heights = NULL;
	grid->rows = 0;
	grid->lines = 0;
	grid->total = 0;
	fd = open("arg");
	lines = proc_lines(fd, grid);
	points = proc_points(lines);
	grid->rows = count_rows(points[0]);
	grid->heights = proc_heights(points, grid);
	return (grid);
}

/*
biblioteca do open e read

get_next_line = char *
loop ate retornar algo
NULL se tiver o file vazio

split, atoi, get_next_line
*/