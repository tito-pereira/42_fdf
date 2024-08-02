/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:39:18 by tibarbos          #+#    #+#             */
/*   Updated: 2024/08/02 12:17:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

int	count_rows(char **points)
{
	int	i;

	i = 0;
	while (points[i] != NULL)
		i++;
	return (i);
}

t_heights	*new_heights_node(char **str)
{
	t_heights	*new;

	new = malloc(sizeof(t_heights));
	new->line = str;
	new->next = NULL;
	return (new);
}

t_lines	*new_lines_node(char *str)
{
	t_lines	*new;

	new = malloc(sizeof(t_lines));
	new->line = str;
	new->next = NULL;
	return (new);
}

int	check_file(char *name)
{
	int	i;

	i = 0;
	while (name[i] != '\0')
		i++;
	if (name[i - 1] == 'f' && name[i - 2] == 'd' && name[i - 3] == 'f'
		&& name[i - 4] == '.')
		return (1);
	return (0);
}
