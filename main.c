#include "fdf.h"

int	escape_close(int keycode, void *param) {
	t_mlx *mlx;
	mlx = (t_mlx *)param;
	printf("escaping with keycode:%d\n", keycode);
	if (keycode == 65307) {
		printf("ESC pressed. Beginning exit sequence.\n");
		mlx_destroy_image(mlx->mlx, mlx->img);
		printf("image destroyed\n");
		mlx_destroy_window(mlx->mlx, mlx->win);
		printf("window destroyed\n");
		mlx_destroy_display(mlx->mlx);
		printf("display destroyed\n");
	}
	return 0;
}

int	change_pic(int keycode, void *param) {
	t_image	*new;
	t_mlx	*mlx;
	new = malloc(sizeof(t_image));
	mlx = (t_mlx *)param;
	if (keycode >= 49 && keycode <= 52) {
		new->ptr = mlx_new_image(mlx->mlx, 800, 600);
		if (keycode == 49)
			img_key_central(new, 1);
		else if (keycode == 50)
			img_key_central(new, 2);
		else if (keycode == 51)
			img_key_central(new, 3);
		else if (keycode == 52)
			img_key_central(new, 4);
		printf("change img\n");
		mlx_put_image_to_window(mlx->mlx, mlx->win, new->ptr, 0, 0);
		//mlx_destroy_image(mlx->mlx, mlx->img);
		mlx->img = new->ptr;
		return 0;
	}
	free(new);
	new = NULL;
	return 0;
}

int	key_handler(int keycode, void *param) {
	printf("key_handler\n");
	if (keycode >= 49 && keycode <= 52)
		change_pic(keycode, param);
	else if (keycode == 65307)
		escape_close(keycode, param);
	return 0;
}

int	main(int ac, char **av) {
	t_mlx	*mlx;
	t_image	*image;
	t_grid	*grid;
	t_point	*points;
	t_all	*all;

	if (ac == 2) {
		grid = create_grid(av[1]);
		points = create_points(grid); //acabar
		mlx = malloc(sizeof(t_mlx));
		mlx->mlx = mlx_init();
		mlx->win = mlx_new_window(mlx->mlx, 800, 600, "fdf");
		display_iso(mlx, points, grid); //fazer
		all->mlx = mlx;
		all->grid = grid;
		all->points = points;
		mlx_key_hook(mlx->win, key_handler, (void *)all); //fazer vetores
		mlx_loop(mlx->mlx);
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
