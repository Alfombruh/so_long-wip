#include "so_long.h"

static void ft_characterinfo(t_solong *data, int i, int j)
{
	data->pjx = j;
	data->pjy = i;
}

static void ft_exitinfo(t_solong *data, int i, int j)
{
	data->exitx = j;
	data->exity = i;
}

void ft_getdata(t_solong *data)
{
	int i;
	int j;
	
	i = 0;
	data->collectables = 0;
	while(i < data->tall)
	{
		j = 0;
		while(j < data->wide)
		{
			if(data->map[i][j] == 'P')
				ft_characterinfo(data, i, j);
			if(data->map[i][j] == 'C')
				data->collectables++;
			if(data->map[i][j] == 'E')
				ft_exitinfo(data, i, j);
			j++;
		}
		i++;
	}
}
