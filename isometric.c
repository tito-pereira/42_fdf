#include "fdf.h"

void	get_matrix(t_grid *grid, int *x, int *y)
{
	float d;

	d = sqrt(pow(grid->rows, 2) + pow(grid->lines, 2));
	//printf("diagonal points: %f\n", d);
	if (d > 120)
	{
		*x = 2;
		*y = 1;
	}
	else if (d > 60 && d <= 120)
	{
		*x = 4;
		*y = 2;
	}
	else if (d > 30 && d <= 60)
	{
		*x = 8;
		*y = 4;
	}
	else if (d <= 30)
	{
		*x = 16;
		*y = 8;
	}
}

void	print_points(t_point *pts) {
	while (pts != NULL) {
		//printf("x:%d y:%d z:%d px:%d py:%d\n", pts->x, pts->y, pts->z, pts->pixx, pts->pixy);
		pts = pts->next;
	}
}

void	display_lines(t_point *pts, t_image *first)
{
	while (pts->next != NULL)
	{
		draw_line(pts, pts->next, first);
		pts = pts->next;
	}
}

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
		printf("------row %d of %d------\n", row, grid->rows);
		while (line < (grid->lines - 1))
		{
			c = 0;
			printf("fx:%d fy:%d sx:%d sy:%d\n", fst->pixx, fst->pixy, scd->pixx, scd->pixy);
			while (c < grid->rows)
			{
				printf(".");
				scd = scd->next;
				c++;
			}
			printf("\nc:%d\n", c);
			printf("ax:%d ay:%d bx:%d by:%d\n", fst->pixx, fst->pixy, scd->pixx, scd->pixy);
			draw_line(fst, scd, first);
			fst = scd;
			line++;
		}
		row++;
		line = 0;
		pts = pts->next;
	}
}

void    display_iso(t_mlx *mlx, t_point *pts, t_grid *grid, t_image *first)
{
	int	mx;
	int	my;
	int	mxx;
	int	row;
	int	line;
	t_point	*origin;

	mx = 0;
	my = 0;
	row = 0;
	line = 0;
	get_matrix(grid, &mx, &my);
	mxx = -1 * mx;
	//printf("matrixes, x:%d, -x:%d, y:%d\n", mx, mxx, my);
	//draw points
	origin = pts;
	line = 0;
	while (line < grid->lines)
	{
		row = 0;
		while (row < grid->rows)
		{
			pts->pixx = 400 + (line * mxx) + (row * mx);
			pts->pixy = 50 + (line * my) + (row * my) + (2 * pts->z);
			//printf("x:%d y:%d z:%d px:%d py:%d\n", pts->x, pts->y, pts->z, pts->pixx, pts->pixy);
			pts = pts->next;
			row++;
		}
		line++;
	}
	//draw line
	//print_points(origin);
	pts = origin;
	display_lines(pts, first);
	display_rows(pts, first, grid);
	printf("out\n");
	mlx->img = first->ptr;
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}

/*
so tou a desenhar uma coluna
ainda tou a conectar o fim e inicio de linhas

void	display_rows(t_point *pts, t_image *first, t_grid *grid)
{
	int	c;
	int	line;
	t_point	*fst;
	t_point	*scd;

	c = 0;
	line = 0;
	while (line < (grid->lines - 1))
	{
		c = 0;
		//printf("-----\nrow:%d total:%d\n", line, grid->lines);
		fst = pts;
		scd = pts;
		while (c < grid->rows)
		{
			scd = scd->next;
			c++;
		}
		//printf("c:%d\n", c);
		//printf("ax:%d ay:%d bx:%d by:%d\n", fst->pixx, fst->pixy, scd->pixx, scd->pixy);
		draw_line(fst, scd, first);
		pts = scd;
		line++;
	}
}

void	display_lines(t_point *pts, t_image *first, t_grid *grid)
{
	int	line;
	int	row;

	line = 0;
	row = 0;
	while (line < grid->lines)
	{
		row = 0;
		while (row < grid->rows)
		{
			printf("line %d row %d\n", line, row);
			draw_line(pts, pts->next, first);
			pts = pts->next;
			row++;
		}
		pts = pts->next;
		line++;
	}
}
//linha 11 coluna 7 aleatoriamente da erro? my guess is limite de pagina inferior
-----
while (pts->next != NULL)
{
	draw_line(pts, pts->next, first);
	pts = pts->next;
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