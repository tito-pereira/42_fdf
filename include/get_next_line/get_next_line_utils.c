/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 10:40:52 by tibarbos          #+#    #+#             */
/*   Updated: 2023/10/20 14:44:31 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_find_n(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (-1);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char		*substr;
	size_t		i;

	i = 0;
	substr = malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	while (s[start] != '\0' && len > 0)
	{
		substr[i] = s[start];
		start++;
		i++;
		len--;
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!dest)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_new_chest(char *chest)
{
	int		i;
	int		j;
	int		n;
	char	*new;

	i = 0;
	n = 0;
	while (chest[i] != '\n')
	{
		i++;
		n++;
	}
	n++;
	j = 0;
	while (chest[i] != '\0')
	{
		i++;
		j++;
	}
	new = ft_substr(chest, n, j);
	free (chest);
	return (new);
}
