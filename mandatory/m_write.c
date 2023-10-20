#include "fdf.h"

void	write_image(t_image *img, int x, int y, int color)
{
	int i;
	int	*paint;

	i = 0;
	if ((x > 0 && x < WIDTH) && (y > 0 && y < HEIGHT)) {
		img->data = mlx_get_data_addr(img->ptr, &img->bpp, &img->sline, &img->endian);
		i = (y * (img->sline / 4)) + x;
		paint = (int *)(img->data);
		paint[i - 1] = color;
	}
}

int	nmb_module(int x)
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
