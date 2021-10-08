#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft/libft.h"
#include "mlx/mlx.h"

typedef struct s_solong
{
//mlx
	void	*mlx;
	void	*win;
	int 	x; //la posicion de la imagen en x
	int		y; //la posicion de la imagen en y
//image
	void	*img;
	void	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int 	imgx;
	int 	imgy;
//map
	int		tall;
	int		wide;
	char	**map;
	int		pjx;
	int 	pjy;
	int		exitx;
	int 	exity;
	int 	collectables;
//tiles
	char	*pj;
	char	*wall;
	char	*ttomaz;
	char	*money;
	char	*exit;
//others
	int 	collected;
	int 	moves;
}				t_solong;

//ft_map.c
void	map_check(char *map_name, t_solong *map);
//ft_errors.c
int ft_errors(int argc, t_solong data);
//ft_map.c
void ft_map(t_solong *data);
//ft_getdata
void ft_getdata(t_solong *data);
//movements
int ft_moveforward(t_solong *data);
int ft_movedown(t_solong *data);
int ft_moveleft(t_solong *data);
int ft_moveright(t_solong *data);

#endif
