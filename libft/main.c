#include "libft.h"
#include <stdio.h>

int	main()
{
	char	**new;
	int	i = 0;
	new = ft_split("this is a test phrase with more words", ' ');
	while (new[i] != NULL) {
		if (new[i] == NULL)
			printf("null");
		else
			printf("%s\n", new[i]);
		free(new[i]);
		i++;
	}
	free (new);
}
