/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:46:12 by tibarbos          #+#    #+#             */
/*   Updated: 2024/08/02 12:14:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf_bonus.h"

int	close_all(void *param)
{
	t_all	*all;

	all = (t_all *)param;
	mlx_destroy_image(all->mlx->mlx, all->mlx->img);
	mlx_destroy_window(all->mlx->mlx, all->mlx->win);
	mlx_loop_end(all->mlx->mlx);
	return (0);
}

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
		mlx_hook(mlx->win, 17, 0, close_all, (void *)all);
		mlx_loop(mlx->mlx);
		mlx_destroy_display(mlx->mlx);
		free_all(all);
	}
}
