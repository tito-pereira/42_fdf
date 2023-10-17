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