#include "fdf.h"

void	get_matrix(t_grid *grid, int *x, int *y)
{
	float d;

	d = sqrt(pow(grid->rows, 2) + pow(grid->lines, 2));
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

void    display_iso(t_mlx *mlx, t_point *pts, t_grid *grid)
{
	int	mx;
	int	my;
	int	mxx;
	int	i;
	int	j;
	t_point	*origin;

	mx = 0;
	my = 0;
	i = 0;
	j = 0;
	get_matrix(grid, &mx, &my);
	mxx = -1 * mx;
	//draw points
	origin = pts;
	j = 0;
	while (j < grid->lines)
	{
		i = 0;
		while (i < grid->rows)
		{
			pts->pixx = 400 + (j * mxx) + (i * mx);
			pts->pixy = 50 + (j * my) + (i * my) + (2 * pts->z);
			pts = pts->next;
			i++;
		}
		j++;
	}
	//draw line
	pts = origin;
	while (pts->next != NULL)
	{
		draw_line(pts, pts->next, mlx->img);
		pts = pts->next;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}

/*
acabar o draw points, nao sei mudar de linha

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