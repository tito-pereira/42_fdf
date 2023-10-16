#include "fdf.h"

void	get_matrix(t_grid *grid, int *x, int *y)
{
	float d;

	d = sqrt(pow(grid->rows, 2) + pow(grid->lines, 2));
	if (d > 120)
	{
		*x = 2 * SCALE;
		*y = 1 * SCALE;
	}
	else if (d > 60 && d <= 120)
	{
		*x = 4 * SCALE;
		*y = 2 * SCALE;
	}
	else if (d > 30 && d <= 60)
	{
		*x = 8 * SCALE;
		*y = 4 * SCALE;
	}
	else if (d <= 30)
	{
		*x = 16 * SCALE;
		*y = 8 * SCALE;
	}
}

void    isometric(t_all *all, int order)
{
	t_matrix	*mx;
	t_matrix	*my;
	t_matrix	*start;

	mx = malloc(sizeof(t_matrix));
	my = malloc(sizeof(t_matrix));
	start = malloc(sizeof(t_matrix));
	get_matrix(all->grid, &(mx->x), &(mx->y));
	my->x = -1 * mx->x;
	my->y = mx->y;
	start->x = (WIDTH / 2);
	start->y = (HEIGHT / 4);
	if (order == 1)
		prep_pts(all, mx, my, start, 3);
	free(mx);
	free(my);
	free(start);
}

void	new_iso(t_all *all, t_image *first)
{
	isometric(all, 1);
	display_lines(all->pts, first, all->grid);
	display_rows(all->pts, first, all->grid);
	all->mlx->img = first->ptr;
	mlx_put_image_to_window(all->mlx->mlx, all->mlx->win, all->mlx->img, 0, 0);
}

void	do_iso(t_all *all) //change display (isometric, 1)
{
	t_image	*new;

	new = malloc(sizeof(t_image));
	new->ptr = mlx_new_image(all->mlx->mlx, WIDTH, HEIGHT);
	isometric(all, 1);
	display_lines(all->pts, new, all->grid);
	display_rows(all->pts, new, all->grid);
	mlx_put_image_to_window(all->mlx->mlx, all->mlx->win, new->ptr, 0, 0);
	mlx_destroy_image(all->mlx->mlx, all->mlx->img);
	all->mlx->img = new->ptr;
}

/*

void	do_plan(t_all *all)
{
	t_image	*new;

	new = malloc(sizeof(t_image));
	new->ptr = mlx_new_image(all->mlx->mlx, WIDTH, HEIGHT);
	planar(all);
	display_lines(all->pts, new, all->grid);
	display_rows(all->pts, new, all->grid);
	mlx_put_image_to_window(all->mlx->mlx, all->mlx->win, new->ptr, 0, 0);
	mlx_destroy_image(all->mlx->mlx, all->mlx->img);
	all->mlx->img = new->ptr;
}

void    display_planar(t_all *all, t_image *first)
{
	t_matrix	*mx;
	t_matrix	*my;
	t_matrix	*start;

	mx = malloc(sizeof(t_matrix));
	my = malloc(sizeof(t_matrix));
	start = malloc(sizeof(t_matrix));
	mx->x = 1;
	mx->y = 1;
	get_matrix(all->grid, &(mx->x), &(mx->y));
	my->x = -1 * mx->x;
	my->y = mx->y;
	start->x = (WIDTH / 5);
	start->y = (HEIGHT / 5);
	prep_pts(all, mx, my, start, 3);
	display_lines(all->pts, first, all->grid);
	display_rows(all->pts, first, all->grid);
	all->mlx->img = first->ptr;
	mlx_put_image_to_window(all->mlx->mlx, all->mlx->win, all->mlx->img, 0, 0);
	free(mx);
	free(my);
	free(start);
}
---------------------------
void	display_rows(t_point *pts, t_image *first, t_grid *grid)
{
	int	c;
	int	line;
	int	row;
	t_point	*fst;
	t_point	*scd;

	c = 0;
	row = 0;
	line = 0;
	while (row < (grid->rows))
	{
		fst = pts;
		scd = pts;
		while (line < (grid->lines - 1))
		{
			c = 0;
			while (c < grid->rows)
			{
				//printf(".");
				scd = scd->next;
				c++;
			}
			draw_line(fst, scd, first);
			fst = scd;
			line++;
		}
		row++;
		line = 0;
		pts = pts->next;
	}
}

void	display_lines(t_point *pts, t_image *first, t_grid *grid)
{
	int	line;
	int	row;
	//t_point	*fst;

	line = 0;
	row = 0;
	while (line < grid->lines)
	{
		row = 0;
		fst = pts;
		while (row < grid->rows)
		{
			pts = pts->next;
			draw_line(pts, pts->next, first);
			row++;
		}
		pts = pts->next;
		line++;
	}
}

//linha 11 coluna 7 aleatoriamente da erro? my guess is limite de pagina inferior
-----
void	display_lines(t_point *pts, t_image *first)
{
	while (pts->next != NULL)
	{
		draw_line(pts, pts->next, first);
		pts = pts->next;
	}
}

nao sei se escrevo as coordenadas aqui ou no put points
se quero reutilizar esta funçao nos eventos, tenho que colocar aqui

mlx para criar e pushar imagem
points para cords
grid para total i guess, ou line/rows

ponto inicial? meio ecra?
vou usar 2:1, mas com que valores em concreto?

valor minimo é o 2:1 (para mapas mt grandes) e se exceder temos pena
fica fora do frame
tenho 800v600? faco entre 600v500
600 / rows
600 tem que ocupar duma ponta a outra

unidade minima isometrica 3x5 pixeis
2-5
x-600 2*600 / 5
5 pixeis = 2 pontos da grid
600 pixeis = 240 pontos da grid
300 pixeis = 120 pontos da grid
150 pixeis = 60 pontos da grid
75 pixeis = 30 pontos da grid

tier 1: >240 pontos diagonais (2:1)
tier 2: 120-240 (4:2) ou (2:1)
tier 3: 60-120 (8:4) ou (4:2)
tier 4: 30-60 (16:8) ou (8:4)
tier 5: <30 (32:16) ou (16:8)
(2, 4, 6, 8, 10) nah
em vez de dobros, é so acrescentar mais vetores xd

ponto partida?
vou meter 400, 50 i guess, depois mudo

meti, a cada unidade de altura, dois pixeis para cima. testar
*/

/*
display iso pode servir tambem como evento, premir tecla "i"
da reset na imagem e zooms e volta a meter as coordenadas isometricas
iniciais
ou nao, se for dificil demais
*/