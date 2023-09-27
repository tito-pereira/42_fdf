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
	//mlx_pixel_put(process, window, x, y, );
	mlx_loop(process);
}