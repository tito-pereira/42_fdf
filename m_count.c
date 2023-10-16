#include "fdf.h"

void	f_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

t_count *new_count(int value)
{
    t_count	*new;

	new = malloc(sizeof(t_count));
	new->cnt = value;
	new->reset = value;
	new->nxt = NULL;
	return (new);
}

void	chk_pos_cntrs(t_count *count)
{
	count = count->nxt;
	while (count != NULL)
	{
		if (count->cnt > 0)
			(count->cnt)--;
		count = count->nxt;
	}
}

int chk_zero_cntrs(t_count *count)
{
    count = count->nxt;
	while (count != NULL)
	{
		if (count->cnt == 0)
		{
			count->cnt = count->reset;
			return (1);
		}
		count = count->nxt;
	}
	return (0);
}