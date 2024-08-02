/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substrr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:15:05 by tibarbos          #+#    #+#             */
/*   Updated: 2023/10/09 18:17:46 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlenn(const char *str)
{
	size_t	i;

	i = 0;
	while (((char *)str)[i] != '\0')
		i++;
	return (i);
}

char	*ft_sup(char *substr, char const *s, unsigned int start, size_t len)
{
	size_t	i;

	i = 0;
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

char	*ft_substrr(char const *s, unsigned int start, size_t len)
{
	char		*substr;

	if (len >= ft_strlenn(((char *)s)))
		len = ft_strlenn(((char *)s)) - start;
	if (start >= ft_strlenn(((char *)s)))
	{
		substr = malloc(1 * sizeof(char));
		substr[0] = '\0';
		return (substr);
	}
	else
		substr = malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	substr = ft_sup(substr, ((char *)s), start, len);
	return (substr);
}
