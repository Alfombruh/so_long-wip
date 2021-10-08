#include "so_long.h"

static int ft_maperror(char **map, int wide, int tall)
{
	(void) wide;
	(void) tall;

	if(map[0][0] != 1)
		return(1);
	return(0);
}

int ft_errors(int argc, t_solong data)
{
	if(argc < 2 || argc > 2)
		printf("remember, remember salpeper");
	/*
	if(ft_maperror(data.map, data.wide, data.tall))
		return(1);
	*/
	return (0);
}
