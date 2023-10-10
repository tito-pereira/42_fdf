#include "fdf.h"

void	choose_matrix(int *mx, int *my, int *now_x, int *now_y)
{
	if (mx > 0)
	{
		(*now_x)++;
		(*mx)--;
	}
	if (mx < 0)
	{
		(*now_x)--;
		(*mx)++;
	}
	if (my > 0)
	{
		(*now_y)++;
		(*my)--;
	}
	if (my < 0)
	{
		(*now_y)--;
		(*my)++;
	}
}

void	draw_str(t_point *a, t_point *b, int *mx, int *my, t_image *img)
{
	int	now_x;
	int	now_y;

	now_x = a->pixx;
	now_y = a->pixy;
	write_image(img, now_x, now_y, WHITE);
	while (mx != 0 || my != 0)
	{
		choose_matrix(&mx, &my, &now_x, &now_y);
		write_image(img, now_x, now_y, WHITE);
	}
}

void	draw_l(t_point *a, t_point *b, t_image *img)// t_grid *g)
{
	int	my;
	int	mx;

    my = b->pixy - a->pixy;
    mx = b->pixx - a->pixx;
	if (mx == 0 || my == 0)
		draw_str(a, b, &mx, &my, img);
	else if (mx == my || (mx * -1) == my || mx == (my * -1))
		draw_str(a, b, &mx, &my, img);
}

/*
criar alguma especie de offset na draw_str()
em que a base e desenhar reto ou diagonais
e tenho uma varivel dinamica de offsets que (consoante a proporçao)
fica com um contador, e quando chega a altura desenha um offset

posso meter (img, x, y, *a, *b) para o write image
e calculo a altura relativa de z e a respetiva cor a partir dai
valores concretos para Z? ou dinamicos? definir mais um parametro
chamado max_height e dividir em grupos iguais, estratos de cor?

desenhar fora dos quadrantes é que é o desafio agora
por causa das proporções

numero de unidades de diferença entre um e outro
é o numero de vezes extra que um vetor vai ter a mais q o outro
e devem ser realizadas de modo equidistante para maior smoothness

void	draw_unvn(t_point *a, t_point *b, t_image *img)
{
	if (mx > 0 && my < 0);
}
*/