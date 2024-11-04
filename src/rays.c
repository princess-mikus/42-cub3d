/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:18:07 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/11/04 12:53:19 by fcasaubo         ###   ########.fr       */
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
	int		rayX;
	bool 	hit = false;

	while (!hit)
	{
		rayY = ((y / 64) * 64);
		rayX = (x + rayY) / -tan(rad) + x;
		if (map2[rayY / 64 - 1][rayX / 64] == '1')
			hit = true;
		else
		{
			y = rayY;
			x = rayX;
		}
	}
	return (sqrt((rayX - data->player->instances->x) * (rayX - data->player->instances->x) + (rayY - data->player->instances->y) * (rayY - data->player->instances->y)));
}

double	north_ray(t_data *data, double rad)
{
	int		x = data->player->instances->x;
	int		y = data->player->instances->y;
	int 	rayY;
	int		rayX;
	bool 	hit = false;

	while (!hit)
	{
		rayY = ((y / 64) * 64);
		rayX = (x - rayY) / -tan(rad) + x;
		if (map2[rayY / 64 - 1][rayX / 64] == '1')
			hit = true;
		else
		{
			y = rayY;
			x = rayX;
		}
	}
	return (sqrt((rayX - data->player->instances->x) * (rayX - data->player->instances->x) + (rayY - data->player->instances->y) * (rayY - data->player->instances->y)));
}

void	select_ray(t_data *data)
{
	double	v_ray;
	double	h_ray;
	double	angle;

	angle = deg_to_rad(180);
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

	printf("%f %f\n", north_ray(data, deg_to_rad(90)), south_ray(data, deg_to_rad(180)));
}
