/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikus <mikus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:18:07 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/12/17 21:28:59 by mikus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	west_ray(t_data *data, double rad, t_ray *ray)
{
	int		step;

	step = -1;
	ray->angle = rad;
	ray->ray_x = ((int)(data->px / 64) * 64) - 0.0001;
	ray->ray_y = (data->px - ray->ray_x) * -tan(rad) + data->py;
	while (++step < 100)
	{
		if (ray->ray_y < 0 || ray->ray_x < 0
			|| ray->ray_y > (data->map_y - 1) * 64 || ray->ray_x > (data->map_x - 1) * 64)
		{
			ray->lenght = __DBL_MAX__;
			return ;
		}
		if (data->map[(int)ray->ray_y / 64][(int)ray->ray_x / 64] == '1')
			break ;
		else
		{
			ray->ray_x += -64;
			ray->ray_y += 64 * -tan(rad);
		}
	}
	ray->lenght = sqrt((ray->ray_x - data->px) * (ray->ray_x - data->px) \
	+ (ray->ray_y - data->py) * (ray->ray_y - data->py));
}

void	east_ray(t_data *data, double rad, t_ray *ray)
{
	int		step;

	step = -1;
	ray->angle = rad;
	ray->ray_x = ((int)(data->px / 64 + 1) * 64);
	ray->ray_y = (data->px - ray->ray_x) * -tan(rad) + data->py;
	while (++step < 100)
	{
		if (ray->ray_y < 0 || ray->ray_x < 0
			|| ray->ray_y > (data->map_y - 1) * 64 || ray->ray_x > (data->map_x - 1) * 64)
		{
			ray->lenght = __DBL_MAX__;
			return ;
		}
		if (data->map[(int)ray->ray_y / 64][(int)ray->ray_x / 64] == '1')
			break ;
		else
		{
			ray->ray_x += 64;
			ray->ray_y += -64 * -tan(rad);
		}
	}
	ray->lenght = sqrt((ray->ray_x - data->px) * (ray->ray_x - data->px) \
	+ (ray->ray_y - data->py) * (ray->ray_y - data->py));
}

void	south_ray(t_data *data, double rad, t_ray *ray)
{
	int		step;

	step = -1;
	ray->angle = rad;
	ray->ray_y = ((int)(data->py / 64) * 64) - 0.0001;
	ray->ray_x = (data->py - ray->ray_y) * -1 / tan(rad) + data->px;
	while (++step < 100)
	{
		if (ray->ray_y < 0 || ray->ray_x < 0
			|| ray->ray_y > (data->map_y - 1) * 64 || ray->ray_x > (data->map_x - 1) * 64)
		{
			ray->lenght = __DBL_MAX__;
			return ;
		}
		if (data->map[(int)ray->ray_y / 64][(int)ray->ray_x / 64] == '1')
			break ;
		else
		{
			ray->ray_x += 64 * (-1 / tan(rad));
			ray->ray_y += -64;
		}
	}
	ray->lenght = sqrt((ray->ray_x - data->px) * (ray->ray_x - data->px) \
	+ (ray->ray_y - data->py) * (ray->ray_y - data->py));
}

void	north_ray(t_data *data, double rad, t_ray *ray)
{
	int		step;

	step = -1;
	ray->angle = rad;
	ray->ray_y = ((int)(data->py / 64 + 1) * 64);
	ray->ray_x = (data->py - ray->ray_y) * -1 / tan(rad) + data->px;
	while (++step < 100)
	{
		if (ray->ray_y < 0 || ray->ray_x < 0
			|| ray->ray_y > (data->map_y - 1) * 64 || ray->ray_x > (data->map_x - 1) * 64)
		{
			ray->lenght = __DBL_MAX__;
			return ;
		}
		if (data->map[(int)ray->ray_y / 64][(int)ray->ray_x / 64] == '1')
			break ;
		else
		{
			ray->ray_x += -64 * (-1 / tan(rad));
			ray->ray_y += 64;
		}
	}
	ray->lenght = sqrt((ray->ray_x - data->px) * (ray->ray_x - data->px) \
	+ (ray->ray_y - data->py) * (ray->ray_y - data->py));
}
