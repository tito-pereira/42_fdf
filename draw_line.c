#include "fdf.h"

float	slope(t_point *a, t_point *b)
{
	float	slope;

	slope = (b->pixy - a->pixy) / (b->pixx - a->pixx);
	return (slope);
}

void	draw_a_b(t_point *a, t_point *b, float begin, t_image *img)
{
	while (a != b)
	{
		a = a->next;
		if (slope(a, b) == begin)
			write_image(img, a->pixx, a->pixy);
	}
}

void	draw_b_a(t_point *a, t_point *b, float begin, t_image *img)
{
	while (b != a)
	{
		b = b->next;
		if (slope(a, b) == begin)
			write_image(img, b->pixx, b->pixy);
	}
}

void	draw_line(t_point *a, t_point *b, t_image *img)
{
	float	begin;

	begin = slope(a, b);
	if (a->pixy < b->pixy)
		draw_a_b(a, b, begin, img);
	else if (a->pixy > b->pixy)
		draw_b_a(a, b, begin, img);
	else if (a->pixy == b->pixy)
	{
		if (a->pixx > b->pixx)
			draw_b_a(a, b, begin, img);
		else if (a->pixx < b->pixx)
			draw_a_b(a, b, begin, img);
	}
}