#include "fdf.h"

void	write_image(t_image *img, int x, int y, int color)
{
	int i;
	int	*paint;

	i = 0;
	if ((x > 0 && x < WIDTH) && (y > 0 && y < HEIGHT)) {
		img->data = mlx_get_data_addr(img->ptr, &img->bpp, &img->sline, &img->endian);
		i = (y * (img->sline / 4)) + x;
		paint = (int *)(img->data);
		paint[i - 1] = color;
	}
}

int	nmb_module(int x)
{
	if (x < 0)
		x *= -1;
	return (x);
}

int	signal(int x)
{
	int	signal;

	signal = 1;
	if (x < 0)
		signal *= -1;
	if (x == 0)
		signal = 0;
	return (signal);
}

/*
yb - ya / xb - xa

sline = 3200 (800 * 4)
300(linhas) * 800(bytes por linha) = 240000
i = 240400
x = 400 (quero andar 400 pixeis)

img->data == (char *)img.data
(int *)img.data ta certo
(int *)(char *)img.data ta errado
img->data[i] == *(img->data + i)
no entanto (int *)img->data[i], tem que ser *(int *)img->data[i]
tou a dereferenciar primeiro, img->data[i] e um char (derefereniado)
e eu tou a fazer (int *)char o que nao existe
so podes typecast pointers como pointers, e char/ints
so, img->data[i] dereferences it, but (img->data + i) does not, it just indicates the pointer
only if i did *(img->data + i) i would dereference it
y = 300;
(y * sline) - bytes || (y * (sline / 4)) - bits
x = 400;
x (32 bpp, 4 byte pixel model)
preciso de saber se sline vem em bits ou bytes, testar
se for em bytes, faco int *
se for em bits, faco unsigned int *

img->data = (unsigned char *)img->data; (byte a byte)
i / 4 , porque vou iterar em int *

ou mudo a cor individualmente, ou dou cast como int *
*/

/*a funcao pede nos int* para um simples numero, o que
signfica que é suposto passarmos a morada e eles preenchem automatico
aquelas informações*/
/*crio uma struct porque sao conjuntos de informações que vao estar
sempre associados a uma só imagem
cor vem em valor de integer no formato hexadecimal
*/

/*
criar funcao de draw between points
*/