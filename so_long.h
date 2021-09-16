#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft/libft.h"
#include "mlx/mlx.h"

typedef struct s_data
{
	void	*mlx;
	void	*win;
}				t_data;

typedef struct s_image
{
	void *img;
	void *addr;
	int bpp;
	int line_len;
	int endian;
}			t_image;

#endif
