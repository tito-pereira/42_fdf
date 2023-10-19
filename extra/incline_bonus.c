#include "fdf_bonus.h"


int	inc_down_iso(t_matrix *rm, t_matrix *lm)
{
	if ((lm->x == -rm->x) //B
		&& (!(rm->y != 0 && rm->x / rm->y == 1)))
	{
		//printf("before, ry:%d ly:%d\n", rm->y, lm->y);
		rm->y += (rm->x / 2); //1 ,-->+ (-)
		lm->y += (rm->x / 2); //1 ,+->+ (+)
		//printf("after, ry:%d ly:%d\n", rm->y, lm->y);
		if (rm->y != 0 && nmb_module(rm->x) / nmb_module(rm->y) == 1)
			return (0);
		else if (rm->y == 0)
			return (33);
		return (3);
	}
	else if ((lm->x == rm->x) //A
		&& (!(rm->y != 0 && rm->x / rm->y == -1)))
	{
		//printf("before, ry:%d ly:%d\n", rm->y, lm->y);
		rm->y -= (rm->x / 2); //-1 ,+->- (-)
		lm->y += (rm->x / 2); //-1 ,-->+ (+)
		//printf("after, ry:%d ly:%d\n", rm->y, lm->y);
		if (rm->y != 0 && nmb_module(rm->x) / nmb_module(rm->y) == 1) //os dois extremos
			return (0);
		else if (rm->y == 0)
			return (33);
		return (3);
	}
	return (-1);
}

int	inc_down_plan(t_matrix *rm, t_matrix *lm)
{
	if ((rm->y == 0 && lm->x == 0) //C
		&& (!(lm->y != 0 && rm->x / lm->y == 1)))
	{
		//printf("hori\nbefore, rx:%d ly:%d\n", rm->x, lm->y);
		lm->y += (rm->x / 2);
		//printf("after, rx:%d ly:%d\n", rm->x, lm->y);
		if (lm->y != 0 && nmb_module(rm->x) / nmb_module(lm->y) == 1)
			return (0);
		else if (lm->y == 0)
			return (55);
		return (5);
	}
	else if ((rm->x == 0 && lm->y == 0)
		&& (!(rm->y != 0 && lm->x / rm->y == 1))) //D
	{
		//printf("verti\nbefore, ry:%d lx:%d\n", rm->y, lm->x);
		rm->y += (lm->x / 2);
		//printf("after, ry:%d lx:%d\n", rm->y, lm->x);
		if (rm->y != 0 && nmb_module(lm->x) / nmb_module(rm->y) == 1)
			return (0);
		else if (rm->y == 0)
			return (55);
		return (5);
	}
	return (inc_down_iso(rm, lm));
}

int	inc_up_iso(t_matrix *rm, t_matrix *lm)
{
	if ((lm->x == -rm->x) && (!(rm->y != 0 && rm->x / rm->y == -1))) //B
	{
		//printf("before, ry:%d ly:%d\n", rm->y, lm->y);
		rm->y -= (rm->x / 2); //1 ,-->+ (-)
		lm->y -= (rm->x / 2); //1 ,+->+ (+)
		//printf("after, ry:%d ly:%d\n", rm->y, lm->y);
		if (rm->y != 0 && nmb_module(rm->x) / nmb_module(rm->y) == 1)
			return (0);
		else if (rm->y == 0)
			return (33);
		return (3);
	}
	else if ((lm->x == rm->x) && (!(rm->y != 0 && rm->x / rm->y == 1))) //A
	{
		//printf("before, ry:%d ly:%d\n", rm->y, lm->y);
		rm->y += (rm->x / 2); //-1 ,+->- (-)
		lm->y -= (rm->x / 2); //-1 ,-->+ (+)
		//printf("after, ry:%d ly:%d\n", rm->y, lm->y);
		if (rm->y != 0 && nmb_module(rm->x) / nmb_module(rm->y) == 1) //os dois extremos
			return (0);
		else if (rm->y == 0)
			return (33);
		return (3);
	}
	return (-1);
}

int	inc_up_plan(t_matrix *rm, t_matrix *lm)
{
	if ((rm->y == 0 && lm->x == 0) //C
		&& (!(lm->y != 0 && rm->x / lm->y == -1)))
	{
		//printf("hori\nbefore, rx:%d ly:%d\n", rm->x, lm->y);
		lm->y -= (rm->x / 2);
		//printf("after, rx:%d ly:%d\n", rm->x, lm->y);
		if (lm->y != 0 && nmb_module(rm->x) / nmb_module(lm->y) == 1)
			return (0);
		else if (lm->y == 0)
			return (55);
		return (5);
	}
	else if ((rm->x == 0 && lm->y == 0)
		&& (!(rm->y != 0 && lm->x / rm->y == -1))) //D
	{
		//printf("verti\nbefore, ry:%d lx:%d\n", rm->y, lm->x);
		rm->y -= (lm->x / 2);
		//printf("after, ry:%d lx:%d\n", rm->y, lm->x);
		if (rm->y != 0 && nmb_module(lm->x) / nmb_module(rm->y) == 1)
			return (0);
		else if (rm->y == 0)
			return (55);
		return (5);
	}
	return (inc_up_iso(rm, lm));
}

void    incline(t_all *all, int order)
{
    t_matrix    *rm;
    t_matrix    *lm;
	t_matrix	*start;
	int			z;

    rm = r_matrix(all->pts);
	z = 0;
	start = malloc(sizeof(t_matrix));
	lm = l_matrix(all->pts, all->grid);
	if (order == 1)
		z = inc_up_plan(rm, lm);
	else if (order == 2)
		z = inc_down_plan(rm, lm);
	start->x = (WIDTH / 2) - ((all->grid->rows / 2) * rm->x) - ((all->grid->lines / 2) * lm->x);
	start->y = (HEIGHT / 2) - ((all->grid->rows / 2) * rm->y) - ((all->grid->lines / 2) * lm->y);
    if (z != -1)
		prep_pts(all, rm, lm, start, z);
	free(rm);
    free(lm);
	free(start);
}

/*
. distinguir entre o 2:2 e 2:1 positivo e o negativo
. sera que vale a pena sequer?
. nas situaçoes limites
em vez de proibir
mfazer z * -1 e por na mesma

. incline em posiçoes nao iso e nao plan
. rotações funcionam na perfeição, mas o incline ainda dá certos stresses
se for feito num angulo estranho, tipo incline + rotate
o proprio incline em si, lateral, sem ser nas posicoes iniciais,
funciona estranho
*/

/*
int	inc_up_iso(t_matrix *rm, t_matrix *lm)
{
	if ((lm->x == (rm->x * (-1))) //B
		&& (!(rm->y < 0 && nmb_module(rm->x) / nmb_module(rm->y) == 1)))
	{
		//printf("before, ry:%d ly:%d\n", rm->y, lm->y);
		rm->y -= (nmb_module(rm->x) / 2);
		lm->y -= (nmb_module(rm->x) / 2);
		//printf("after, ry:%d ly:%d\n", rm->y, lm->y);
		if (rm->y < 0 && nmb_module(rm->x) / nmb_module(rm->y) == 1)
			return (0);
		else if (rm->y < 0 && nmb_module(rm->x) / nmb_module(rm->y) == 2)
			return (3);
		else if (rm->y == 0)
			return (33);
		return (3);
	}
	else if ((lm->x == rm->x) //A, mal, change
		&& (!(rm->y < 0 && nmb_module(rm->x) / nmb_module(rm->y) == 1)))
	{
		rm->y -= (nmb_module(rm->x) / 2);
		lm->y += (nmb_module(rm->x) / 2);
		if (rm->y < 0 && nmb_module(rm->x) / nmb_module(rm->y) == 1)
			return (0);
		else if (rm->y < 0 && nmb_module(rm->x) / nmb_module(rm->y) == 2)
			return (3);
		else if (rm->y == 0)
			return (33);
		return (3);
	}
	return (-1);
}

int	inc_up_plan(t_matrix *rm, t_matrix *lm)
{
	if ((rm->y == 0 && lm->x == 0)
		&& (!(lm->y < 0 && nmb_module(rm->x) / nmb_module(lm->y) == 1)))
	{
		lm->y -= (nmb_module(rm->x) / 2);
		if (lm->y < 0 && nmb_module(rm->x) / nmb_module(lm->y) == 1)
			return (0);
		else if (lm->y < 0 && nmb_module(rm->x) / nmb_module(lm->y) == 2)
			return (40);
		return (4);
	}
	else if ((rm->x == 0 && lm->y == 0)
		&& (!(rm->y < 0 && nmb_module(lm->x) / nmb_module(rm->y) == 1)))
	{
		rm->y -= (nmb_module(lm->x) / 2);
		if (rm->y < 0 && nmb_module(lm->x) / nmb_module(rm->y) == 1)
			return (0);
		else if (rm->y < 0 && nmb_module(lm->x) / nmb_module(rm->y) == 2)
			return (40);
		return (4);
	}
	return (inc_up_iso(rm, lm));
}

void	inc_up_plan(t_matrix *rm, t_matrix *lm)
{
	else if (rm->y == 0 && lm->x == 0) //C
	{
		if (lm->y > 0 && nmb_module(rm->x) / nmb_module(lm->y) == 2)
			lm->y *= 2;
		else if (lm->y == 0)
			lm->y = (nmb_module(rm->x) / 2) * -1;
		else if (lm->y < 0 && nmb_module(rm->x) / nmb_module(lm->y) == 2)
			lm->y = 0;
		else if (lm->y < 0 && nmb_module(rm->x) / nmb_module(lm->y) == 1)
			lm->y /= 2;
	}
	else if (rm->x == 0 && lm->y == 0) //D
	{
		if (rm->y > 0 && nmb_module(lm->x) / nmb_module(rm->y) == 2)
			rm->y *= 2;
		else if (rm->y == 0)
			rm->y = (nmb_module(lm->x) / 2) * -1;
		else if (rm->y < 0 && nmb_module(lm->x) / nmb_module(rm->y) == 2)
			rm->y = 0;
		else if (rm->y < 0 && nmb_module(lm->x) / nmb_module(rm->y) == 1)
			rm->y /= 2;
	}
}

void	inc_up_plan(t_matrix *rm, t_matrix *lm)
{
	else if (rm->y == 0 && lm->x == 0) //C
	{
		if (!(lm->y < 0 && nmb_module(rm->x) / nmb_module(lm->y) == 1))
			lm->y -= (nmb_module(rm->x) / 2);
	}
	else if (rm->x == 0 && lm->y == 0) //D
	{
		if (!(rm->y < 0 && nmb_module(lm->x) / nmb_module(rm->y) == 1))
			rm->y -= (nmb_module(lm->x) / 2);
	}
}

void	inc_up(t_matrix *rm, t_matrix *lm)
{
	if ((lm->x == rm->x || lm->x == (rm->x * (-1)))
		&& (!(rm->y < 0 && nmb_module(rm->x) / nmb_module(rm->y) == 1)))
			rm->y -= (nmb_module(rm->x) / 2);
	else if ((rm->y == 0 && lm->x == 0)
		&& (!(lm->y < 0 && nmb_module(rm->x) / nmb_module(lm->y) == 1)))
			lm->y -= (nmb_module(rm->x) / 2);
	else if ((rm->x == 0 && lm->y == 0)
		&& (!(rm->y < 0 && nmb_module(lm->x) / nmb_module(rm->y) == 1)))
			rm->y -= (nmb_module(lm->x) / 2);
}
*/