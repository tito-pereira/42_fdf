#ifndef FDF_H
# define FDF_H

# include "../minilibx-linux/mlx.h"
# include <stdio.h> //colocar caseira
# include <stdlib.h>
# define	RED		0x00FF0000
# define	GREEN	0x0000FF00 //altitude acima de 0
# define	BLUE	0x000000FF //altitude abaixo de 0
# define	WHITE	0x00FFFFFF //grelha
# define	BLACK	0x00000000 //apagar pixel

typedef	struct	s_image {
	void	*ptr;
	char	*data;
	int	bpp;
	int	sline;
	int	endian;
}	t_image;

typedef	struct fdf {
	void	*mlx;
	void	*win;
	void	*img;
}	t_mlx;


void	write_image(t_image **img, int x, int y, int color);
void	img_av_central(t_image **img, char *n);
void	img_key_central(t_image **img, int n);

#endif