/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:18:07 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/12/12 12:22:54 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	west_ray(t_data *data, double rad, t_ray *ray)
{
	int		step;

	step = -1;
	ray->angle = rad;
	ray->rayX = ((int)(data->px / 64) * 64) - 0.0001;
	ray->rayY = (data->px - ray->rayX) * -tan(rad) + data->py;
	while (++step < 100)
	{
		if (ray->rayY < 0 || ray->rayX < 0
			|| ray->rayY > data->map_y * 64 || ray->rayX > data->map_x * 64)
		{
			ray->lenght = __DBL_MAX__;
			return ;
		}
		if (data->map[(int)ray->rayY / 64][(int)ray->rayX / 64] == '1')
			break ;
		else
		{
			ray->rayX += -64;
			ray->rayY += 64 * -tan(rad);
		}
	}
	ray->lenght = sqrt((ray->rayX - data->px) * (ray->rayX - data->px) \
	+ (ray->rayY - data->py) * (ray->rayY - data->py));
}

void	east_ray(t_data *data, double rad, t_ray *ray)
{
	int		step;

	step = -1;
	ray->angle = rad;
	ray->rayX = ((int)(data->px / 64 + 1) * 64);
	ray->rayY = (data->px - ray->rayX) * -tan(rad) + data->py;
	while (++step < 100)
	{
		if (ray->rayY < 0 || ray->rayX < 0
			|| ray->rayY > data->map_y * 64 || ray->rayX > data->map_x * 64)
		{
			ray->lenght = __DBL_MAX__;
			return ;
		}
		if (data->map[(int)ray->rayY / 64][(int)ray->rayX / 64] == '1')
			break ;
		else
		{
			ray->rayX += 64;
			ray->rayY += -64 * -tan(rad);
		}
	}
	ray->lenght = sqrt((ray->rayX - data->px) * (ray->rayX - data->px) \
	+ (ray->rayY - data->py) * (ray->rayY - data->py));
}

void	south_ray(t_data *data, double rad, t_ray *ray)
{
	int		step;

	step = -1;
	ray->angle = rad;
	ray->rayY = ((int)(data->py / 64) * 64) - 0.0001;
	ray->rayX = (data->py - ray->rayY) * -1 / tan(rad) + data->px;
	while (++step < 100)
	{
		if (ray->rayY < 0 || ray->rayX < 0
			|| ray->rayY > data->map_y * 64 || ray->rayX > data->map_x * 64)
		{
			ray->lenght = __DBL_MAX__;
			return ;
		}
		if (data->map[(int)ray->rayY / 64][(int)ray->rayX / 64] == '1')
			break ;
		else
		{
			ray->rayX += 64 * (-1 / tan(rad));
			ray->rayY += -64;
		}
	}
	ray->lenght = sqrt((ray->rayX - data->px) * (ray->rayX - data->px) \
	+ (ray->rayY - data->py) * (ray->rayY - data->py));
}

void	north_ray(t_data *data, double rad, t_ray *ray)
{
	int		step;

	step = -1;
	ray->angle = rad;
	ray->rayY = ((int)(data->py / 64 + 1) * 64);
	ray->rayX = (data->py - ray->rayY) * -1 / tan(rad) + data->px;
	while (++step < 100)
	{
		if (ray->rayY < 0 || ray->rayX < 0
			|| ray->rayY > data->map_y * 64 || ray->rayX > data->map_x * 64)
		{
			ray->lenght = __DBL_MAX__;
			return ;
		}
		if (data->map[(int)ray->rayY / 64][(int)ray->rayX / 64] == '1')
			break ;
		else
		{
			ray->rayX += -64 * (-1 / tan(rad));
			ray->rayY += 64;
		}
	}
	ray->lenght = sqrt((ray->rayX - data->px) * (ray->rayX - data->px) \
	+ (ray->rayY - data->py) * (ray->rayY - data->py));
}
