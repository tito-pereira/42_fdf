/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_write.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:39:40 by tibarbos          #+#    #+#             */
/*   Updated: 2023/10/20 19:01:17 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	write_image(t_image *img, int x, int y, int color)
{
	int		i;
	int		*paint;

	i = 0;
	if ((x > 0 && x < WIDTH) && (y > 0 && y < HEIGHT))
	{
		img->data = mlx_get_data_addr(img->ptr, &img->bpp, &img->sl, &img->ed);
		i = (y * (img->sl / 4)) + x;
		paint = (int *)(img->data);
		paint[i - 1] = color;
	}
}

int	nmb_module(int x)
{
	if (x < 0)
		x *= -1;
	return (x);
}

int	signal(int x)
{
	int	signal;

	signal = 1;
	if (x < 0)
		signal *= -1;
	if (x == 0)
		signal = 0;
	return (signal);
}
