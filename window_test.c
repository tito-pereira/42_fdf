#include "./minilibx-linux/mlx.h"

typedef	struct	s_image {
	void	*pointer;
	char	*data;
	int	bitspp;
	int	sizeline;
	int	endian;
}	t_image;

void	*write_image(void *image) {
	char	*info;
	int	bpp, sline, endian;
	info = mlx_get_data_addr(image, &bpp, &sline, &endian);
	//agora quero escrever os meus pixeis aqui
	/*a funcao pede nos int* para um simples numero, o que
	signfica que é suposto passarmos a morada e eles preenchem automatico
	aquelas informações*/
	/*crio uma struct porque sao conjuntos de informações que vao estar
	sempre associados a uma só imagem*/
	char	*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel,
			   int *size_line, int *endian);
	return ()
}

int	main() {
	void	*process;
	void	*window;
	char	*name;
	t_image	*image;
	int	colunas, linhas;
	colunas = 800;
	linhas = 600;
	process = mlx_init();
	window = mlx_new_window(process, colunas, linhas, "fdf");
	image->pointer = mlx_new_image(process, colunas, linhas);
	image->pointer = write_image(image->pointer);
	for (int y = 200; y <= 400; y++) {
		for (int x = 200; x <= 600; x++)
			mlx_pixel_put(process, window, x, y, 0x0000FF00);
	}
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
	int	mlx_put_image_to_window(process, window, image, colunas, linhas);
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

*/

//cc window_test.c -L./mlx_linux/ -lmlx -lXext -lX11 -lm
