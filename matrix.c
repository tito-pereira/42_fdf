#include "fdf.h"

void	offset_matrix(t_matrix *m, int *now_x, int *now_y)
{
	if (m->x > 0)
	{
		(*now_x)++;
		m->x--;
	}
	if (m->x < 0)
	{
		(*now_x)--;
		m->x++;
	}
	if (m->y > 0)
	{
		(*now_y)++;
		m->y--;
	}
	if (m->y < 0)
	{
		(*now_y)--;
		m->y++;
	}
}

void	straight_matrix(t_matrix *m, int *now_x, int *now_y)
{
	if (nmb_module(m->x) > nmb_module(m->y))
	{
		(*now_x) += signal(m->x);
		m->x -= signal(m->x);
	}
	else if (nmb_module(m->y) > nmb_module(m->x))
	{
		(*now_y) += signal(m->y);
		m->y -= signal(m->y);
	}
}

int	check_total(int mx, int my)
{
	int	total;
	total = 0;
	if (nmb_module(mx) > nmb_module(my))
		total = nmb_module(mx);
	else if (nmb_module(my) > nmb_module(mx))
		total = nmb_module(my);
	return (total);
}

int	check_offset(int mx, int my)
{
	int	offset;
	offset = 0;
	if (nmb_module(mx) >= nmb_module(my))
		offset = nmb_module(my);
	else if (nmb_module(my) > nmb_module(mx))
		offset = nmb_module(mx);
	return (offset);
}

t_count	*check_count(int offset, int straight)
{
	t_count	*count;
	t_count	*first;
	int	rest;

	count = new_count(0);
	first = count;
	rest = 0;
	if (straight > offset)
		f_swap(&offset, &straight);
	if (offset == 0 || straight == 0)
		return (count);
	if (offset >= straight)
	{
		count->cnt = offset / straight;
		count->reset = count->cnt;
		rest = offset % straight;
		while (rest != 0)
		{
			count->nxt = new_count((offset / rest));
			count = count->nxt;
			rest = offset % rest;
		}
	}
	return (first);
}

/*
void	offset_matrix(t_matrix *m, int *now_x, int *now_y)
{
	if (m->x > 0)
	{
		//printf("before nowx:%d mx:%d\n", *now_x, m->x);
		(*now_x)++;
		m->x--;
		//printf("after nowx:%d mx:%d\n", *now_x, m->x);
	}
	if (m->x < 0)
	{
		//printf("before nowx:%d mx:%d\n", *now_x, m->x);
		(*now_x)--;
		m->x++;
		//printf("after nowx:%d mx:%d\n", *now_x, m->x);
	}
	if (m->y > 0)
	{
		//printf("before nowy:%d my:%d\n", *now_y, m->y);
		(*now_y)++;
		m->y--;
		//printf("after nowy:%d my:%d\n", *now_y, m->y);
	}
	if (m->y < 0)
	{
		//printf("before nowy:%d my:%d\n", *now_y, m->y);
		(*now_y)--;
		m->y++;
		//printf("after nowy:%d my:%d\n", *now_y, m->y);
	}
}

void	straight_matrix(t_matrix *m, int *now_x, int *now_y)
{
	if (module(m->x) > module(m->y)) //m->x > m->y
	{
		printf("before nowx:%d mx:%d\n", *now_x, m->x);
		(*now_x) += signal(m->x); //++, (*now_x) += m->x
		m->x -= signal(m->x); //--, m->x = m->x - m->x
		printf("after nowx:%d mx:%d\n", *now_x, m->x);
	}
	else if (module(m->y) > module(m->x)) //m->y > m->x
	{
		printf("before nowy:%d my:%d\n", *now_y, m->y);
		(*now_y) += signal(m->y); //++
		m->y -= signal(m->y); //--
		printf("after nowy:%d my:%d\n", *now_y, m->y);
	}
}

int	check_offset(int mx, int my)
{
	int	offset;

	offset = 0;
	if (mx < 0)
		mx *= -1;
	if (my < 0)
		my *= -1;
	if (mx > my)
		offset = mx - my;
	if (my > mx)
		offset = my - mx;
	return (offset);
}

int	check_count(int offset, int straight)
{
	int	count;

	count = 0;
	if (offset == 0 || straight == 0)
		return (count);
	if (offset >= straight)
	{
		count = offset / straight;
		printf("c:%d (%d / %d) ", count, offset, straight);
	}
	else if (straight > offset)
	{
		count = straight / offset;
		printf("c:%d (%d / %d) ", count, straight, offset);
	}
	return (count);
}

t_matrix	*check_count(int offset, int straight)
{
	t_matrix	*count;
	int	rest;

	count = malloc(sizeof(t_matrix));
	count->x = 0;
	count->y = -1;
	rest = 0;
	if (offset == 0 || straight == 0)
		return (count);
	if (offset >= straight)
	{
		count->x = offset / straight;
		rest = offset % straight;
		if (rest != 0)
			count->y = offset / rest;
		printf("c1:%d(%d/%d) c2:%d(%d/%d)", count->x, offset, straight, count->y, offset, rest);
	}
	else if (straight > offset)
	{
		count->x = straight / offset;
		rest = straight / offset;
		if (rest != 0)
			count->y = straight / rest;
		printf("c1:%d(%d/%d) c2:%d(%d/%d)", count->x, straight, offset, count->y, straight, rest);
	}
	return (count);
}
*/