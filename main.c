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

int main()
{
    t_data	m;

	m.p.posX = 150;
	m.p.posY = 150;
	m.p.m_speed = 100;
	m.p.r_speed = 0.5;
	m.p.dirX = 0;
	m.p.dirY = -1;

	m.mlx = mlx_init();
	m.mlx_win = mlx_new_window(m.mlx, screenWidth, screenHeight, "Raycaster");
	m.img = mlx_new_image(m.mlx, screenWidth, screenHeight);
	m.addr = mlx_get_data_addr(m.img, &m.bits_per_pixel, &m.line_length, &m.endian);
    draw_map(&m, 0xFFFFFF);
	my_mlx_pixel_put(&m, m.p.posX, m.p.posX, 0xFF0000);
	mlx_put_image_to_window(m.mlx, m.mlx_win, m.img, 0, 0);
	mlx_key_hook(m.mlx_win, &key_event, &m);
	mlx_loop(m.mlx);
}