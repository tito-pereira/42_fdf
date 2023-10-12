#include "fdf.h"

void	draw_str(t_point *a, t_matrix *m, t_image *img)
{
	int	now_x;
	int	now_y;

	now_x = a->pixx;
	now_y = a->pixy;
	//write_image(img, now_x, now_y, WHITE);
	while (m->x != 0 || m->y != 0)
	{
		printf("off mx:%d my:%d\noff\n", m->x, m->y);
		offset_matrix(m, &now_x, &now_y);
		write_image(img, now_x, now_y, WHITE);
	}
}

void	draw_unvn_off(t_point *a, t_matrix *m, t_image *img, t_matrix *count)
{
	int	now_x;
	int	now_y;
	int	reset_x;
	int	reset_y;

	now_x = a->pixx;
	now_y = a->pixy;
	reset_x = count->x;
	reset_y = count->y;
	printf("off\n");
	while (m->x != 0 || m->y != 0)
	{
		printf("c1:%d c2:%d off\n", count->x, count->y);
		if (count->x == 0 || count->y == 0)
		{
			printf("str mx:%d my:%d\n", m->x, m->y);
			straight_matrix(m, &now_x, &now_y);
			write_image(img, now_x, now_y, WHITE);
			if (count->x == 0)
				count->x = reset_x;
			else if (count->y == 0)
				count->y = reset_y;
		}
		else
		{
			printf("off mx:%d my:%d\n", m->x, m->y);
			offset_matrix(m, &now_x, &now_y);
			write_image(img, now_x, now_y, WHITE);
			(count->x)--;
			if (count->y > 0)
				(count->y)--;
		}
	}
}

void	draw_unvn_str(t_point *a, t_matrix *m, t_image *img, t_matrix *count)
{
	int	now_x;
	int	now_y;
	int	reset_x;
	int	reset_y;

	now_x = a->pixx;
	now_y = a->pixy;
	reset_x = count->x;
	reset_y = count->y;
	printf("str\n");
	while (m->x != 0 || m->y != 0)
	{
		printf("c1:%d c2:%d str\n", count->x, count->y);
		if (count->x == 0 || count->y == 0)
		{
			printf("off mx:%d my:%d\n", m->x, m->y);
			offset_matrix(m, &now_x, &now_y);
			write_image(img, now_x, now_y, WHITE);
			if (count->x == 0)
				count->x = reset_x;
			else if (count->y == 0)
				count->y = reset_y;
		}
		else
		{
			printf("str mx:%d my:%d\n", m->x, m->y);
			straight_matrix(m, &now_x, &now_y);
			write_image(img, now_x, now_y, WHITE);
			(count->x)--;
			if (count->y > 0)
				(count->y)--;
		}
	}
}

void	draw_l(t_point *a, t_point *b, t_image *img)// t_grid *g)
{
	t_matrix	*matrix;
	int			total;
	int			offset;
	int			straight;
	t_matrix	*count;

    matrix = malloc(sizeof(t_matrix));
	matrix->y = b->pixy - a->pixy;
    matrix->x = b->pixx - a->pixx;
	total = check_total(matrix->x, matrix->y); // module(matrix->x) + module(matrix->y)
	offset = check_offset(matrix->x, matrix->y);
	straight = total - offset;
	count = check_count(offset, straight); // (module(matrix->x), module(matrix->y)), +1, *2
	printf("t:%d = o:%d + s:%d\n", total, offset, straight);
	write_image(img, a->pixx, a->pixy, WHITE); //pontos inicial + coincidentes
	if (count->x == 0)
	{
		printf("quadrante\n");
		draw_str(a, matrix, img);
	}
	else
	{
		printf("unvn ");
		if (straight >= offset)
			draw_unvn_str(a, matrix, img, count); //str dominant
		else if (offset >= straight)
			draw_unvn_off(a, matrix, img, count); //off dominant
	}
}

/*
comecar os erros
*/



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