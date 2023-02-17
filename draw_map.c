#include "lib.h"

int worldMap[mapHeight][mapWidth]=
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1},
	{1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1},
	{1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1},
	{1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void    draw_unit_square(t_data *data, int mapX, int mapY, int color)
{
	int i;

	mapX *= 100;
	mapY *= 100;
	i = 0;
	while (i < 100)
	{
		my_mlx_pixel_put(data, mapX + i, mapY, color);
		my_mlx_pixel_put(data, mapX, mapY + i, color);
		my_mlx_pixel_put(data, mapX + 100, mapY + i, color);
		my_mlx_pixel_put(data, mapX + i, mapY + 100, color);
		i ++;
	}
}

void    draw_map(t_data *data, int color)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < mapHeight)
	{
		while (i < mapWidth)
		{
			if (worldMap[j][i] == 1)
				draw_unit_square(data, i, j, color);
			i ++;
		}
		i = 0;
		j ++;
	}
}