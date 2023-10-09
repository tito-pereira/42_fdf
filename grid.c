#include "fdf.h"

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

t_lines	*new_lines_node(char *str)
{
	t_lines	*new;

	new = malloc(sizeof(t_lines));
	new->line = str;
	new->next = NULL;
	return (new);
}

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
//funcao malloc retorna pointer, so podes algo=malloc
//se algo for um pointer. nao pode ser int ou char

t_heights	*new_heights_node(char **str)
{
	t_heights	*new;

	new = malloc(sizeof(t_heights));
	new->line = str;
	new->next = NULL;
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

int	count_rows(char **points)
{
	int	i;

	i = 0;
	while (points[i] != NULL)
		i++;
	return (i);
}

int	count_lines(t_lines *lines)
{
	int	i;

	i = 0;
	while (lines != NULL)
	{
		lines = lines->next;
		i++;
	}
	return (i);
}

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

void	print_heights(t_grid *grid) {
	int	i = 0;
	for (int l = 0; l < grid->lines; l++) {
		for (int r = 0; r < grid->rows; r++) {
			printf("%d, ", grid->heights[i]);
			i++;
		}
		printf("\n");
	}
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
	//printf("file opened, fd:%d\n", fd);
	lines = proc_lines(fd, grid);
	grid->lines = count_lines(lines);
	//printf("lines procced:%d\n", grid->lines);
	points = proc_points(lines);
	grid->rows = count_rows(points->line);
	grid->total = grid->lines * grid->rows;
	//printf("points procced:%d\n", grid->rows);
	grid->heights = proc_heights(points, grid);
	//print_heights(grid);
	return (grid);
}