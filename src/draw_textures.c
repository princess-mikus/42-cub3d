/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikus <mikus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:47:55 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/12/21 13:38:38 by mikus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_north_texture(t_data *data, int x, int y)
{
	int	tx;
	int	ty;
	int	texture_width;

	texture_width = data->texture.north.width;
	tx = data->ray[x].ray_x * texture_width / 64;
	ty = ((y - data->sky_size + data->wall_diff / 2)
			* data->texture.north.height) / (data->wall_size + data->wall_diff);
	mlx_put_pixel(data->viewpoint, x, y,
		data->texture.north.pixels[ty][tx % texture_width]);
}

void	draw_south_texture(t_data *data, int x, int y)
{
	int	tx;
	int	ty;
	int	texture_width;

	texture_width = data->texture.south.width - 1;
	tx = data->ray[x].ray_x * texture_width / 64;
	ty = ((y - data->sky_size + data->wall_diff / 2)
			* data->texture.south.height) / (data->wall_size + data->wall_diff);
	mlx_put_pixel(data->viewpoint, x, y,
		data->texture.south.pixels[ty][(texture_width - (tx % texture_width))]);
}

void	draw_west_texture(t_data *data, int x, int y)
{
	int	tx;
	int	ty;
	int	texture_width;

	texture_width = data->texture.west.width - 1;
	tx = data->ray[x].ray_y * texture_width / 64;
	ty = ((y - data->sky_size + data->wall_diff / 2)
			* data->texture.west.height) / (data->wall_size + data->wall_diff);
	mlx_put_pixel(data->viewpoint, x, y,
		data->texture.west.pixels[ty][(texture_width - (tx % texture_width))]);
}

void	draw_east_texture(t_data *data, int x, int y)
{
	int	tx;
	int	ty;
	int	texture_width;

	texture_width = data->texture.east.width;
	tx = data->ray[x].ray_y * texture_width / 64;
	ty = ((y - data->sky_size + data->wall_diff / 2)
			* data->texture.east.height) / (data->wall_size + data->wall_diff);
	mlx_put_pixel(data->viewpoint, x, y,
		data->texture.east.pixels[ty][tx % texture_width]);
}

void	draw_textures(t_data *data, int x, int y)
{
	if (data->ray[x].type == 'h' && data->ray[x].angle < M_PI)
		draw_north_texture(data, x, y);
	else if (data->ray[x].type == 'h')
		draw_south_texture(data, x, y);
	else if (data->ray[x].type == 'v'
		&& (data->ray[x].angle < NORTH || data->ray[x].angle > SOUTH))
		draw_west_texture(data, x, y);
	else
		draw_east_texture(data, x, y);
}
