#include "fdf.h"

int	change_pic(t_mlx **mlx) {
	t_image	*img;
	img = malloc(sizeof(t_image));
	printf("malloc\n");
	img->ptr = mlx_new_image((*mlx)->mlx, 800, 600);
	printf("new image\n");
	/*for (int x = 300; x <= 500; x++) {
		for (int y = 200; y <= 400; y++)
			write_image(&img, x, y, GREEN);
	}*/
	(*mlx)->img = img->ptr;
	mlx_put_image_to_window((*mlx)->mlx, (*mlx)->win, img->ptr, 0, 0);
	return (0);
}

int	main(int ac, char **av) {
	if (ac == 2) {
		t_mlx	*mlx;
		t_image	*image;
		int	colunas, linhas;
		colunas = 800;
		linhas = 600;
		mlx = malloc(sizeof(t_mlx));
		image = malloc(sizeof(t_image));
		mlx->mlx = mlx_init();
		mlx->win = mlx_new_window(mlx->mlx, colunas, linhas, "fdf");
		image->ptr = mlx_new_image(mlx->mlx, colunas, linhas);
		mlx->img = image->ptr;
		img_av_central(&image, av[1]);
		mlx_put_image_to_window(mlx->mlx, mlx->win, image->ptr, 0, 0);
		mlx_loop(mlx->mlx);
	}
	if (ac == 1) {
		t_mlx	*mlx;
		t_image	*image;
		mlx = malloc(sizeof(t_mlx));
		image = malloc(sizeof(t_image));
		mlx->mlx = mlx_init();
		mlx->win = mlx_new_window(mlx->mlx, 800, 600, "fdf");
		mlx_key_hook(mlx->win, change_pic, &mlx);
		mlx_loop(mlx->mlx);
		/*
		image->ptr = mlx_new_image(mlx->mlx, 800, 600);
		mlx_put_image_to_window(mlx->mlx, mlx->win, image->ptr, 0, 0);
		mlx_key_hook(mlx->win, change_pic, image);
		*/
	}
}

/*
**  origin for x & y is top left corner of the window
**  y down is positive
**  color is 0x00RRGGBB
0x00FF0000 (red)
0x0000FF00 (green)
0x000000FF (blue)


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

/*for (int y = 200; y <= 400; y++) {
	for (int x = 200; x <= 600; x++)
		write_image(process, window, x, y, 0x0000FF00);
}
for (int j = 10; j <= 600; j += 20) {
	for (int i = 0; i <= 800; i++) {
		write_image(process, window, i, j, 0x0000FFFF);
	}
}
for (int i = 10; i <= 800; i += 20) {
	for (int j = 0; j <= 600; j++) {
		write_image(process, window, i, j, 0x0000FFFF);
	}
}*/

/*write_image(&image, 400, 300, GREEN);
for (int j = 10; j <= 600; j += 20) {
	for (int i = 0; i <= 800; i++) {
		write_image(&image, i, j, WHITE);
	}
}
for (int i = 10; i <= 800; i += 20) {
	for (int j = 0; j <= 600; j++) {
		write_image(&image, i, j, WHITE);
	}
}*/

//cc window_test.c write.c -L../minilibx-linux/ -lmlx -lXext -lX11 -lm
