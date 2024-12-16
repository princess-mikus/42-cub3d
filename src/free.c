/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:59:23 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/12/16 11:59:28 by fcasaubo         ###   ########.fr       */
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
	free_array((void **)params->raw);
	free_array((void **)params->map);
}

void	free_data(t_data *data)
{
	//free_array((void **)data->map);
	//free_array((void **)data->texture.north.pixels);
	//free_array((void **)data->texture.south.pixels);
	//free_array((void **)data->texture.east.pixels);
	//free_array((void **)data->texture.west.pixels);
	mlx_delete_image(data->mlx, data->viewpoint);
	mlx_terminate(data->mlx);
}