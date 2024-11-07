// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

#include "cub3d.h"

char		map[5][6] = {
	{'1', '1', '1', '1', '1', '\0'},
	{'1', '0', '0', '0', '1', '\0'},
	{'1', '0', '0', '0', '1', '\0'},
	{'1', '0', '0', '0', '1', '\0'},
	{'1', '1', '1', '1', '1', '\0'}
};

double deg_to_rad(double deg)
{
	while (deg > 360)
		deg /= 360;
	return (deg * M_PI / 180);
}

mlx_image_t	*draw_small_cube(mlx_t *mlx)
{
	int x = -1;
	int y = -1;
	mlx_image_t *new_cube = mlx_new_image(mlx, 10, 10);

	while (++y < 10)
	{
		while (++x < 10)
		{
			mlx_put_pixel(new_cube, x, y, 0x800080FF);
		}
		x = -1;
	}
	return (new_cube);
}

void	ft_put_pixel(mlx_t *mlx, int x, int y)
{
	mlx_image_t *pixel = mlx_new_image(mlx, 4, 4);

	mlx_put_pixel(pixel, 0, 0, 0x800080FF);
	mlx_put_pixel(pixel, 1, 0, 0x800080FF);
	mlx_put_pixel(pixel, 0, 1, 0x800080FF);
	mlx_put_pixel(pixel, 1, 1, 0x800080FF);
	mlx_image_to_window(mlx, pixel, x, y);
}

mlx_image_t	*draw_cube(mlx_t *mlx)
{
	int x = -1;
	int y = -1;
	mlx_image_t *new_cube = mlx_new_image(mlx, 64, 64);

	while (++y < 64)
	{
		while (++x < 64)
			mlx_put_pixel(new_cube, x, y, 0xFFFFFF);
		x = -1;
	}
	return (new_cube);
}

void	draw_v_line(mlx_t *mlx, mlx_image_t *img, int x, int max_y)
{
	int y = -1;
	mlx_image_t *pixel;

	pixel = mlx_new_image(mlx, 1, max_y);
	while (++y < max_y)
	{
		mlx_put_pixel(pixel, 0, y, 0xFFFFFF);
	}
	mlx_image_to_window(mlx, pixel, x, 0);
}

void	draw_h_line(mlx_t *mlx, mlx_image_t *img, int y, int max_x)
{
	int x = -1;
	mlx_image_t *pixel;

	pixel = mlx_new_image(mlx, max_x, 1);
	while (++x < max_x)
		mlx_put_pixel(pixel, x, 0, 0xFFFFFF);
	mlx_image_to_window(mlx, pixel, 0, y);
}

void	draw_grid(t_data *mlx)
{
	
	int map_y = 5;
	int map_x = 0;
	while(map[0][map_x])
		map_x++;
	
	int y = 64;
	int x = 0;

	while (y <= map_y * 64)
	{
		draw_h_line(mlx->mlx, mlx->img, y, map_x * 64);
		y += 64;
	}

	y = 0;
	x = 64;

	while (x <= map_x * 64)
	{
		draw_v_line(mlx->mlx, mlx->img, x, map_y * 64);
		x += 64;
	}
}

int32_t main(void)
{
	t_data	data;

	// Gotta error check this stuff
	if (!(data.mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(data.img = mlx_new_image(data.mlx, 128, 128)))
	{
		mlx_close_window(data.mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (mlx_image_to_window(data.mlx, data.img, 0, 0) == -1)
	{
		mlx_close_window(data.mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	draw_grid(&data);
	data.rad = deg_to_rad(90);
	data.player = draw_small_cube(data.mlx);
	mlx_image_to_window(data.mlx, data.player, 67, 157);
	data.px = data.player->instances[0].x;
	data.py = data.player->instances[0].y;
	data.rad = deg_to_rad(89);
	select_ray(&data);
	mlx_loop_hook(data.mlx, movement, &data);
	//mlx_loop_hook(data.mlx, north_ray, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (EXIT_SUCCESS);
}
