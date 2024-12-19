/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:31:00 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/12/19 14:06:54 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	arr_len(char **array)
{
	int	retval;

	retval = 0;
	while (array[retval])
		retval++;
	return (retval);
}

double	radian_to_circle(double angle)
{
	if (angle <= 0)
		angle += 2 * M_PI;
	if (angle >= 2 * M_PI)
		angle -= 2 * M_PI;
	return (angle);
}

void	error(char *message, t_params *params)
{
	write(2, "Error\n", 6);
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
	free_map(params);
	exit(EXIT_FAILURE);
}

double	deg_to_rad(double deg)
{
	int	rad;

	rad = deg * M_PI / 180;
	return (radian_to_circle(rad));
}
