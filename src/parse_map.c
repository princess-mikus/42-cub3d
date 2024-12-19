/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:12:10 by aarranz-          #+#    #+#             */
/*   Updated: 2024/12/19 12:39:06 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_position(t_params *params, char *str, int y, bool *player_found)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == 'N' || str[i] == 'S' || str[i] == 'E' || str[i] == 'W')
		{
			params->player_x = i;
			params->player_y = y;
			params->player_dir = str[i];
			if (!*player_found)
				*player_found = true;
			else
				error("More than one player in map!", params);
		}
	}
}

void	count_lines_len_map(t_params *params)
{
	int	i;

	i = 0;
	while (params->map[i])
	{
		if ((params->map[i][params->map_len] != '1')
			|| (params->map[i][params->map_len + 1] != '\n'
			&& params->map[i][params->map_len + 1] != '\0'))
			error("map char count in lines not valid", params);
		i++;
	}
}

void	parse_map(t_params *params)
{
	file_check(params);
	dump_raw(params);
	dump_info(params);
	dump_info2(params);
	c_f_numbers(params);
	dump_map(params);
	if (!is_closed(params))
		error("Map not closed!", params);
}
