#ifndef LIB_H
# define LIB_H

# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>

#define screenWidth 1601
#define screenHeight 901

typedef struct s_player
{
	int		posX;
	int		posY;
	float	dirX;
	float	dirY;
	float	planeX;
	float	planeY;
	float	dir_angle;
	float	m_speed;
	float	r_speed;
}				t_player;

typedef struct	s_data
{
	int			ray_num;
	float		ray_len;
	float		ray_angX;
	float		ray_angY;
	int			ray_posX;
	int			ray_posY;
	float		hypoX;
	float		hypoY;
	int			mapW;
	int			mapH;
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	char		**world_map;
	t_player	p;
}				t_data;

void    draw_map(t_data *data, int color);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
char	*ft_strdup(char *s1);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *str);

#endif