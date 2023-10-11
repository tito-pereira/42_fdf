#include "fdf.h"

void	draw_str(t_point *a, t_point *b, int *mx, int *my, t_image *img)
{
	int	now_x;
	int	now_y;

	now_x = a->pixx;
	now_y = a->pixy;
	//write_image(img, now_x, now_y, WHITE);
	while ((*mx) != 0 || (*my) != 0)
	{
		offset_matrix(&mx, &my, &now_x, &now_y);
		write_image(img, now_x, now_y, WHITE);
	}
}

void	draw_unvn_off(t_point *a, t_point *b, int *mx, int *my, t_image *img)
{
	int	now_x;
	int	now_y;
	int	reset;

	now_x = a->pixx;
	now_y = a->pixy;
	reset = count;
	while (mx != 0 || my != 0)
	{
		if (count == 0)
		{
			//straight++;
			straight_matrix(&mx, &my, &now_x, &now_y);
			write_image(img, now_x, now_y, WHITE);
			count = reset;
		}
		else
		{
			//offset++;
			offset_matrix(&mx, &my, &now_x, &now_y);
			write_image(img, now_x, now_y, WHITE);
			count--;
		}
	}
}

void	draw_unvn_str(t_point *a, t_point *b, int *mx, int *my, t_image *img)
{
	int	now_x;
	int	now_y;
	int	reset;

	now_x = a->pixx;
	now_y = a->pixy;
	reset = count;
	while (mx != 0 || my != 0)
	{
		if (count == 0)
		{
			//offset++;
			offset_matrix(&mx, &my, &now_x, &now_y);
			write_image(img, now_x, now_y, WHITE);
			count = reset;
		}
		else
		{
			//straight++;
			straight_matrix(&mx, &my, &now_x, &now_y);
			write_image(img, now_x, now_y, WHITE);
			count--;
		}
	}
}

void	draw_l(t_point *a, t_point *b, t_image *img)// t_grid *g)
{
	int	my;
	int	mx;
	int	total;
	int	offset;
	int	straight;
	int	count;

    my = b->pixy - a->pixy;
    mx = b->pixx - a->pixx;
	total = check_total(my, my);
	offset = check_offset(mx, my);
	straight = total - offset;
	count = check_count(offset, straight); // offset / straight; check_total, o maior em cima
	write_image(img, a->pixx, a->pixy, WHITE); //pontos inicial + coincidentes
	if (count == 0)
		draw_str(a, b, &mx, &my, img);
	else
	{
		if (straight > offset)
			draw_unvn_str(a, b, &mx, &my, img); //str dominant
		else if (offset > straight)
			draw_unvn_off(a, b, &mx, &my, img); //off dominant
	}
}
/*if count == 0, draw tudo str
so desenha offsets ou so straights
if off=0 || mx ou my == 0
else, variar entre draw_off e draw str
na ordem da proporcao

vai acabar por encaixar tudo na mesma funcao
if offset / str == 0, draw tudo str*/

/*
por o count dentro das draw_unvn

posso meter (img, x, y, *a, *b) para o write image
e calculo a altura relativa de z e a respetiva cor a partir dai
valores concretos para Z? ou dinamicos? definir mais um parametro
chamado max_height e dividir em grupos iguais, estratos de cor?
*/