/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:38:16 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/11/27 17:42:00 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//void	draw_sky(t_data *data, sky_size)

void	draw_image(t_data *data)
{
	int	wall_size;
	int	wall_diff = 0;
	int	sky_size;
	int	end;
	int	y;
	int	x = -1;

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
		sky_size = (HEIGHT - wall_size) / 2 + (HEIGHT - wall_size) % 2;
		end = (HEIGHT / 2) + (wall_size / 2);
 		y = sky_size - 1;
		while (++y < end)
		{
			if (data->ray[x].type == 'h' && data->ray[x].angle > M_PI)
			{
				int tx = (int)(data->ray[x].rayX * (data->texture.south.width / 64)) % data->texture.south.width;
				int	ty = ((y - sky_size + wall_diff / 2) * data->texture.south.height) / (wall_size + wall_diff);
				mlx_put_pixel(data->viewpoint, x, y, data->texture.south.pixels[ty][tx]);	
			}
			else if (data->ray[x].type == 'h')
			{
				int tx = (int)(data->ray[x].rayX * (data->texture.north.width / 64)) % data->texture.north.width;
				int	ty = ((y - sky_size + wall_diff / 2) * data->texture.north.height) / (wall_size + wall_diff);
				mlx_put_pixel(data->viewpoint, x, y, data->texture.north.pixels[ty][tx]);
			}
			else if (data->ray[x].type == 'v' && data->ray[x].angle < NORTH || data->ray[x].angle > SOUTH)
			{
				int tx = (int)data->ray[x].rayY * (data->texture.west.width / 64) % data->texture.west.width;
				int	ty = ((y - sky_size + wall_diff / 2) * data->texture.west.height) / (wall_size + wall_diff);
				mlx_put_pixel(data->viewpoint, x, y, data->texture.west.pixels[ty][tx]);
			}
			else
			{
				int tx = (int)data->ray[x].rayY * (data->texture.west.width / 64) % data->texture.east.width;
				int	ty = ((y - sky_size + wall_diff / 2) * data->texture.east.height) / (wall_size + wall_diff);
				mlx_put_pixel(data->viewpoint, x, y, data->texture.east.pixels[ty][tx]);
			}
		}
		//draw_sky();
	}
	mlx_image_to_window(data->mlx, data->viewpoint, 0, 0);
}