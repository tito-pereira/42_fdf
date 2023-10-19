#include "fdf_bonus.h"

void	move_cam(t_all *all, int order)
{
	int mx;
	int my;
	t_point	*iter;

	mx = 0;
	my = 0;
	iter = all->pts;
	if (order == 1)
		my = -1 * MVCAM;
	else if (order == 2)
		mx = -1 * MVCAM;
	else if (order == 3)
		my = 1 * MVCAM;
	else if (order == 4)
		mx = 1 * MVCAM;
	while (iter != NULL)
	{
		iter->pixx += mx;
		iter->pixy += my;
		iter = iter->next;
	}
}
