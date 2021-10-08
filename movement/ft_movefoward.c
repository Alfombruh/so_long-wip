#include "../so_long.h"

int ft_moveforward(t_solong *data)
{
	if(data->map[data->pjy - 1][data->pjx] != '1')
	{
		if(data->map[data->pjy - 1][data->pjx] == 'C')
		{
			data->collected++;
			printf("COLLECTED: %d/%d\n", data->collected, data->collectables);
		}
		if(data->map[data->pjy - 1][data->pjx] == 'E')
		{	
			if(data->collected != data->collectables)
					return(0);
			if(data->collected == data->collectables)
			{
				mlx_destroy_window(data->mlx, data->win);
			}
		}
		data->map[data->pjy][data->pjx] = 0;
		data->map[data->pjy - 1][data->pjx] = 'P';
		data->pjy--;
	}
	else 
		return(0);
	return (1);
}
