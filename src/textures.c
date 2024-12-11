/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:36:56 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/12/11 11:31:10 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	to_rgba_hex(int red, int green, int blue, int alpha)
{
	return (red << 24 | green << 16 | blue << 8 | alpha);
}

t_texture	texture_formatter(mlx_texture_t *texture)
{
	int			x;
	int			k;
	int			y;
	t_texture	new_texture;

	y = 0;
	new_texture.pixels = malloc(texture->height * sizeof(int *));
	new_texture.width = texture->width;
	new_texture.height = texture->height;
	while (y < texture->height)
	{
		new_texture.pixels[y] = malloc(texture->width * sizeof(int));
		x = -1;
		k = texture->width * 4 * y;
		while (++x < texture->width)
		{
			new_texture.pixels[y][x] = \
			to_rgba_hex(texture->pixels[k], texture->pixels[k + 1],
					texture->pixels[k + 2], texture->pixels[k + 3]);
			k += 4;
		}
		y++;
	}
	mlx_delete_texture(texture);
	return (new_texture);
}

void	load_textures(t_data *data, t_params *parameters)
{
	data->texture.north = texture_formatter(mlx_load_png(parameters->NO));
	data->texture.south = texture_formatter(mlx_load_png(parameters->SO));
	data->texture.east = texture_formatter(mlx_load_png(parameters->EA));
	data->texture.west = texture_formatter(mlx_load_png(parameters->WE));
	data->ceiling = 0xFF0000FF;
	data->floor = 0xFFFFFFFF;
}
