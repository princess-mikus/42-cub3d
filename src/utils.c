/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikus <mikus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:31:00 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/12/10 19:14:49 by mikus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	red_cross(t_params *params)
{
	free_map(params);
	exit(0);
	return (0);
}

void	free_map(t_params *params)
{
	free(params->map_path);
	free(params->map_name);
	free_array((void **)params->raw);
	free_array((void **)params->map);
}


void	error(char *message, t_params *params)
{
	write(2, "Error\n", 6);
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
	free_map(params);
	exit(0);
}

double deg_to_rad(double deg)
{
	while (deg > 360)
		deg /= 360;
	return (deg * M_PI / 180);
}

void	free_array(void **array)
{
	int	i;

	i = -1;
	while (array && array[++i])
		free(array[i]);
	free(array);
}
