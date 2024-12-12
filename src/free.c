/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:59:23 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/12/12 13:07:29 by aarranz-         ###   ########.fr       */
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
	free(params->NO);
	free(params->SO);
	free(params->WE);
	free(params->EA);
	free(params->C);
	free(params->F);
	free_array((void **)params->raw);
	free_array((void **)params->map);
}
