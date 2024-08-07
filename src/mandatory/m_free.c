/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_free.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:37:13 by tibarbos          #+#    #+#             */
/*   Updated: 2024/08/02 12:16:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	free_all(t_all *all)
{
	t_point	*tmp;

	tmp = NULL;
	free (all->grid->heights);
	free (all->grid);
	while (all->pts != NULL)
	{
		tmp = all->pts->next;
		free (all->pts);
		all->pts = tmp;
	}
	free (all->mlx->mlx);
	free (all->mlx);
	free (all);
}

void	free_count(t_count *count)
{
	t_count	*tmp;

	tmp = NULL;
	while (count != NULL)
	{
		tmp = count->nxt;
		free (count);
		count = tmp;
	}
}

void	free_ds(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free (str[i]);
		i++;
	}
	free (str[i]);
}

void	free_grid(t_heights *heights, t_lines *lines)
{
	t_heights	*tmp;
	t_lines		*temp;

	tmp = NULL;
	temp = NULL;
	while (lines != NULL)
	{
		temp = lines->next;
		free (lines->line);
		free (lines);
		lines = temp;
	}
	while (heights != NULL)
	{
		tmp = heights->next;
		free_ds(heights->line);
		free (heights->line);
		free (heights);
		heights = tmp;
	}
}

void	free_mat(t_trimat *m)
{
	free(m->r);
	free(m->l);
	free(m->s);
	free(m);
}
