/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:36:56 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/12/18 18:32:41 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	to_rgba_hex(int red, int green, int blue, int alpha)
{
	return (red << 24 | green << 16 | blue << 8 | alpha);
}

int	str_to_hex(char *str, t_data *data, t_params *params)
{
	char	**splitted;
	int		retval;
	int		i;
	bool	error_var;

	i = -1;
	splitted = ft_split(str, ',');
	error_var = false;
	while (splitted[++i])
		if (ft_strlen(splitted[i]) < 1
			|| ft_strlen(splitted[i]) > 3 || atoi(splitted[i]) > 255)
			error_var = true;
	if (error_var || arr_len(splitted) != 3)
	{
		free_array((void **)splitted);
		free_data(data);
		error("Wrong ceiling or floor color!", params);
	}
	retval = to_rgba_hex
		(ft_atoi(splitted[0]), ft_atoi(splitted[1]), ft_atoi(splitted[2]), 255);
	free_array((void **)splitted);
	return (retval);
}

t_texture	texture_formatter(mlx_texture_t *texture)
{
	uint32_t	x;
	uint32_t	y;
	int			k;
	t_texture	new_texture;

	y = -1;
	new_texture.pixels = ft_calloc((texture->height + 1), sizeof(uint32_t *));
	new_texture.width = texture->width;
	new_texture.height = texture->height;
	while (++y < texture->height)
	{
		new_texture.pixels[y] = \
			ft_calloc((texture->width + 1), sizeof(uint32_t));
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
		error("Texture not found!", params);
	}
	data->texture.north = texture_formatter(north_texture);
	data->texture.south = texture_formatter(south_texture);
	data->texture.east = texture_formatter(east_texture);
	data->texture.west = texture_formatter(west_texture);
	data->ceiling = str_to_hex(params->c, data, params);
	data->floor = str_to_hex(params->f, data, params);
}
