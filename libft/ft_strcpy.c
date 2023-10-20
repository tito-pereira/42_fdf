/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:41:58 by tibarbos          #+#    #+#             */
/*   Updated: 2023/10/20 18:43:12 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *pts)
{
	char	*new;
	size_t	j;

	new = malloc((ft_strlenn(pts) + 1) * sizeof(char));
	j = 0;
	while (pts[j] != '\0')
	{
		new[j] = pts[j];
		j++;
	}
	new[j] = '\0';
	return (new);
}
