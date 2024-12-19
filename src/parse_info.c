/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:16:35 by aarranz-          #+#    #+#             */
/*   Updated: 2024/12/19 14:46:22 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_info(t_params *params, int info_height)
{
	int		i;
	char	*trimmed;

	i = -1;
	while (params->raw[++i] && i < info_height)
	{
		trimmed = ft_strtrim(params->raw[i], " \t\n");
		if (trimmed && ft_strlen(trimmed) >= 3)
		{
			if (!(trimmed[0] == 'N' && trimmed[1] == 'O' && trimmed[2] == ' ')
				&& !(trimmed[0] == 'S' && trimmed[1] == 'O'
					&& trimmed[2] == ' ')
				&& !(trimmed[0] == 'E' && trimmed[1] == 'A'
					&& trimmed[2] == ' ')
				&& !(trimmed[0] == 'W' && trimmed[1] == 'E'
					&& trimmed[2] == ' ')
				&& !(trimmed[0] == 'F' && trimmed[1] == ' ')
				&& !(trimmed[0] == 'C' && trimmed[1] == ' '))
			{
				free(trimmed);
				error("Garbage in info", params);
			}
		}
		free(trimmed);
	}
}
