/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:54:08 by mikus             #+#    #+#             */
/*   Updated: 2024/12/17 12:22:48 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*take_path(char *str, int nbr)
{
	char	*trimed;

	trimed = ft_strtrim(str, " ");
	free(str);
	str = ft_strtrim(trimed + nbr, " \n");
	free(trimed);
	return (str);
}

void	dump_info2(t_params *params)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (params->raw[++i])
	{
		j = -1;
		while (params->raw[i][++j] != '\0')
		{
			if (params->raw[i][j] == 'C' && params->raw[i][j + 1] == ' ')
				params->c = take_path(ft_strdup(params->raw[i]), 1);
			else if (params->raw[i][j] == 'F' && params->raw[i][j + 1] == ' ')
				params->f = take_path(ft_strdup(params->raw[i]), 1);
		}
	}
}

void	dump_info(t_params *params)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (params->raw[++i])
	{
		j = -1;
		while (params->raw[i][++j] != '\0')
		{
			if (params->raw[i][j] == 'N' && params->raw[i][j + 1] == 'O'
			&& params->raw[i][j + 2] == ' ')
				params->no = take_path(ft_strdup(params->raw[i]), 2);
			else if (params->raw[i][j] == 'S' && params->raw[i][j + 1] == 'O'
			&& params->raw[i][j + 2] == ' ')
				params->so = take_path(ft_strdup(params->raw[i]), 2);
			else if (params->raw[i][j] == 'E' && params->raw[i][j + 1] == 'A'
			&& params->raw[i][j + 2] == ' ')
				params->ea = take_path(ft_strdup(params->raw[i]), 2);
			else if (params->raw[i][j] == 'W' && params->raw[i][j + 1] == 'E'
			&& params->raw[i][j + 2] == ' ')
				params->we = take_path(ft_strdup(params->raw[i]), 2);
		}
	}
}

void	dump_raw(t_params *params)
{
	int		fd;
	char	*result;
	int		i;

	result = NULL;
	fd = open(params->map_path, O_RDONLY);
	while (true)
	{
		result = get_next_line(fd);
		if (!result)
			break ;
		free(result);
		params->raw_heigth++;
	}
	params->raw = malloc(sizeof(char *) * params->raw_heigth + 1);
	close(fd);
	fd = open(params->map_path, O_RDONLY);
	i = 0;
	while (true)
	{
		params->raw[i] = get_next_line(fd);
		if (!params->raw[i])
			break ;
		i++;
	}
}

void	file_check(t_params *params)
{
	char	*res;

	params->map_name = ft_strdup(ft_strrchr(params->map_path, '/') + 1);
	if ((ft_strlen(params->map_name) <= 4)
		|| ((params->map_name[ft_strlen(params->map_name) - 1] != 'b')
			|| (params->map_name[ft_strlen(params->map_name) - 2] != 'u')
			|| (params->map_name[ft_strlen(params->map_name) - 3] != 'c')
			|| (params->map_name[ft_strlen(params->map_name) - 4] != '.')))
		error("map extension not valid", params);
	res = NULL;
	params->fd = open(params->map_path, O_RDONLY);
	res = get_next_line(params->fd);
	if (!res || ft_strlen(res) < 3 || res[0] == '\n')
	{
		close(params->fd);
		error("file can't open", params);
	}
	free(res);
	close(params->fd);
}
