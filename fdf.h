#ifndef FDF_H
# define FDF_H

# include "../minilibx-linux/mlx.h"
# include <stdio.h> //colocar caseira
# include <stdlib.h>
# define	RED		0x00FF0000
# define	GREEN	0x0000FF00 //altitude acima de 0
# define	BLUE	0x000000FF //altitude abaixo de 0
# define	WHITE	0x00FFFFFF //grelha

typedef	struct	s_image {
	void	*ptr;
	char	*data;
	int	bpp;
	int	sline;
	int	endian;
}	t_image;

void	write_image(t_image **img, int x, int y, int color);

#endif