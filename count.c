#include "fdf.h"

/*
f_swap (2 int)

count = new_count(0);
count = malloc(sizeof(t_count));
	count->cnt = 0;
	count->reset = 0

chk_pos_cntrs(count);//check_other, if > 0, --

(chk_zero_cntrs(count) == 1) //check others cnts, if == 0, reset, return 1, do function
*/

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

	printf("in, value:%d\n", value);
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