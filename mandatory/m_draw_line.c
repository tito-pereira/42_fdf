#include "fdf.h"

void	draw_str(t_point *a, t_matrix *m, t_image *img, int color)
{
	int	now_x;
	int	now_y;

	now_x = a->pixx;
	now_y = a->pixy;
	while (m->x != 0 || m->y != 0)
	{
		offset_matrix(m, &now_x, &now_y);
		write_image(img, now_x, now_y, color);
	}
}

void	draw_unvn_off(t_point *a, t_matrix *m, t_image *img, t_count *count, int color)
{
	int	now_x;
	int	now_y;

	now_x = a->pixx;
	now_y = a->pixy;
	while (m->x != 0 || m->y != 0)
	{
		if (count->cnt == 0)
		{
			straight_matrix(m, &now_x, &now_y);
			write_image(img, now_x, now_y, color);
			if (count->cnt == 0)
				count->cnt = count->reset;
			chk_pos_cntrs(count);
		}
		if (chk_zero_cntrs(count) == 1)
		{
			offset_matrix(m, &now_x, &now_y);
			write_image(img, now_x, now_y, color);
		}
		else
		{
			offset_matrix(m, &now_x, &now_y);
			write_image(img, now_x, now_y, color);
			if (count->cnt > 0)
				(count->cnt)--;
			chk_pos_cntrs(count);
		}
	}
}

void	draw_unvn_str(t_point *a, t_matrix *m, t_image *img, t_count *count, int color)
{
	int	now_x;
	int	now_y;

	now_x = a->pixx;
	now_y = a->pixy;
	while (m->x != 0 || m->y != 0)
	{
		if (count->cnt == 0)
		{
			offset_matrix(m, &now_x, &now_y);
			write_image(img, now_x, now_y, color);
			if (count->cnt == 0)
				count->cnt = count->reset;
			chk_pos_cntrs(count);
		}
		if (chk_zero_cntrs(count) == 1)
		{
			straight_matrix(m, &now_x, &now_y);
			write_image(img, now_x, now_y, color);
		}
		else
		{
			straight_matrix(m, &now_x, &now_y);
			write_image(img, now_x, now_y, color);
			if (count->cnt > 0)
				(count->cnt)--;
			chk_pos_cntrs(count);
		}
	}
}

int	define_color(t_point *a, t_point *b)
{
	int	medium;

	medium = (a->z + b->z) / 2;
	if (medium <= 0)
		return (LBLUE);
	else if (medium > 0 && medium < 5)
		return (YELLOW);
	else if (medium >= 5 && medium < 30)
		return (GREEN);
	else if (medium >= 30 && medium < 80)
		return (BROWN);
	return (WHITE);
}

void	draw_line(t_point *a, t_point *b, t_image *img)
{
	t_matrix	*matrix;
	int			total;
	int			offset;
	int			straight;
	t_count		*count;
	int			color;

    matrix = malloc(sizeof(t_matrix));
	color = define_color(a, b);
	matrix->y = b->pixy - a->pixy;
    matrix->x = b->pixx - a->pixx;
	total = check_total(matrix->x, matrix->y);
	offset = check_offset(matrix->x, matrix->y);
	straight = total - offset;
	count = check_count(offset, straight);
	write_image(img, a->pixx, a->pixy, color);
	if (count->cnt == 0)
		draw_str(a, matrix, img, color);
	else
	{
		if (straight >= offset)
			draw_unvn_str(a, matrix, img, count, color);
		else if (offset >= straight)
			draw_unvn_off(a, matrix, img, count, color);
	}
}
