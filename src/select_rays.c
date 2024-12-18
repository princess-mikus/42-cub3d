/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:18:07 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/12/18 18:51:34 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_selector(t_data	*data, double angle, t_ray	*ray_h, t_ray *ray_v)
{
	if (angle > NORTH && angle < SOUTH)
		east_ray(data, angle, ray_v);
	else
		west_ray(data, angle, ray_v);
	if (angle > M_PI)
		north_ray(data, angle, ray_h);
	else
		south_ray(data, angle, ray_h);
}

void	init_rays(t_ray	*ray_h, t_ray *ray_v)
{
	ray_h->type = 'h';
	ray_v->type = 'v';
	ray_h->lenght = __DBL_MAX__;
	ray_v->lenght = __DBL_MAX__;
}

void	select_ray(t_data *data)
{
	double	angle;
	t_ray	ray_h;
	t_ray	ray_v;
	int		i;

	angle = data->view_angle - data->fov / 2;
	i = -1;
	while (++i < WIDTH)
	{
		init_rays(&ray_h, &ray_v);
		angle = radian_to_circle(angle);
		ray_selector(data, angle, &ray_h, &ray_v);
		if (ray_h.lenght < ray_v.lenght)
			data->ray[i] = ray_h;
		else
			data->ray[i] = ray_v;
		data->ray[i].lenght = fabs(data->ray[i].lenght
				* cos(data->ray[i].angle - data->view_angle));
		angle += data->fov / (double)WIDTH;
	}
}
