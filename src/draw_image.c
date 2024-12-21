/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikus <mikus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:38:16 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/12/21 13:30:33 by mikus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_sky(t_data *data, int sky_size, int x)
{
	int	y;

	y = -1;
	while (++y < sky_size)
		mlx_put_pixel(data->viewpoint, x, y, data->ceiling);
}

void	draw_floor(t_data *data, int sky_size, int x)
{
	int	y;

	y = sky_size - 1;
	while (++y < HEIGHT)
		mlx_put_pixel(data->viewpoint, x, y, data->floor);
}

void	draw_image(t_data *data)
{
	int		y;
	int		x;

	x = -1;
	while (++x < WIDTH)
	{
		data->wall_size = (64 * HEIGHT) / data->ray[x].lenght;
		if (data->wall_size > HEIGHT)
		{
			data->wall_diff = data->wall_size - HEIGHT;
			data->wall_size = HEIGHT;
		}
		else
			data->wall_diff = 0;
		data->sky_size = (HEIGHT - data->wall_size) / 2
			+ (HEIGHT - data->wall_size) % 2;
		y = data->sky_size - 1;
		draw_sky(data, data->sky_size, x);
		while (++y < (HEIGHT / 2) + (data->wall_size / 2))
			draw_textures(data, x, y);
		draw_floor(data, y, x);
	}
}
