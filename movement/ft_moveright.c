#include "../so_long.h"

int ft_moveright(t_solong *data)
{
	if(data->map[data->pjy][data->pjx + 1] != '1')
	{
		if(data->map[data->pjy][data->pjx + 1] == 'C')
		{	
			data->collected++;
			printf("COLLECTED: %d/%d\n", data->collected, data->collectables);
		}
		if(data->map[data->pjy][data->pjx + 1] == 'E')
		{
			if(data->collected != data->collectables)
				return(0);
			if(data->collected == data->collectables)
				mlx_destroy_window(data->mlx, data->win);
		}
		data->map[data->pjy][data->pjx] = 0;
		data->map[data->pjy][data->pjx + 1] = 'P';
		data->pjx++;
	}
	else
		return (0);
	return (1);
}