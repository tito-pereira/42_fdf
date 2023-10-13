#include "fdf.h"

int	escape_close(int keycode, void *param) {
	t_all *all;
	all = (t_all *)param;
	//printf("escaping with keycode:%d\n", keycode);
	if (keycode == 65307) {
		//free everything
		//printf("ESC pressed. Beginning exit sequence.\n");
		mlx_destroy_image(all->mlx->mlx, all->mlx->img);
		//printf("image destroyed\n");
		mlx_destroy_window(all->mlx->mlx, all->mlx->win);
		//printf("window destroyed\n");
		mlx_destroy_display(all->mlx->mlx);
		//printf("display destroyed\n");
	}
	return 0;
}

int	key_handler(int keycode, void *param)
{
	if (keycode == 119)
		move_cam((t_all *)param, 'w');
	else if (keycode == 97)
		move_cam((t_all *)param, 'a');
	else if (keycode == 115)
		move_cam((t_all *)param, 's');
	else if (keycode == 100)
		move_cam((t_all *)param, 'd');
	/*else if (keycode == 65362)
		zoom((t_all *)param, 'i');
	else if (keycode == 65364)
		zoom((t_all *)param, 'o');*/
	else if (keycode == 65307)
		escape_close(keycode, param);
	return 0;
}

int	main(int ac, char **av) {
	t_mlx	*mlx;
	t_grid	*grid;
	t_point	*points;
	t_image	*first;
	t_all	*all;

	if (ac == 2) {
		all = malloc(sizeof(t_all));
		grid = create_grid(av[1]);
		points = create_points(grid);
		first = malloc(sizeof(t_image));
		mlx = malloc(sizeof(t_mlx));
		mlx->mlx = mlx_init();
		mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "fdf");
		first->ptr = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
		all->mlx = mlx;
		all->grid = grid;
		all->pts = points;
		display_iso(all, first);
		mlx_key_hook(mlx->win, key_handler, (void *)all);
		mlx_loop(mlx->mlx);
	}
}
//sera que posso tirar aquela condiçao if?
//sera que tenho de verificar o titulo por uma extansao ".fdf"?

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