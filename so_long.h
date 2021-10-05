#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft/libft.h"
#include "mlx/mlx.h"

char **map_check(char *map_name);
char **ft_allocate(char *buffer, int wide, int tall);
char **ft_fill(char *buffer, char **map, int tall, int wide);
t_map *ft_count_buffer_size(char *buffer, t_map *map);

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int x;
	int y;
}				t_data;

typedef struct s_image
{
	void *img;
	void *addr;
	int bpp;
	int line_len;
	int endian;
	int wid;
	int hei;
}			t_image;

typedef struct s_map
{
	int tall;
	int wide;
}			t_map;

typedef struct s_gen
{
	t_image	image;
	t_data	data;
}		t_gen;

#endif
