#include "fdf.h"

int	main() {
	void	*process;
	void	*window;
	char	*name;
	t_image	*image;
	int	colunas, linhas;
	colunas = 800;
	linhas = 600;
	image = malloc(sizeof(t_image));
	process = mlx_init();
	window = mlx_new_window(process, colunas, linhas, "fdf");
	image->ptr = mlx_new_image(process, colunas, linhas);
	write_image(&image, 400, 300, GREEN);
	for (int j = 10; j <= 600; j += 20) {
		for (int i = 0; i <= 800; i++) {
			write_image(&image, i, j, WHITE);
		}
	}
	for (int i = 10; i <= 800; i += 20) {
		for (int j = 0; j <= 600; j++) {
			write_image(&image, i, j, WHITE);
		}
	}
	mlx_put_image_to_window(process, window, image->ptr, 0, 0);
	mlx_loop(process);
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

//cc window_test.c write.c -L../minilibx-linux/ -lmlx -lXext -lX11 -lm
