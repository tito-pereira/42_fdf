#include "fdf.h"

float	slope(t_point *a, t_point *b)
{
	float	slope;
	float	up;
	float	down;

	up = (b->pixy - a->pixy);
	//printf("(%d - %d) up:%f\n", b->pixy, a->pixy, up);
	down = (b->pixx - a->pixx);
	//printf("(%d - %d) down:%f\n", b->pixx, a->pixx, down);
	slope = up / down;
	//printf("slope: %f\n", slope);
	return (slope);
}

void	draw_a_b(t_point *a, t_point *b, float begin, t_image *img)//t_grid *g)
{
	int	now_x;
	int	now_y;

	now_x = a->pixx;
	now_y = a->pixy;
	//printf("begin:%f, x:%d, y:%d\n", begin, now_x, now_y);
	while (now_y <= b->pixy)
	{
		while ((now_y != b->pixy) && (now_x <= 600))
		{
			//printf("while 1\n");
			if (slope(a, b) == begin) {
				//printf("will write\n");
				write_image(img, now_x, now_y, WHITE);
				//printf("written\n");
			}
			now_x++;
		}
		while ((now_y == b->pixy) && (now_x <= b->pixx))
		{
			//printf("while 2\n");
			if (slope(a, b) == begin)
				write_image(img, now_x, now_y, WHITE);
			now_x++;
		}
		now_y++;
		now_x = 0;
	}
}

void	draw_b_a(t_point *a, t_point *b, float begin, t_image *img)// t_grid *g)
{
	int	now_x;
	int	now_y;

	now_x = b->pixx;
	now_y = b->pixy;
	while (now_y <= a->pixy)
	{
		while ((now_y != a->pixy) && (now_x <= 600))
		{
			if (slope(a, b) == begin)
				write_image(img, now_x, now_y, WHITE);
			now_x++;
		}
		while ((now_y == a->pixy) && (now_x <= a->pixx))
		{
			if (slope(a, b) == begin)
				write_image(img, now_x, now_y, WHITE);
			now_x++;
		}
		now_y++;
		now_x = 0;
	}
}

void	draw_line(t_point *a, t_point *b, t_image *img)// t_grid *g)
{
	float	begin;

	//printf("draw\n");
	begin = slope(a, b);
	if (a->pixy < b->pixy) {
		//printf("if\n");
		draw_a_b(a, b, begin, img);
	}
	else if (a->pixy > b->pixy) {
		//printf("else\n");
		draw_b_a(a, b, begin, img);
	}
	else if (a->pixy == b->pixy)
	{
		if (a->pixx > b->pixx) {
			//printf("if 2\n");
			draw_b_a(a, b, begin, img);
		}
		else if (a->pixx < b->pixx) {
			//printf("else 2\n");
			draw_a_b(a, b, begin, img);
		}
	}
}

/*
mudar o slope de t_points para coordenadas

eu tou a ir de ponto a ponto, em vez de pixel a pixel

------------
eu tou a conetar as linhas so
e a conetar o fim de uma linha ao fim da proxima
tenho que:
- conetar linhas, mas cortar as conexoes do fim
- conetar colunas
acho que depois tambem posso ajustar isto
------------
void	draw_a_b(t_point *a, t_point *b, float begin, t_image *img)
{
	while (a != b)
	{
		a = a->next;
		if (slope(a, b) == begin)
			write_image(img, a->pixx, a->pixy, WHITE);
	}
}

void	draw_b_a(t_point *a, t_point *b, float begin, t_image *img)
{
	while (b != a)
	{
		b = b->next;
		if (slope(a, b) == begin)
			write_image(img, b->pixx, b->pixy, WHITE);
	}
}

----------------

void	draw_a_b(t_point *a, t_point *b, float begin, t_image *img)
{
	int	now_x;
	int	now_y;

	now_x = a->pixx;
	now_y = a->pixy;
	while (now_y <= b->pixy)
	{
		while ((now_y != b->pixy) && (now_x <= rows))
		{
			if (slope(a, b) == begin)
				write_image(img, now_x, now_y, WHITE);
			now_x++;
		}
		while ((now_y == b->pixy) && (now_x <= b->pixx))
		{
			if (slope(a, b) == begin)
				write_image(img, now_x, now_y, WHITE);
			now_x++;
		}
		now_y++;
		now_x = 0;
	}
}

	now_x = x inicial (a->pixx); (x final, b->pixx)
	now_y = y inicial (a->pixy); (y final, b->pixy)
*/