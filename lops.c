#include "so_long.h"

int move(int keycode, t_gen *gen)
{
	if(keycode == 13)
	{
		mlx_clear_window(gen->data.mlx, gen->data.win);
		gen->image.wid += 1;
		gen->image.hei += 1;
		mlx_put_image_to_window(gen->data.mlx, gen->data.win, gen->image.img, gen->image.wid, gen->image.hei);	
	}
	return(1);	
}

int main(void)
{
	t_gen	gen;
	char	*relative_path = "../../sample";

	gen.data.x = 960;
	gen.data.y = 540;
	gen.data.mlx = mlx_init();
	gen.data.win = mlx_new_window(gen.data.mlx, 1920, 1080, "Yeyeyey senda ye");
	gen.image.img = mlx_xpm_file_to_image(gen.data.mlx, relative_path, &gen.image.wid, &gen.image.hei);
	mlx_put_image_to_window(gen.data.mlx, gen.data.win, gen.image.img, gen.data.x, gen.data.y);
	mlx_hook(gen.data.win, 2, 1L<<0, move, &gen);
	mlx_loop(gen.data.mlx);
}
