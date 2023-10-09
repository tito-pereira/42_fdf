#include "fdf.h"

void	image_1(t_image *img) {
	for (int x = 300; x <= 500; x++) {
		for (int y = 200; y <= 400; y++)
			write_image(img, x, y, GREEN);
	}
}

void	image_2(t_image *img) {
	for (int x = 300; x <= 500; x++) {
		for (int y = 200; y <= 400; y++)
			write_image(img, x, y, RED);
	}
}

void	image_3(t_image *img) {
	for (int x = 300; x <= 500; x++) {
		for (int y = 200; y <= 400; y++)
			write_image(img, x, y, BLUE);
	}
}

void	image_4(t_image *img) {
	for (int x = 300; x <= 500; x++) {
		for (int y = 200; y <= 400; y++)
			write_image(img, x, y, WHITE);
	}
}

void	img_av_central(t_image *img, char *n) {
	if (n[0] == '1')
		image_1(img);
	else if (n[0] == '2')
		image_2(img);
	else if (n[0] == '3')
		image_3(img);
	else if (n[0] == '4')
		image_4(img);
}

void	img_key_central(t_image *img, int n) {
	if (n == 1)
		image_1(img);
	else if (n == 2)
		image_2(img);
	else if (n == 3)
		image_3(img);
	else if (n == 4)
		image_4(img);
}