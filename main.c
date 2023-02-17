#include "lib.h"

int	key_event(int key_code, void *param)
{
	t_data	*m;

	m = param;
	if (key_code == 53)
		exit(0);
	else if (key_code == 1)
		printf("S\n");
	else if (key_code == 2)
		printf("D\n");
	else if (key_code == 13)
		printf("W\n");
	else if (key_code == 0)
		printf("A\n");
	else if (key_code == 124)
		printf("->\n");
	else if (key_code == 123)
		printf("<-\n");
	else
		printf("-> %d\n", key_code);
	return (1);
}

int main()
{
    t_data	m;

	m.mlx = mlx_init();
	m.mlx_win = mlx_new_window(m.mlx, screenWidth, screenHeight, "Raycaster");
	m.img = mlx_new_image(m.mlx, screenWidth, screenHeight);
	m.addr = mlx_get_data_addr(m.img, &m.bits_per_pixel, &m.line_length, &m.endian);
    draw_map(&m, 0xFFFFFF);
	mlx_put_image_to_window(m.mlx, m.mlx_win, m.img, 0, 0);
	mlx_key_hook(m.mlx_win, &key_event, &m);
	mlx_loop(m.mlx);
}