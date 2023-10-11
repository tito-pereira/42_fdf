#include "fdf.h"

int	module(int x)
{
	if (x < 0)
		x *= -1;
	return (x);
}

int	signal(int x)
{
	int	signal;

	signal = 1;
	if (x < 0)
		signal *= -1;
	if (x == 0)
		signal = 0;
	return (signal);
}

void	offset_matrix(t_matrix *m, int *now_x, int *now_y)
{
	if (m->x > 0)
	{
		printf("before nowx:%d mx:%d\n", *now_x, m->x);
		(*now_x)++;
		m->x--;
		printf("after nowx:%d mx:%d\n", *now_x, m->x);
	}
	if (m->x < 0)
	{
		printf("before nowx:%d mx:%d\n", *now_x, m->x);
		(*now_x)--;
		m->x++;
		printf("after nowx:%d mx:%d\n", *now_x, m->x);
	}
	if (m->y > 0)
	{
		printf("before nowy:%d my:%d\n", *now_y, m->y);
		(*now_y)++;
		m->y--;
		printf("after nowy:%d my:%d\n", *now_y, m->y);
	}
	if (m->y < 0)
	{
		printf("before nowy:%d my:%d\n", *now_y, m->y);
		(*now_y)--;
		m->y++;
		printf("after nowy:%d my:%d\n", *now_y, m->y);
	}
}
//full offset (1, 1) -> full straight (1, 0)

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
//so faz matrizes (1,0) na direcao da coordenada maior

int	check_total(int mx, int my)
{
	if (mx < 0)
		mx *= -1;
	if (my < 0)
		my *= -1;
	return (mx + my);
}
//soma os modulos de |mx| e |my|
//numero total de vetores q se anda

int	check_offset(int mx, int my)
{
	int	offset;

	offset = 0;
	/*if (mx < 0)
		mx *= -1;
	if (my < 0)
		my *= -1;*/
	if (module(mx) > module(my))
		offset = mx - my;
	if (module(my) > module(mx))
		offset = my - mx;
	return (offset);
}
//faz a diferenca dos modulos de |mx| e |my|
//diferenca entre os vetores (1, 0) e (1, 1) q se anda

int	check_count(int offset, int straight)
{
	int	count;

	count = 0;
	if (offset > straight)
		count = offset / straight;
	else if (straight > offset)
		count = straight / offset;
	return (count);
}
//ve qual dos tipos de vetor, (1, 0) ou (1, 1) tem maior quantidade
//divide um pelo outro para introduzir o vetor minoritario
//de modo proporcional e equidistante

/*
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
*/