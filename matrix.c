#include "fdf.h"

void	offset_matrix(int *mx, int *my, int *now_x, int *now_y)
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
//full offset (1, 1) -> full straight (1, 0)

void	straight_matrix(int *mx, int *my, int *now_x, int *now_y)
{
	if (mx > my)
	{
		(*now_x)++;
		(*mx)--;
	}
	else if (my > mx)
	{
		(*now_y)++;
		(*my)--;
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