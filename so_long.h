#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft/libft.h"
#include "mlx/mlx.h"

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
