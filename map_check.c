#include "so_long.h"

static int ft_count_buffer_size(char *buffer, t_solong *map)
{
	int tomasturba;

	map->wide =  0;
	map->tall = 1;
	tomasturba = 0;

	while(buffer[map->wide] != '\0')
	{
		if (buffer[map->wide] == '\n')
		{
			if (map->tall == 1)
				tomasturba = map->wide;
			else
			{
					if ((map->wide - (map->tall - 1)) - (tomasturba * (map->tall - 1)) != tomasturba)
					return (0);
			}	
			map->tall++;
		}
		map->wide++;
	}
	map->wide = tomasturba;
	return (1);
}

static	char **ft_fill(char *buffer, char **map, int tall, int wide)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;

	while(i < tall)
	{
		j = 0;
		while(j < wide)
		{
			map[i][j] = buffer[k++];
			j++;
		}
		map[i][j] = '\0';
		i++;
		k++;
	}
	return(map);
}

static	char **ft_allocate(int	wide, int tall)
{
	int i;
	char **map;
	
	i = 0;
	map = malloc(sizeof(char *) * (tall + 1));
	while(i < tall)
	{
		map[i] = malloc(sizeof(char) * (wide + 1));
		i++;
	}
	map[i] = 0;
	return(map);
}

void map_check(char *argv, t_solong *map)
{
	int fd;
	char *buffer;
	
	map->wide = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		printf("Error al leer el mapa");
		return ;
	}
	map->tall = 1;
	buffer = (char *) malloc(sizeof(char) * 5000);
	read(fd, buffer, 5000);
	if (ft_count_buffer_size(buffer, map) == 0)
	{
		printf("MAP ERROR NOT RECTANGULAR\n");
		printf("%d \n %d \n", map->tall, map->wide);
		return ;
	}
	map->map = ft_allocate(map->wide, map->tall);
	map->map = ft_fill(buffer, map->map, map->tall, map->wide);
	free(buffer);
}
