#include "./mlx_linux/mlx.h"

int	main() {
	void	*process;
	void	*window;
	char	*name;
	int	x, y;
	x = 800;
	y = 600;
	name = "new image";
	process = mlx_init();
	window = mlx_new_window(process, x, y, name);
	//mlx_pixel_put(process, window, 400, 300, 0x0000FF00);
	for (int y = 200; y <= 400; y++) {
		for (int x = 200; x <= 600; x++)
			mlx_pixel_put(process, window, x, y, 0x0000FFFF);
	}
	mlx_loop(process);
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
*/

//cc window_test.c -L./mlx_linux/ -lmlx -lXext -lX11 -lm