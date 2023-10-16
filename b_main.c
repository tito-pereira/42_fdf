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
	{
		move_cam((t_all *)param, 's');
		//change_display((t_all *)param, 's', &move_cam);
	}
	else if (keycode == 97)
		move_cam((t_all *)param, 'd');
	else if (keycode == 115)
		move_cam((t_all *)param, 'w');
	else if (keycode == 100)
		move_cam((t_all *)param, 'a');
	else if (keycode == 65362)
		zoom((t_all *)param, 'i');
	else if (keycode == 65364)
		zoom((t_all *)param, 'o');
	else if (keycode == 65363)
		do_rot((t_all *)param, 'r');
	else if (keycode == 65361)
		do_rot((t_all *)param, 'l');
	else if (keycode == 32)
		do_plan((t_all *)param);
	else if (keycode == 49)
		do_iso((t_all *)param);
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