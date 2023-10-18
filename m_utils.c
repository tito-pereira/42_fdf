#include "fdf.h"

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

t_heights	*new_heights_node(char **str)
{
	t_heights	*new;

	new = malloc(sizeof(t_heights));
	new->line = str;
	new->next = NULL;
	return (new);
}

t_lines	*new_lines_node(char *str)
{
	t_lines	*new;

	new = malloc(sizeof(t_lines));
	new->line = str;
	new->next = NULL;
	return (new);
}

int	check_file(char *name)
{
	int	i;

	i = 0;
	while (name[i] != '\0')
		i++;
	if (name[i-1] == 'f' && name[i - 2] == 'd' && name[i - 3] == 'f'
		&& name[i - 4] == '.')
		return (1);
	return (0);
}