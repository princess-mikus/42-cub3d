// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <MLX42/MLX42.h>

#define M_PI 3.14159265358979323846
#define WIDTH 320
#define HEIGHT 320
#define FOV 64
int			pos[2] = {2, 2};
char		map[5][6] = {
	{'1', '1', '1', '1', '1', '\0'},
	{'1', '0', '0', '0', '1', '\0'},
	{'1', '0', '0', '0', '1', '\0'},
	{'1', '0', '0', '0', '1', '\0'},
	{'1', '1', '1', '1', '1', '\0'}
};

double deg_to_rad(int deg)
{
	while (deg > 360)
		deg /= 360;
	if (deg < 0)
		return (deg * (M_PI / 180));
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
			mlx_put_pixel(new_cube, x, y, 0xFFFFFF);
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
		{
			mlx_put_pixel(new_cube, x, y, 0xFFFFFF);
		}
		x = -1;
	}
	return (new_cube);
}

void	first_ray(mlx_t *mlx, mlx_image_t *img, int deg)
{
	int	x = 172;
	int	y = 129;
	double	rad = deg_to_rad(deg);
	bool 	hit = false;

	mlx_image_to_window(mlx, draw_small_cube(mlx), x - 4, y - 4);
	while (!hit)
	{
		int rayY = ((y / 64) * 64);
		int rayX = (x - rayY) / -tan(rad) + x;
		ft_put_pixel(mlx, rayX, rayY);
		if (map[rayY / 64 - 1][rayX / 64] == '1')
		{
			printf("Hit!\n");
			hit = true;
		}
		else
		{
			printf("No Hit!\n");
			y = rayY;
			x = rayX;
			hit = true;
		}
	}
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
	{
		mlx_put_pixel(pixel, x, 0, 0xFFFFFF);
	}
	mlx_image_to_window(mlx, pixel, 0, y);
}

void	draw_grid(mlx_t *mlx, mlx_image_t *img)
{
	int map_y = 5;
	int map_x = 0;
	while(map[0][map_x])
		map_x++;
	
	int y = 64;
	int x = 0;

	while (y <= map_y * 64)
	{
		draw_h_line(mlx, img, y, map_x * 64);
		y += 64;
	}

	y = 0;
	x = 64;

	while (x <= map_x * 64)
	{
		draw_v_line(mlx, img, x, map_y * 64);
		x += 64;
	}
}

int32_t main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	// Gotta error check this stuff
	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(img = mlx_new_image(mlx, 128, 128)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, img, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	draw_grid(mlx, img);
	int deg = 20;
	while (deg < 40)
		first_ray(mlx, img, deg++);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
