/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:47:55 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/12/12 12:15:33 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_north_texture(t_data *data, int x, int y)
{
	int	tx;
	int	ty;

	tx = data->ray[x].rayX * data->texture.south.width / 64;
	ty = ((y - data->sky_size + data->wall_diff / 2)
			* data->texture.south.height) / (data->wall_size + data->wall_diff);
	mlx_put_pixel(data->viewpoint, x, y,
		data->texture.south.pixels[ty][tx % data->texture.south.width]);
}

void	draw_south_texture(t_data *data, int x, int y)
{
	int	tx;
	int	ty;

	tx = data->ray[x].rayX * data->texture.north.width / 64;
	ty = ((y - data->sky_size + data->wall_diff / 2)
			* data->texture.north.height) / (data->wall_size + data->wall_diff);
	mlx_put_pixel(data->viewpoint, x, y,
		data->texture.north.pixels[ty][tx % data->texture.north.width]);
}

void	draw_west_texture(t_data *data, int x, int y)
{
	int	tx;
	int	ty;

	tx = data->ray[x].rayY * data->texture.west.width / 64;
	ty = ((y - data->sky_size + data->wall_diff / 2)
			* data->texture.west.height) / (data->wall_size + data->wall_diff);
	mlx_put_pixel(data->viewpoint, x, y,
		data->texture.west.pixels[ty][tx % data->texture.west.width]);
}

void	draw_east_texture(t_data *data, int x, int y)
{
	int	tx;
	int	ty;

	tx = data->ray[x].rayY * data->texture.east.width / 64;
	ty = ((y - data->sky_size + data->wall_diff / 2)
			* data->texture.east.height) / (data->wall_size + data->wall_diff);
	mlx_put_pixel(data->viewpoint, x, y,
		data->texture.east.pixels[ty][tx % data->texture.east.width]);
}

void	draw_textures(t_data *data, int x, int y)
{
	if (data->ray[x].type == 'h' && data->ray[x].angle > M_PI)
		draw_north_texture(data, x, y);
	else if (data->ray[x].type == 'h')
		draw_south_texture(data, x, y);
	else if (data->ray[x].type == 'v'
		&& data->ray[x].angle < NORTH || data->ray[x].angle > SOUTH)
		draw_west_texture(data, x, y);
	else
		draw_east_texture(data, x, y);
}
