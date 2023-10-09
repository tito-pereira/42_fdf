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
	char	**pts;
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

char	***proc_points(t_lines	*lines)
{
	char	***points;
	int	i;

	i = 0;
	points = malloc(sizeof(char ***));
	while (lines[i] != NULL)
	{
		points[i] = ft_split(lines[i], ' ');
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
}

void	print_lines(char **lines) {
	printf("hey\n");
	printf("%s\n", lines[0]);
	//for (int i = 0; lines[i] != NULL; i++)
		//printf("line[i]:%s\n", lines[i]);
}

t_grid	*create_grid(char *arg)
{
	t_grid	*grid;
	int		fd;
	char	***points;
	char	**lines;

	grid = malloc(sizeof(t_grid));
	grid->heights = NULL;
	grid->rows = 0;
	grid->lines = 0;
	grid->total = 0;
	fd = open(arg, O_RDONLY);
	printf("file opened, fd:%d\n", fd);
	lines = proc_lines(fd, grid);
	printf("lines procced\n");
	print_lines(lines);
	points = proc_points(lines);
	printf("points procced\n");
	grid->rows = count_rows(points[0]);
	printf("rows:%d, lines:%d\n", grid->rows, grid->lines);
	grid->heights = proc_heights(points, grid);
	return (grid);
}