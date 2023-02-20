#ifndef LIB_H
# define LIB_H

# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>

#define screenWidth 1601
#define screenHeight 901
#define mapWidth 16
#define mapHeight 9

typedef struct s_player
{
	int		posX;
	int		posY;
	double	direction_angle;
	double	speed;
	double	rot_speed;
}				t_player;

typedef struct	s_data
{
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_player	p;
}				t_data;

void    draw_map(t_data *data, int color);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif