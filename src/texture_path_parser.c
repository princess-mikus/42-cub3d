/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_path_parser.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:30:50 by aarranz-          #+#    #+#             */
/*   Updated: 2024/12/19 12:59:57 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	no_path(t_params *params, int i)
{
	if (params->no)
		error("More than one North Texture!", params);
	params->no = take_path(ft_strdup(params->raw[i]), 2);
}

void	so_path(t_params *params, int i)
{
	if (params->so)
		error("More than one South Texture!", params);
	params->so = take_path(ft_strdup(params->raw[i]), 2);
}

void	ea_path(t_params *params, int i)
{
	if (params->ea)
		error("More than one East Texture!", params);
	params->ea = take_path(ft_strdup(params->raw[i]), 2);
}

void	we_path(t_params *params, int i)
{
	if (params->we)
		error("More than one West Texture!", params);
	params->we = take_path(ft_strdup(params->raw[i]), 2);
}

void	c_f_numbers(t_params *params)
{
	int	i;

	i = -1;
	while(params->c[++i])	
	{
		if(params->c[i] == ',')
			i++;
		if (ft_isdigit(params->c[i]) == 0)
			error("error on ceiling", params);			
	}
	i = -1;
	while(params->f[++i])	
	{
		if(params->f[i] == ',')
			i++;
		if (ft_isdigit(params->f[i]) == 0)
			error("error on floor", params);			
	}
}
