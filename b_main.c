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
		change_frame((t_all *)param, 1, 1);
	else if (keycode == 97)
		change_frame((t_all *)param, 1, 2);
	else if (keycode == 115)
		change_frame((t_all *)param, 1, 3);
	else if (keycode == 100)
		change_frame((t_all *)param, 1, 4);
	else if (keycode == 65362)
		change_frame((t_all *)param, 2, 1);
	else if (keycode == 65364)
		change_frame((t_all *)param, 2, 2);
	else if (keycode == 32)
		change_frame((t_all *)param, 3, 1);
	else if (keycode == 49)
		change_frame((t_all *)param, 4, 1);
	else if (keycode == 65363)
		change_frame((t_all *)param, 5, 1);
	else if (keycode == 65361)
		change_frame((t_all *)param, 5, 2);
	else if (keycode == 50)
		change_frame((t_all *)param, 6, 1);
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
		new_iso(all, first);
		mlx_key_hook(mlx->win, key_handler, (void *)all);
		mlx_loop(mlx->mlx);
	}
}