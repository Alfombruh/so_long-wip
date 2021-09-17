#include "so_long.h"

int render_next_frame(void *img);

void my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char *dst;

	dst = img->addr + (y *img->line_len + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

int main()
{
	t_data mlx;
	t_image img;
	int color;
	int x;
	int y;
	
	color = 0x000000;
	x = 0;
	y = 0;
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 1920, 1080, "webOS");
	img.img = mlx_new_image(mlx.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	while(x != 1919)
	{
		my_mlx_pixel_put(&img, x, y, color);
		x++;
		while(y != 1079)
		{
			my_mlx_pixel_put(&img, x, y, color);
			if(x > 274 && x < 548) 
				color = 0xFF7F00;
			else if(x > 548 && x < 822)
				color = 0xFFFF0;
			else if(x > 822 && x < 1096)
				color = 0x00FF00;
			else if(x > 1096 && x < 1370)
				color = 0x0000FF;
			else if(x > 1370 && x < 1644)
				color = 0x2E2B5F;
			else if(x > 1644 && x < 1919)
				color = 0x8B00FF;	
			y++;
		}
		y = 0;
		mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
	}
	mlx_loop_hook(mlx.mlx, render_next_frame, &img);
	mlx_loop(mlx.mlx);
}
