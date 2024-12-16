/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dump_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:03:43 by mikus             #+#    #+#             */
/*   Updated: 2024/12/16 11:50:41 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	dump_map2(t_params *params, size_t k)
{
	size_t	i;
	size_t	j;
	size_t	l;
	bool	player_found;

	i = k - 1;
	j = 0;
	params->map_height = params->raw_heigth - i;
	params->map = ft_calloc(sizeof(char *), (params->map_height + 1));
	while (params->raw[++i])
	{
		player_position(params, params->raw[i], j, &player_found);
		params->map[j] = ft_calloc(sizeof(char), (params->longest + 1));
		l = -1;
		while (++l <= params->longest)
		{
			params->map[j][l] = '0';
			if (l <= ft_strlen(params->raw[i]) && params->raw[i][l] == '1')
				params->map[j][l] = '1';
		}
		j++;
	}
	if (!player_found)
		error("Less than one player! Empty map", params);
}

void	longest_line(t_params *params, int k)
{
	int		i;
	int		j;
	size_t	line;

	i = k;
	line = 0;
	while (params->raw[i])
	{
		j = 0;
		while (params->raw[i][j])
			j++;
		line = j;
		if (line > params->longest)
			params->longest = line;
		i++;
	}
}

void	check_char_map(t_params *params, int k)
{
	int	i;
	int	j;

	i = k - 1;
	while (params->raw[++i])
	{
		j = -1;
		while (params->raw[i][++j])
		{
			if (params->raw[i][j] != '1' && params->raw[i][j] != '0'
			&& params->raw[i][j] != 'N' && params->raw[i][j] != 'W'
			&& params->raw[i][j] != 'S' && params->raw[i][j] != 'E'
			&& params->raw[i][j] != ' ' && params->raw[i][j] != '\n')
				error("characters in map are invalid", params);
		}
	}
}

void	dump_map(t_params *params)
{
	size_t	i;
	size_t	j;
	size_t	info_line;

	info_line = 0;
	i = -1;
	while (params->raw[++i] && (i >= params->raw_heigth - 1 || info_line < 6))
	{
		j = -1;
		while (params->raw[i][++j] != '\0')
		{
			if ((params->raw[i][j] == 'N' && params->raw[i][j + 1] == 'O'
			&& params->raw[i][j + 2] == ' ') || (params->raw[i][j] == 'S'
			&& params->raw[i][j + 1] == 'O' && params->raw[i][j + 2] == ' ')
			|| (params->raw[i][j] == 'E' && params->raw[i][j + 1] == 'A'
			&& params->raw[i][j + 2] == ' ') || (params->raw[i][j] == 'W'
			&& params->raw[i][j + 1] == 'E' && params->raw[i][j + 2] == ' ')
			|| (params->raw[i][j] == 'C' && params->raw[i][j + 1] == ' ')
			|| (params->raw[i][j] == 'F' && params->raw[i][j + 1] == ' '))
				info_line++;
		}
	}
	check_char_map(params, i);
	longest_line(params, i);
	dump_map2(params, i);
}
