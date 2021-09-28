#include "so_long.h"

char **ft_fill(char	*buffer,char **map, int wide, int tall)
{
	int i;
	int j;
	int k;
	map = (char *)malloc(sizeof(char) * tall);
	while(*buffer != '\0');
	{
		*map = malloc(sizeof(char) * wide);


	}
}

int main(int argc, char **argv)
{
	int fd;
	int	tall;
	int	wide;
	char **map;
	char *buffer;
	
	wide = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("Error al leer el mapa");
		return(0);
	}
	tall = 1;
	buffer = (char *) malloc(sizeof(char) * 5000);
	read(fd, buffer, 5000);
	printf("%s\n", buffer);
	printf("outta while1\	n");
	while(buffer[wide++] != '\0')
	{
		if(buffer[wide] == '\n')
			tall++;
	}
	wide = wide / tall;
	wide = wide - 1;
	map = ft_fill(buffer, map, wide, tall);
	printf("wide: %d\n", wide);
	printf("tall: %d\n", tall);
	printf("outta while2\n");
	return(0);
}
