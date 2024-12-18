/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:03:13 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/12/18 19:04:30 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_x(char **map, int x, int y, t_params *params)
{
	if (y >= params->map_height - 1 || \
	(map[y + 1][x] != '1' && map[y + 1][x] != 'X'))
		return (false);
	if (y <= 0 || (map[y - 1][x] != '1' && map[y - 1][x] != 'X'))
		return (false);
	if (x >= (int)params->longest || (map[y][x + 1] != '1'
		&& map[y][x + 1] != 'X'))
		return (false);
	if (x <= 0 || (map[y][x - 1] != '1' && map[y][x - 1] != 'X'))
		return (false);
	return (true);
}

bool	search_map(char **map, t_params *params)
{
	int	y;
	int	x;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
			if (map[y][x] == 'X' && !check_x(map, x, y, params))
				return (false);
	}
	return (true);
}

bool	in_list(t_fflst *to_check, t_fflst *current)
{
	bool	appears;

	appears = false;
	while (current->next)
	{
		if (to_check->x == current->x && to_check->y == current->y)
		{
			if (!appears)
				appears = true;
			else
				return (true);
		}
		current = current->next;
	}
	return (false);
}

void	search_inner_floors(t_params *params, char **map, t_fflst **positions)
{
	int		x;
	int		y;
	t_fflst	*to_check;

	to_check = *positions;
	x = to_check->x;
	y = to_check->y;
	if (map[y][x] == 'X' || in_list(to_check, *positions))
	{
		*positions = to_check->next;
		return (free(to_check));
	}
	if (x > 0 && map[y][x - 1] != '1' && map[y][x - 1] != 'X')
		c3d_lstadd_back(positions, c3d_lstnew(y, x - 1));
	if (x < (int)params->longest && map[y][x + 1] != '1'
		&& map[y][x + 1] != 'X')
		c3d_lstadd_back(positions, c3d_lstnew(y, x + 1));
	if (y > 0 && map[y - 1][x] != '1' && map[y - 1][x] != 'X')
		c3d_lstadd_back(positions, c3d_lstnew(y - 1, x));
	if (y < params->map_height - 2 && map[y + 1][x] != '1'
		&& map[y + 1][x] != 'X')
		c3d_lstadd_back(positions, c3d_lstnew(y + 1, x));
	map[y][x] = 'X';
	*positions = to_check->next;
	free(to_check);
}

bool	is_closed(t_params *params)
{
	t_fflst	*positions;
	char	**map_cpy;
	int		i;
	bool	retval;

	positions = c3d_lstnew(params->player_y, params->player_x);
	map_cpy = ft_calloc((params->map_height + 1), sizeof(char *));
	i = -1;
	while (params->map[++i])
		map_cpy[i] = ft_strdup(params->map[i]);
	search_inner_floors(params, map_cpy, &positions);
	while (positions)
		search_inner_floors(params, map_cpy, &positions);
	retval = search_map(map_cpy, params);
	free_array((void **)map_cpy);
	free(positions);
	return (retval);
}
