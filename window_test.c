#include "./mlx_linux/mlx.h"

int	main() {
	void	*process;
	void	*window;
	char	*name;
	void	*image;
	int	x, y;
	x = 800;
	y = 600;
	name = "new image";
	process = mlx_init();
	window = mlx_new_window(process, x, y, name);
	//mlx_pixel_put(process, window, 400, 300, 0x0000FF00);
	for (int y = 200; y <= 400; y++) {
		for (int x = 200; x <= 600; x++)
			mlx_pixel_put(process, window, x, y, 0x0000FF00);
	}
	/*for (int j = 10; j <= 600; j += 20) {
		for (int i = 10; i <= 800; i += 20) {
			mlx_pixel_put(process, window, i, j, 0x0000FFFF);
		}
	}*/
	for (int j = 10; j <= 600; j += 20) {
		for (int i = 0; i <= 800; i++) {
			mlx_pixel_put(process, window, i, j, 0x0000FFFF);
		}
	}
	for (int i = 10; i <= 800; i += 20) {
		for (int j = 0; j <= 600; j++) {
			mlx_pixel_put(process, window, i, j, 0x0000FFFF);
		}
	}
	mlx_loop(process);
	image = mlx_new_image(process, x, y);
}

/*
o teste funcionou, o loop de put_pixel funcionou

antes de lidar com os eventos e hooks, ainda nem sei como criar uma imagem com a grid e isso
sera que tenho que ser eu a descarregar um grid ja em imagem?

image vs window

**  origin for x & y is top left corner of the window
**  y down is positive
**  color is 0x00RRGGBB
0x00FF0000 (red)
0x0000FF00 (green)
0x000000FF (blue)


** Image stuff
-new image
-data address
-put img to window
-get color value

void	*mlx_new_image(void *mlx_ptr,int width,int height);
**  return void *0 if failed
**  obsolete : image2 data is stored using bit planes
**  void	*mlx_new_image2(void *mlx_ptr,int width,int height);
char	*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel,
			   int *size_line, int *endian);

**  endian : 0 = sever X is little endian, 1 = big endian
**  for mlx_new_image2, 2nd arg of mlx_get_data_addr is number_of_planes

int	mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr,
				int x, int y);
int	mlx_get_color_value(void *mlx_ptr, int color);

vou ter que usar estas funcoes de imagem, para evitar tears da imagem ao
carregar, e assim vou guardando os pixeis todos e so apresento quando estiver
tudo pronto

fdf e um programa que vai receber como argumento, nao uma string,
mas o nome de um file, com extensao "fdf" que eu acho que nao
quer dizer nada
*/

//cc window_test.c -L./mlx_linux/ -lmlx -lXext -lX11 -lm