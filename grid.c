#include "fdf.h"

char	**more_mem(char ***pts, int i)
{
	char	**new;
	int		j;

	j = 0;
	new = malloc((i + 1) * sizeof(char *));
	while (j <= i)
	{
		new[i] = ft_strcpy(*pts[i]);
		j++;
	}
	printf("new[i]:%s\n", new[i]);
	free(*pts);
	*pts = NULL;
	return (new);
}

char	**proc_lines(int fd, t_grid *grid)
{
	int		i;

	char	**pts;

	i = 0;
	pts = malloc(sizeof(char *));
	while (1)
	{
		printf("loop %d\n", i);
		pts[i] = get_next_line(fd);
		printf("line%d: %s\n", i, pts[i]);
		if (pts[i] == NULL)
			break ;
		i++;
		grid->lines++;
		pts = more_mem(&pts, i);
	}
	return (pts);
}
//funcao malloc retorna pointer, so podes algo=malloc
//se algo for um pointer. nao pode ser int ou char

char	***proc_points(char **lines)
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