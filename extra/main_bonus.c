/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:46:12 by tibarbos          #+#    #+#             */
/*   Updated: 2023/10/20 18:05:10 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	escape_close(int keycode, void *param)
{
	t_all	*all;

	all = (t_all *)param;
	if (keycode == 65307)
	{
		mlx_destroy_image(all->mlx->mlx, all->mlx->img);
		mlx_destroy_window(all->mlx->mlx, all->mlx->win);
		mlx_loop_end(all->mlx->mlx);
	}
	return (0);
}

int	mouse_handler(int button, int x, int y, void *param)
{
	t_all	*all;

	all = (t_all *)param;
	if (x > 0 && y > 0)
	{
		if (button == 4)
			change_frame(all, 2, 1);
		else if (button == 5)
			change_frame(all, 2, 2);
	}
	return (0);
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
	else if (keycode == 50)
		change_frame((t_all *)param, 3, 1);
	else if (keycode == 49)
		change_frame((t_all *)param, 4, 1);
	else if (keycode == 65363)
		change_frame((t_all *)param, 5, 1);
	else if (keycode == 65361)
		change_frame((t_all *)param, 5, 2);
	else if (keycode == 65362)
		change_frame((t_all *)param, 6, 1);
	else if (keycode == 65364)
		change_frame((t_all *)param, 6, 2);
	else if (keycode == 65307)
		escape_close(keycode, param);
	return (0);
}

t_all	*create_all(t_mlx *mlx, t_grid *grid, t_point *pts)
{
	t_all	*all;

	all = malloc(sizeof(t_all));
	all->mlx = mlx;
	all->grid = grid;
	all->pts = pts;
	return (all);
}

int	main(int ac, char **av)
{
	t_mlx	*mlx;
	t_grid	*grid;
	t_point	*pts;
	t_all	*all;

	if (ac == 2 && check_file(av[1]) == 1)
	{
		grid = create_grid(av[1]);
		pts = create_points(grid);
		mlx = malloc(sizeof(t_mlx));
		mlx->mlx = mlx_init();
		mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "fdf");
		all = create_all(mlx, grid, pts);
		new_iso(all);
		mlx_key_hook(mlx->win, key_handler, (void *)all);
		mlx_mouse_hook(mlx->win, mouse_handler, (void *)all);
		mlx_loop(mlx->mlx);
		mlx_destroy_display(mlx->mlx);
		free_all(all);
	}
}
