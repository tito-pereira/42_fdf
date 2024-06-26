/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 13:15:23 by tibarbos          #+#    #+#             */
/*   Updated: 2023/10/20 18:45:33 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_safe(char *shovel, char *chest)
{
	int		i;
	int		j;
	int		k;
	char	*safe;

	if (!chest || chest == NULL)
	{
		chest = (char *)malloc(1 * sizeof(char));
		chest[0] = '\0';
	}
	j = ft_strlen(chest);
	safe = (char *)malloc((ft_strlen(shovel) + j + 1) * sizeof(char));
	if (safe == NULL)
		return (NULL);
	i = -1;
	while (chest[++i] != '\0')
		safe[i] = chest[i];
	k = -1;
	while (shovel[++k] != '\0')
		safe[i++] = shovel[k];
	safe[i] = '\0';
	free (chest);
	return (safe);
}

char	*ft_sup_read(int x, char *chest)
{
	if (x == 0 && chest[0] == '\0')
	{
		free (chest);
		return (NULL);
	}
	return (chest);
}

char	*ft_to_read(int fd, char *chest)
{
	int		x;
	int		n;
	char	*shovel;

	x = 1;
	n = -1;
	shovel = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	while ((x != 0) && (n < 0))
	{
		x = read(fd, shovel, BUFFER_SIZE);
		if (x == -1)
		{
			if (chest)
				free (chest);
			free (shovel);
			return (NULL);
		}
		shovel[x] = '\0';
		chest = ft_safe(shovel, chest);
		n = ft_find_n(chest);
	}
	free (shovel);
	return (ft_sup_read(x, chest));
}

char	*ft_free_chest(char *chest)
{
	free (chest);
	chest = NULL;
	return (chest);
}

char	*get_next_line(int fd)
{
	static char	*chest;
	char		*loot;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (chest && ft_find_n(chest) > 0)
	{
		loot = ft_substr(chest, 0, ft_find_n(chest));
		chest = ft_new_chest(chest);
		return (loot);
	}
	chest = ft_to_read(fd, chest);
	if (chest == NULL)
		return (NULL);
	if (chest && ft_find_n(chest) > 0)
	{
		loot = ft_substr(chest, 0, ft_find_n(chest));
		chest = ft_new_chest(chest);
		return (loot);
	}
	loot = ft_strdup(chest);
	chest = ft_free_chest(chest);
	return (loot);
}
