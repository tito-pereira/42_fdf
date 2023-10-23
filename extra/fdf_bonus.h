/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:48:49 by tibarbos          #+#    #+#             */
/*   Updated: 2023/10/23 17:54:18 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include "../mandatory/fdf.h"

void		change_frame(t_all *all, int function, int order);
void		move_cam(t_all *all, int order);
void		zoom(t_all *all, int order);
void		planar(t_all *all, int order);
void		rotate(t_all *all, int order);
void		incline(t_all *all, int order);
t_matrix	*r_matrix(t_point *pts);
t_matrix	*l_matrix(t_point *pts, t_grid *grid);
// handles
int			mouse_handler(int button, int x, int y, void *param);
int			key_handler(int keycode, void *param);
int			escape_close(int keycode, void *param);

#endif
