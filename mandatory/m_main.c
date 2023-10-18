#include "fdf.h"

int	escape_close(int keycode, void *param)
{
	t_all *all;
	
	all = (t_all *)param;
	if (keycode == 65307)
	{
		mlx_destroy_image(all->mlx->mlx, all->mlx->img);
		mlx_destroy_window(all->mlx->mlx, all->mlx->win);
		mlx_loop_end(all->mlx->mlx);
	}
	return (0);
}

t_all	*create_all(t_mlx *mlx, t_grid *grid, t_point *pts)
{
	t_all	*all;

	all = malloc(sizeof(t_all));
	all->mlx = mlx;
	all->grid = grid;
	all->pts = pts;
	return (all);
}

int	main(int ac, char **av)
{
	t_mlx	*mlx;
	t_grid	*grid;
	t_point	*pts;
	t_all	*all;

	if (ac == 2 && check_file(av[1]) == 1)
	{
		grid = create_grid(av[1]);
		pts = create_points(grid);
		mlx = malloc(sizeof(t_mlx));
		mlx->mlx = mlx_init();
		mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "fdf");
		all = create_all(mlx, grid, pts);
		new_iso(all);
		mlx_key_hook(mlx->win, escape_close, (void *)all);
		mlx_loop(mlx->mlx);
		//free_everything(all);
		mlx_destroy_display(mlx->mlx);
	}
}

/*
**  origin for x & y is top left corner of the window
**  y down is positive
**  color is 0x00RRGGBB
0x00FF0000 (red)
0x0000FF00 (green)
0x000000FF (blue)

all->mlx->mlx

void	*mlx_new_image(void *mlx_ptr,int width,int height);

char	*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel,
			   int *size_line, int *endian);
int	mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr,
				int x, int y);
int	mlx_get_color_value(void *mlx_ptr, int color);

put image to window, o x e y ali sao as coordenadas do inicio da imagem
neste caso vai ser sempre 0, 0
eu achava que era o quanto eu queria colocar e meti 800, 600
e tava a comecar do fim


void mlx_hook(mlx_win_list_t *win_ptr, int x_event, int x_mask, int (*f)(),
	void *param)
alias (events): key, expose hook, mouse hook
int mlx_key_hook(void *win, int(*f_ptr)(), void *param);

int	mlx_destroy_window(void *mlx_ptr, void *win_ptr);

int	mlx_destroy_image(void *mlx_ptr, void *img_ptr);

int	mlx_destroy_display(void *mlx_ptr);
*/

/*
correr gdb no destroy display
*/

//cc window_test.c write.c -L../minilibx-linux/ -lmlx -lXext -lX11 -lm