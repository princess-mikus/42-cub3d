/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:18:07 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/11/06 11:40:09 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char		map2[5][6] = {
	{'1', '1', '1', '1', '1', '\0'},
	{'1', '0', '0', '0', '1', '\0'},
	{'1', '0', '0', '0', '1', '\0'},
	{'1', '0', '0', '0', '1', '\0'},
	{'1', '1', '1', '1', '1', '\0'}
};

double	south_ray(t_data *data, double rad)
{
	int		x = data->player->instances->x;
	int		y = data->player->instances->y;
	int 	rayY;
	int		offY;
	int		rayX;
	int		offX;
	bool 	hit = false;

	rayY = ((y / 64) * 64);
	rayX = (y - rayY) * (-1 / -tan(rad)) + x;
	offY = -64;
	offX = offY * (-1 / tan(rad));
	printf("%d %d, %f\n", rayY, rayX, (-1 / -tan(rad)));
	mlx_image_to_window(data->mlx, draw_small_cube(data->mlx), rayX, rayY - 4);
	while (!hit)
	{
		if (map2[rayY / 64 - 1][rayX / 64] == '1')
		{
			hit = true;
			printf("%d %d\n", rayY, rayX);
			mlx_image_to_window(data->mlx, draw_small_cube(data->mlx), rayX, rayY - 4);
		}
		else
		{
			rayY += offY;
			rayX += offX;
			mlx_image_to_window(data->mlx, draw_small_cube(data->mlx), rayX, rayY - 4);
			printf("%d %d\n", rayY, rayX);
		}
	}
	return (sqrt((rayX - x) * (rayX - x) + (rayY - y) * (rayY - y)));
}

double	north_ray(t_data *data, double rad)
{
	int		x = data->player->instances->x;
	int		y = data->player->instances->y;
	int 	rayY;
	int		offY;
	int		rayX;
	int		offX;
	bool 	hit = false;

	rayY = ((y / 64) * 64);
	rayX = (y - rayY) * (-1 / -tan(rad)) + x;
	offY = 64;
	offX = offY * (-1 / tan(rad));
	printf("%d %d\n", rayY, rayX);
	mlx_image_to_window(data->mlx, draw_small_cube(data->mlx), rayX, rayY - 4);
	while (!hit)
	{
		if (map2[rayY / 64 - 1][rayX / 64] == '1')
		{
			hit = true;
			printf("%d %d\n", rayY, rayX);
			mlx_image_to_window(data->mlx, draw_small_cube(data->mlx), rayX, rayY - 4);
		}
		else
		{
			rayY += offY;
			rayX += offX;
			mlx_image_to_window(data->mlx, draw_small_cube(data->mlx), rayX, rayY - 4);
			printf("%d %d\n", rayY, rayX);
		}
	}
	return (sqrt((rayX - x) * (rayX - x) + (rayY - y) * (rayY - y)));
}

void	select_ray(t_data *data)
{
	double	v_ray;
	double	h_ray;
	double	angle;

	angle = deg_to_rad(92);

	if (angle > M_PI)
		h_ray = north_ray(data, angle);
	else
		h_ray = south_ray(data, angle);
/*
	angle = data->rad - deg_to_rad(120 / 2);

	while (angle < data->rad + deg_to_rad(120))
	{
		if (angle > NORTH && angle < SOUTH)
			h_ray = right_ray(data, angle);
		else
			h_ray = left_ray(data, angle);
		if (angle > RIGHT)
			v_ray = north_ray(data, angle);
		else
			v_ray = south_ray(data, angle);

		if (v_ray < h_ray)
			printf("Vertical wall closer!\n");
		else
			printf("Vertical wall closer!\n");
	}
	*/

	printf("%f\n", h_ray);
}
