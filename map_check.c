#include "so_long.h"

t_map	*ft_count_buffer_size(char *buffer, t_map *map)
{
	while(buffer[map->wide++] != '\0')
	{
		if (buffer[map->wide] == '\n')
			map->tall++;
	}
	map->wide = map->wide / map->tall;
	return(0);
}
//probar funcion pero en vez de avanzar en el i avanzar en el j por como esta la memoria alojada
//osea en vez de map[++i][j] que sea map [i][++j]
char **ft_fill(char **map, char *buffer)
{
	int i;
	int j;

	i = -1;
	j = 0;
	printf("bout to enter a while\n");
	while(*buffer != '\0')
	{
		printf("buffer char RN = %c\n", *buffer);
		printf("in the while\ti value: %d\tj value: %d\n", i, j); 
		if(*buffer == '\n')
		{
			printf("enters if\n");
			i = -1;
			buffer++;
			j++;
			printf("leaves if\n");
		}
		map[++i][j] = *buffer++;
		printf("\tchar %c\n", map[i][j]);
	}
	return (map);
}

char **ft_allocate(char	*buffer,int	wide, int tall)
{
	int i;
	char **map;
	
	i = 0;
	printf("hey, boutta enter a malloc here\n");
	printf("my width is:%d \t my height is:%d \t\n", wide, tall);
	map = malloc(sizeof(char) * tall);
	while(i < tall)
	{
		map[i] = malloc(sizeof(char) * wide);
		i++;
	}
	printf("\tMALLOC DONE!!!\n");
	return(map);
}

int main(int argc, char **argv)
{
	int fd;
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
	printf("%s\n", buffer);
	ft_count_buffer_size(buffer, &map);
	printf("map.wide = %d\tmap.tall = %d\t\n", map.wide, map.tall);
	mapa = ft_allocate(buffer, map.wide, map.tall);
	mapa = ft_fill(mapa, buffer);
	printf("We've finished\n");
	return(0);
}
