#include "so_long.h"

t_map	*ft_count_buffer_size(char *buffer, t_map *map)
{
	while(buffer[map->wide++] != '\0')
	{
		if (buffer[map->wide] == '\n')
			map->tall++;
	}
	map->wide = map->wide / map->tall - 1; 
	return(0);
}


char **ft_fill(char *buffer, char **map, int tall, int wide)
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

/*char **ft_fill(char *buffer, char **map, int tall, int wide)
{
	int i;
	int j;

	i = 0;
	j = 0; 
	while(*buffer != '\0')
	{
		if(*buffer == '\n')
		{
			i++;
			j = 0;
			buffer++;
		}
		map[i][j++] = *buffer++;
	}
	return(map);
}*/

char **ft_allocate(char	*buffer,int	wide, int tall)
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
	printf("\t\tMALLOC DONE!!!\n");
	return(map);
}

int main(int argc, char **argv)
{
	int fd;
	int i;
	t_map map;
	char **mapa;
	char *buffer;
	
	map.wide = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("Error al leer el mapa");
		return(0);
	}
	map.tall = 1;
	buffer = (char *) malloc(sizeof(char) * 5000);
	read(fd, buffer, 5000);
	//buffer[map.wide + map.tall + 1] = '\0';
	printf("%s\n", buffer);
	ft_count_buffer_size(buffer, &map);
	printf("map.wide = %d\tmap.tall = %d\t\n", map.wide, map.tall);
	mapa = ft_allocate(buffer, map.wide, map.tall);
	mapa = ft_fill(buffer, mapa, map.tall, map.wide);
	while(mapa[i])
		printf("\t%s\n", mapa[i++]);
	return(0);
}
