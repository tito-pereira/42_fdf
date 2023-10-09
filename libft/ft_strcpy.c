#include "libft.h"

char    *ft_strcpy(char *pts)
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