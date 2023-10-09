#include "fdf.h"

t_point	*new_point(t_grid *grid, int x, int y)
{
	t_point	*new;

	new = malloc(sizeof(t_point));
	new->x = x;
	new->y = y;
	new->z = grid->heights[x * y];
	new->pixx = 0;
	new->pixy = 0;
	new->next = NULL;
	return (new);
}
//falta as coordenadas 2D, ainda vou ver como faço

void	aux(t_point **pts, t_grid *grid, int l)
{
	int	r;

	r = 0;
	while (r < grid->rows)
	{
		if (pts == NULL)
			*pts = new_point(grid, r, l);
		else
			(*pts)->next = new_point(grid, r, l);
		*pts = (*pts)->next;
		r++;
	}
}

t_point	*create_points(t_grid *grid)
{
    t_point    *pts;
	int	i;
	int	l;

	i = 0;
	l = 0;
	pts = NULL;
	printf("here\n");
	while (i < grid->total)
	{
		while (l < grid->lines)
		{
			aux(&pts, grid, l);
			l++;
		}
		i++;
	}
	return (pts);
}

/*
total = numero de elementos do pointss
while i <= total, create point

coordenadas iniciais
tenho que ajustar consoante o numero de rows e lines
*/