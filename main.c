#include "lib.h"

int	key_event(int key_code, void *param)
{
	t_data	*m;

	m = param;
	if (key_code == 53)
		exit(0);
	else if (key_code == 1)
	{
		printf("S\n");
		if (m->world_map[((m->p.posY - 50) / 100) + 1][(m->p.posX - 50) / 100] == 0)
		{
			my_mlx_pixel_put(m, m->p.posX, m->p.posY + m->p.m_speed, 0xFF0000);
			my_mlx_pixel_put(m, m->p.posX, m->p.posY, 0x000000);
			m->p.posY += m->p.m_speed;
			mlx_put_image_to_window(m->mlx, m->mlx_win, m->img, 0, 0);
		}
	}
	else if (key_code == 2)
	{
		printf("D\n");
		if (m->world_map[(m->p.posY - 50) / 100][((m->p.posX - 50) / 100) + 1] == 0)
		{
			my_mlx_pixel_put(m, m->p.posX + m->p.m_speed, m->p.posY, 0xFF0000);
			my_mlx_pixel_put(m, m->p.posX, m->p.posY, 0x000000);
			m->p.posX += m->p.m_speed;
			mlx_put_image_to_window(m->mlx, m->mlx_win, m->img, 0, 0);
		}
	}
	else if (key_code == 13)
	{
		printf("W\n");
		if (m->world_map[((m->p.posY - 50) / 100) - 1][(m->p.posX - 50) / 100] == 0)
		{
			my_mlx_pixel_put(m, m->p.posX, m->p.posY - m->p.m_speed, 0xFF0000);
			my_mlx_pixel_put(m, m->p.posX, m->p.posY, 0x000000);
			m->p.posY -= m->p.m_speed;
			mlx_put_image_to_window(m->mlx, m->mlx_win, m->img, 0, 0);
		}
	}
	else if (key_code == 0)
	{
		printf("A\n");
		if (m->world_map[(m->p.posY - 50) / 100][((m->p.posX - 50) / 100) - 1] == 0)
		{
			my_mlx_pixel_put(m, m->p.posX - m->p.m_speed, m->p.posY, 0xFF0000);
			my_mlx_pixel_put(m, m->p.posX, m->p.posY, 0x000000);
			m->p.posX -= m->p.m_speed;
			mlx_put_image_to_window(m->mlx, m->mlx_win, m->img, 0, 0);
		}
	}
	else if (key_code == 124)
		printf("->\n");
	else if (key_code == 123)
		printf("<-\n");
	return (1);
}

void	draw_vertical(void *param)
{
	t_data	*m;
	int		i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	m = param;
	start = 450 + m->ray_len / 2;
	start = 900 - start;
	while (j < 10)
	{
		while (i < m->ray_len)
		{
			my_mlx_pixel_put(m, j, start + i, 0x0000FF);
			i ++;
		}
		i = 0;
		j ++;
	}
	mlx_put_image_to_window(m->mlx, m->mlx_win, m->img, 0, 0);
}

void	draw_walls(void *param)
{
	t_data	*m;
	int		i;

	i = 0;
	m = param;
	m->ray_len = 200;
	while (i < 100)
	{
		m->ray_num = i;
		// calcular el m->ray_len
		draw_vertical(m);
		i ++;
	}
}

void	draw_sky_floor(void *param)
{
	t_data	*m;
	int		i;
	int		j;

	i = 0;
	j = 0;
	m = param;
	while (j < 900)
	{
		while (i < 1600)
		{
			if (j < 450)
				my_mlx_pixel_put(m, i, j, 0x99CCFF);
			else
				my_mlx_pixel_put(m, i, j, 0x828282);
			i ++;
		}
		i = 0;
		j ++;
	}
	mlx_put_image_to_window(m->mlx, m->mlx_win, m->img, 0, 0);
}

int main()
{
    t_data	m;

	m.mapW = 16;
	m.mapH = 9;
	m.p.posX = 150;
	m.p.posY = 150;
	m.p.m_speed = 100;
	m.p.r_speed = 45; //grados
	m.p.dirX = 0;
	m.p.dirY = -1;
	m.p.dir_angle = 270;

	m.mlx = mlx_init();
	m.mlx_win = mlx_new_window(m.mlx, screenWidth, screenHeight, "Raycaster");
	m.img = mlx_new_image(m.mlx, screenWidth, screenHeight);
	m.addr = mlx_get_data_addr(m.img, &m.bits_per_pixel, &m.line_length, &m.endian);
    draw_sky_floor(&m);
	draw_map(&m, 0xFFFFFF);
	my_mlx_pixel_put(&m, m.p.posX, m.p.posX, 0xFF0000);
	draw_walls(&m);
	mlx_put_image_to_window(m.mlx, m.mlx_win, m.img, 0, 0);
	mlx_key_hook(m.mlx_win, &key_event, &m);
	mlx_loop(m.mlx);
}