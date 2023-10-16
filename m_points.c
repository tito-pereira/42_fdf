#include "fdf.h"

t_point	*new_point(t_grid *grid, int row, int line, int total)
{
	t_point	*new;

	new = malloc(sizeof(t_point));
	new->x = row;
	new->y = line;
	new->z = grid->heights[total];
	new->pixx = 0;
	new->pixy = 0;
	new->pixz = (-2 * SCALE * new->z);
	new->next = NULL;
	return (new);
}

void	aux(t_point **pts, t_point **org, t_grid *grid, int line, int *total)
{
	int	row;

	row = 0;
	while (row < grid->rows)
	{
		if (*pts == NULL)
		{
			*pts = new_point(grid, row, line, *total);
			*org = *pts;
		}
		else
		{
			(*pts)->next = new_point(grid, row, line, *total);
			*pts = (*pts)->next;
		}
		row++;
		(*total)++;
	}
}

t_point	*create_points(t_grid *grid)
{
    t_point		*pts;
	t_point		*origin;
	int			total;
	int			line;

	total = 0;
	line = 0;
	pts = NULL;
	while (total < grid->total)
	{
		while (line < grid->lines)
		{
			aux(&pts, &origin, grid, line, &total);
			line++;
		}
	}
	return (origin);
}

/*
colocar heights do int *heights mais o seu respetivo (x, y)
numa linked list t_points

interessam me as linhas e colunas porque tambem quero colocar (x, y)
dentro das linked lists

total = numero de elementos do pointss
while i <= total, create point

coordenadas iniciais
tenho que ajustar consoante o numero de rows e lines

(para dar um hiperfoco)
materia teorica total = 20 (em quantidade)
um só projeto/engenharia = 40 (em quantidade)

é normal desenvolver um hiperfoco gigante num só projeto de engenharia,
com o mesmo esforco q temos para a teoria inteira
devido à cache mental a partir do qual o nosso hiperfoco cresce
por isso que é fundamental uniformizar práticas, técnicas e
nomenclatura no código e na engenharia de software
para ser mais facil transitar de projeto em projeto e rapidamente
perceber o esquema geral de cada código e mais rapidamente entrar
nesse hiperfoco
*/