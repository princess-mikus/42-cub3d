/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:58:42 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/12/18 17:48:41 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_params(t_params *params)
{
	params->fd = 0;
	params->raw = NULL;
	params->longest = 0;
	params->raw_heigth = 0;
	params->player_x = 0;
	params->player_y = 0;
	params->no = NULL;
	params->so = NULL;
	params->we = NULL;
	params->ea = NULL;
	params->c = NULL;
	params->f = NULL;
	params->map_len = 0;
	params->map_height = 0;
	params->map_name = NULL;
	params->map = NULL;
}

void	load_map(t_data *data, t_params *params)
{
	int	y;

	y = -1;
	data->map = ft_calloc(params->map_height + 1, sizeof(char *));
	while (params->map[++y])
		data->map[y] = ft_strdup(params->map[y]);
}

void	start_camera(t_data *data, t_params *params)
{
	if (params->player_dir == 'N')
		data->view_angle = NORTH;
	else if (params->player_dir == 'E')
		data->view_angle = EAST;
	else if (params->player_dir == 'S')
		data->view_angle = SOUTH;
	else
		data->view_angle = 0;
}

void	init_data(t_data *data, t_params *params)
{
	data->mlx = NULL;
	data->texture.north.pixels = NULL;
	data->texture.south.pixels = NULL;
	data->texture.east.pixels = NULL;
	data->texture.west.pixels = NULL;
	data->map = NULL;
	load_textures(data, params);
	load_map(data, params);
	start_camera(data, params);
	data->fov = deg_to_rad(FOV);
	data->px = params->player_x * 64 + 32;
	data->py = params->player_y * 64 + 32;
	data->map_x = params->longest;
	data->map_y = params->map_height;
}
