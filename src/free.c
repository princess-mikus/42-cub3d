/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikus <mikus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:59:23 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/12/21 13:37:34 by mikus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_array(void **array)
{
	int	i;

	i = -1;
	while (array && array[++i])
		free(array[i]);
	free(array);
}

void	free_map(t_params *params)
{
	free(params->map_path);
	free(params->map_name);
	free(params->no);
	free(params->so);
	free(params->we);
	free(params->ea);
	free(params->c);
	free(params->f);
	free_array((void **)params->raw);
	free_array((void **)params->map);
}

void	free_data(t_data *data)
{
	free_array((void **)data->map);
	free_array((void **)data->texture.north.pixels);
	free_array((void **)data->texture.south.pixels);
	free_array((void **)data->texture.east.pixels);
	free_array((void **)data->texture.west.pixels);
	if (data->mlx)
	{
		mlx_delete_image(data->mlx, data->viewpoint);
		mlx_terminate(data->mlx);
	}
}
