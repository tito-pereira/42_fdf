/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 10:41:05 by tibarbos          #+#    #+#             */
/*   Updated: 2023/10/20 14:45:23 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char	**ft_split(char const *s1, char c);
char	*ft_substrr(char const *s, unsigned int start, size_t len);
size_t	ft_strlenn(const char *str);
int		ft_atoi(const char *str);
char    *ft_strcpy(char *pts);

#endif
