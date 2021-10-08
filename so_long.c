#include "so_long.h"

int main(int argc, char **argv)
{
	t_solong data;

	map_check(argv[1], &data);
	ft_errors(argc, data);
	ft_getdata(&data);
	ft_map(&data);
	return(0);
}
