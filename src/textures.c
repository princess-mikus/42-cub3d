/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:36:56 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/12/17 13:09:23 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	to_rgba_hex(int red, int green, int blue, int alpha)
{
	return (red << 24 | green << 16 | blue << 8 | alpha);
}

int	str_to_hex(char *str)
{
	char	**splitted;
	int		retval;

	splitted = ft_split(str, ',');
	retval = to_rgba_hex(ft_atoi(splitted[0]), ft_atoi(splitted[1]), ft_atoi(splitted[2]), 255);
	free_array((void **)splitted);
	return(retval);
}

t_texture	texture_formatter(mlx_texture_t *texture)
{
	int			x;
	int			k;
	int			y;
	t_texture	new_texture;

	y = -1;
	new_texture.pixels = ft_calloc(texture->height, sizeof(int *));
	new_texture.width = texture->width;
	new_texture.height = texture->height;
	while (++y < texture->height)
	{
		new_texture.pixels[y] = ft_calloc(texture->width, sizeof(int));
		x = -1;
		k = texture->width * 4 * y;
		while (++x < texture->width)
		{
			new_texture.pixels[y][x] = \
			to_rgba_hex(texture->pixels[k], texture->pixels[k + 1],
					texture->pixels[k + 2], texture->pixels[k + 3]);
			k += 4;
		}
	}
	new_texture.pixels[y] = NULL;
	mlx_delete_texture(texture);
	return (new_texture);
}

void	load_textures(t_data *data, t_params *params)
{
	mlx_texture_t	*north_texture;
	mlx_texture_t	*south_texture;
	mlx_texture_t	*east_texture;
	mlx_texture_t	*west_texture;

	north_texture = mlx_load_png(params->no);
	south_texture = mlx_load_png(params->so);
	east_texture = mlx_load_png(params->ea);
	west_texture = mlx_load_png(params->we);
	if (!north_texture || !south_texture || !east_texture || !west_texture)
	{
		free(north_texture);
		free(south_texture);
		free(east_texture);
		free(west_texture);
		mlx_terminate(data->mlx);
		error("Texture not found!", params);
	}
	data->texture.north = texture_formatter(north_texture);
	data->texture.south = texture_formatter(south_texture);
	data->texture.east = texture_formatter(east_texture);
	data->texture.west = texture_formatter(west_texture);
	ft_printf("%s %s\n", params->c, params->f);
	data->ceiling = str_to_hex(params->c);
	data->floor = str_to_hex(params->f);
}
