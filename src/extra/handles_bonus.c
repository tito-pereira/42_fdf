/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handles_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:53:13 by tibarbos          #+#    #+#             */
/*   Updated: 2024/08/02 12:14:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf_bonus.h"

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
