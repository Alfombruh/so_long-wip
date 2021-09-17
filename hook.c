#include "so_long.h"

int key_hook(int keycode)
{

	printf("The keycode of the key tha's being pressed is: %d\n", keycode);
	return (0);
}

int sexx(int keycode, t_data *vars)
{
	(void) keycode;
	(void) vars;

	printf("me follo a tu madre y me voy sin pagar\n");
	return (2);
}

int closse(int keycode, t_data *vars)
{
	if(keycode == 53)
		mlx_destroy_window(vars->mlx, vars->win);
	else
		printf("The keycode of the key that's being pressed is: %d\n", keycode);
	return (1);
}

int main()
{
	t_data vars; 

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "GUILLERMO PEREA VIDEOJUEGO");
	mlx_hook(vars.win, 7, 1L<<4, sexx, &vars);
	mlx_hook(vars.win, 2, 1L<<0, closse, &vars);
	mlx_loop(vars.mlx);
}
