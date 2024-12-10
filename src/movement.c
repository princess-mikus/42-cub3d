/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:37:54 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/11/28 13:42:45 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	movement(void *mlx)
{
	t_data	*data = mlx;
	int	px_o;
	int	py_o;

	px_o = data->px;
	py_o = data->py;
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
	{
		data->px -= cos(data->rad);
		data->py -= sin(data->rad);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
	{
		data->px += cos(data->rad);
		data->py += sin(data->rad);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
	{
		data->px += cos(data->rad + (M_PI / 2));
		data->py += sin(data->rad + (M_PI / 2));
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
	{
		data->px -= cos(data->rad + (M_PI / 2));
		data->py -= sin(data->rad + (M_PI / 2));
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
	{
		data->rad -= 0.1;
		if (data->rad < 0)
			data->rad = 6.28319;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
	{
		data->rad += 0.1;
		if (data->rad > 6.28319)
			data->rad = 0.000001;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
	{
		if (data->fov > 30)
			data->fov -= 1;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
	{
		if (data->fov < 120)
			data->fov += 1;
	}
	if (px_o != data->px || py_o != data->py)
		select_ray(data);
}
