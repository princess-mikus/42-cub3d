/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:18:07 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/11/28 13:03:02 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char		map2[10][11] = {
	{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '\0'},
	{'1', '0', '0', '0', '0', '0', '0', '0', '0', '1', '\0'},
	{'1', '0', '0', '0', '0', '0', '0', '0', '0', '1', '\0'},
	{'1', '0', '0', '0', '0', '0', '0', '0', '0', '1', '\0'},
	{'1', '0', '0', '0', '0', '0', '0', '0', '0', '1', '\0'},
	{'1', '0', '0', '0', '0', '0', '0', '0', '0', '1', '\0'},
	{'1', '0', '0', '0', '0', '0', '0', '0', '0', '1', '\0'},
	{'1', '0', '0', '0', '0', '1', '0', '0', '0', '1', '\0'},
	{'1', '0', '0', '0', '1', '1', '1', '0', '0', '1', '\0'},
	{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '\0'}
};

void	west_ray(t_data *data, double rad, t_ray *ray)
{
	double	offX;
	double	offY;
	int 	step;

	step = 0;
	ray->angle = rad;
	ray->rayX = ((int)(data->px / 64) * 64) - 0.0001;
	ray->rayY = (data->px - ray->rayX) * -tan(rad) + data->py;
	offX = -64;
	offY = -offX * -tan(rad);
	while (step < 10)
	{
		if (ray->rayY < 0 || ray->rayX < 0 || ray->rayY > data->map_y * 64 || ray->rayX > data->map_x * 64)
		{
			ray->lenght = __DBL_MAX__;
			return ;
		}
		if (map2[(int)ray->rayY / 64][(int)ray->rayX / 64] == '1')
			break ;
		else
		{
			ray->rayY += offY;
			ray->rayX += offX;
		}
		step++;
	}
	ray->lenght = sqrt((ray->rayX - data->px) * (ray->rayX - data->px) \
	+ (ray->rayY - data->py) * (ray->rayY - data->py));
}

void	east_ray(t_data *data, double rad, t_ray *ray)
{
	double	offX;
	double	offY;
	int 	step;

	step = 0;
	ray->angle = rad;
	ray->rayX = ((int)(data->px / 64 + 1) * 64);
	ray->rayY = (data->px - ray->rayX) * -tan(rad) + data->py;
	offX = 64;
	offY = -offX * -tan(rad);
	while (step < 10)
	{
		if (ray->rayY < 0 || ray->rayX < 0 || ray->rayY > data->map_y * 64 || ray->rayX > data->map_x * 64)
		{
			ray->lenght = __DBL_MAX__;
			return ;
		}
		if (map2[(int)ray->rayY / 64][(int)ray->rayX / 64] == '1')
			break ;
		else
		{
			ray->rayY += offY;
			ray->rayX += offX;
		}
		step++;
	}
	ray->lenght = sqrt((ray->rayX - data->px) * (ray->rayX - data->px) \
	+ (ray->rayY - data->py) * (ray->rayY - data->py));
}

void	south_ray(t_data *data, double rad, t_ray *ray)
{
	double	offX;
	double	offY;
	int		step;

	step = 0;
	ray->angle = rad;
	ray->rayY = ((int)(data->py / 64) * 64) - 0.0001;
	ray->rayX = (data->py - ray->rayY) * -1 / tan(rad) + data->px;
	offY = -64;
	offX = -offY * (-1 / tan(rad));
	while (step < 10)
	{
		if (ray->rayY < 0 || ray->rayX < 0 || ray->rayY > data->map_y * 64 || ray->rayX > data->map_x * 64)
		{
			ray->lenght = __DBL_MAX__;
			return ;
		}
		if (map2[(int)ray->rayY / 64][(int)ray->rayX / 64] == '1')
			break ;
		else
		{
			ray->rayY += offY;
			ray->rayX += offX;
		}
		step++;
	}
	ray->lenght = sqrt((ray->rayX - data->px) * (ray->rayX - data->px) \
	+ (ray->rayY - data->py) * (ray->rayY - data->py));
}

void	north_ray(t_data *data, double rad, t_ray *ray)
{
	double	offX;
	double	offY;
	int		step;

	step = 0;
	ray->angle = rad;
	ray->rayY = ((int)(data->py / 64 + 1) * 64);
	ray->rayX = (data->py - ray->rayY) * -1 / tan(rad) + data->px;
	offY = 64;
	offX = -offY * (-1 / tan(rad));
	while (step < 10)
	{
		if (ray->rayY < 0 || ray->rayX < 0 || ray->rayY > data->map_y * 64 || ray->rayX > data->map_x * 64)
		{
			ray->lenght = __DBL_MAX__;
			return ;
		}
		if (map2[(int)ray->rayY / 64][(int)ray->rayX / 64] == '1')
			break ;
		else
		{
			ray->rayY += offY;
			ray->rayX += offX;
		}
		step++;
	}
	ray->lenght = sqrt((ray->rayX - data->px) * (ray->rayX - data->px) \
	+ (ray->rayY - data->py) * (ray->rayY - data->py));
}

void	select_ray(t_data *data)
{
	double	angle;
	t_ray	ray_h;
	t_ray	ray_v;
	int		i;
	static int lmao = 0;

	angle = data->rad - (deg_to_rad(data->fov) / 2);
	i = -1;
	ray_h.type = 'h';
	ray_v.type = 'v';
	while (++i < WIDTH)
	{
		if (angle < 0)
			angle += 2 * M_PI;
		if (angle > 2 * M_PI)
			angle -= 2 * M_PI;
		ray_h.lenght = __DBL_MAX__;
		ray_v.lenght = __DBL_MAX__;
		if (angle > NORTH && angle < SOUTH)
			east_ray(data, angle, &ray_v);
		else
			west_ray(data, angle, &ray_v);
		if (angle > M_PI)
			north_ray(data, angle, &ray_h);
		else
			south_ray(data, angle, &ray_h);
		if (ray_h.lenght < ray_v.lenght)
			data->ray[i] = ray_h;
		else
			data->ray[i] = ray_v;
		data->ray[i].lenght = fabs(data->ray[i].lenght * cos(data->ray[i].angle - data->rad));
		angle += deg_to_rad(data->fov / (double)WIDTH);
	}
}
