#include "so_long.h"

void ft_windowput(t_solong *data, char c)
{
	data->img = mlx_xpm_file_to_image(data->mlx, "./tiles/grass.xpm", &data->imgx, &data->imgy);
	mlx_put_image_to_window(data->mlx, data->win, data->img, data->x * 64, data->y * 64);
	if(c == '1')
	{
		data->img = mlx_xpm_file_to_image(data->mlx, "./tiles/wall.xpm", &data->imgx, &data->imgy);
		mlx_put_image_to_window(data->mlx, data->win, data->img, data->x * 64, data->y * 64);
	}
	if(c == 'C')
	{
		data->img = mlx_xpm_file_to_image(data->mlx, "./tiles/money.xpm", &data->imgx, &data->imgy);
		mlx_put_image_to_window(data->mlx, data->win, data->img, data->x * 64, data->y * 64);
	}
	if(c == 'P')
	{
		data->img = mlx_xpm_file_to_image(data->mlx, "./tiles/anthony.xpm", &data->imgx, &data->imgy);
		mlx_put_image_to_window(data->mlx, data->win, data->img, data->x * 64, data->y * 64);
	}
	if(c == 'E')
	{
		data->img = mlx_xpm_file_to_image(data->mlx, "./tiles/exit.xpm", &data->imgx, &data->imgy);
		mlx_put_image_to_window(data->mlx, data->win, data->img, data->x * 64, data->y * 64);
	}
}

static void ft_printmap(t_solong *data)
{
	int i;
	int j;

	i = 0;
	while(i < data->tall)
	{
		j = 0;
		while(j	< data->wide)
		{
			data->y = i;
			data->x = j;
			ft_windowput(data, data->map[i][j]);
			j++;
		}
		i++;
	}
}

static	int	ft_movements(int keycode, t_solong *data)
{
	if(keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
	{	
		mlx_clear_window(data->mlx, data->win);
		if(keycode == 13)
			data->moves += ft_moveforward(data);
		if(keycode ==  0)
			data->moves += ft_moveleft(data);
		if(keycode == 1)
			data->moves += ft_movedown(data);
		if (keycode == 2)
			data->moves += ft_moveright(data);
		ft_printmap(data);
		printf("TOTAL MOVES: %d\n", data->moves);
	}
	else
		printf("movement keys are WASD\n");
	return (0);
}

void	ft_map(t_solong *data)
{
	data->moves = 0;
	data->collected = 0;
	data->mlx =	mlx_init();
	data->win = mlx_new_window(data->mlx, (64 * data->wide), (64 * data->tall), "MARIO BROS 2");
	ft_printmap(data);
	mlx_hook(data->win, 2, 1L<<0, ft_movements, data);
	mlx_loop(data->mlx);
}	
