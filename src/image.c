/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:38:16 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/11/28 12:34:04 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_sky(t_data *data, int sky_size, int x)
{
	int y;

	y = -1;
	while (++y < sky_size)
	{
		mlx_put_pixel(data->viewpoint, x, y, data->ceiling);
	}
}

void	draw_floor(t_data *data, int sky_size, int x)
{
	int y;

	y = sky_size - 1;
	while (++y < HEIGHT)
	{
		mlx_put_pixel(data->viewpoint, x, y, data->floor);
	}
}

void	draw_image(t_data *data)
{
	int	wall_size;
	int	wall_diff;
	int	sky_size;
	int	y;
	int	x;

	wall_diff = 0;
	x = -1;
	mlx_delete_image(data->mlx, data->viewpoint);
	data->viewpoint = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	while (++x < HEIGHT)
	{
		wall_size = (64 * HEIGHT) / data->ray[x].lenght / 2;
		if (wall_size > HEIGHT)
		{
			wall_diff = wall_size - HEIGHT;
			wall_size = HEIGHT;
		}
		else
			wall_diff = 0;
		sky_size = (HEIGHT - wall_size) / 2 + (HEIGHT - wall_size) % 2;
 		y = sky_size - 1;
		draw_sky(data, sky_size, x);
		while (++y < (HEIGHT / 2) + (wall_size / 2))
		{
			if (data->ray[x].type == 'h' && data->ray[x].angle > M_PI)
			{
				int tx = data->ray[x].rayX * data->texture.south.width / 64;
				int	ty = ((y - sky_size + wall_diff / 2) * data->texture.south.height) / (wall_size + wall_diff);
				mlx_put_pixel(data->viewpoint, x, y, data->texture.south.pixels[ty][tx % data->texture.south.width]);	
			}
			else if (data->ray[x].type == 'h')
			{
				int tx = data->ray[x].rayX * data->texture.north.width / 64;
				int	ty = ((y - sky_size + wall_diff / 2) * data->texture.north.height) / (wall_size + wall_diff);
				mlx_put_pixel(data->viewpoint, x, y, data->texture.north.pixels[ty][tx % data->texture.north.width]);
			}
			else if (data->ray[x].type == 'v' && data->ray[x].angle < NORTH || data->ray[x].angle > SOUTH)
			{
				int tx = data->ray[x].rayY * data->texture.west.width / 64;
				int	ty = ((y - sky_size + wall_diff / 2) * data->texture.west.height) / (wall_size + wall_diff);
				mlx_put_pixel(data->viewpoint, x, y, data->texture.west.pixels[ty][tx % data->texture.west.width]);
			}
			else
			{
				int tx = data->ray[x].rayY * data->texture.east.width / 64;
				int	ty = ((y - sky_size + wall_diff / 2) * data->texture.east.height) / (wall_size + wall_diff);
				mlx_put_pixel(data->viewpoint, x, y, data->texture.east.pixels[ty][tx % data->texture.east.width]);
			}
		}
		draw_floor(data, y, x);
	}
	mlx_image_to_window(data->mlx, data->viewpoint, 0, 0);
}
