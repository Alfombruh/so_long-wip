#include "so_long.h"

void my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char *dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}
void img_initialize(t_image *data)
{
	data->bpp = 10;
	data->line_len = 10;
}
int main()
{
	t_data data;
	t_image img;
	int color;
	int x = 0;
	int y = 0;
	color = 0x0000FF;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1920, 1080, "MESSI BOCADILLO DE CHORIZO: EL VIDEOJUEGO!");
	img.img = mlx_new_image(data.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	//img_initialize(&img);
	my_mlx_pixel_put(&img, x, y, color);
	mlx_put_image_to_window(data.mlx, data.win, img.img, 960, 540);
	mlx_loop(data.mlx);
}
