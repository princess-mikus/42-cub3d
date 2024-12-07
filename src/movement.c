/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:37:54 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/11/04 11:17:35 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	movement(void *mlx)
{
	t_data	*data = mlx;
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
	{
		data->px += cos(data->rad);
		data->py += sin(data->rad);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
	{
		data->px -= cos(data->rad);
		data->py -= sin(data->rad);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
	{
		data->px -= cos(data->rad + (M_PI / 2));
		data->py -= sin(data->rad + (M_PI / 2));
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
	{
		data->px += cos(data->rad + (M_PI / 2));
		data->py += sin(data->rad + (M_PI / 2));
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
	{
		data->rad -= 0.1;
		if (data->rad < 0)
			data->rad = 6.28319;
		printf("%f\n", data->rad);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
	{
		data->rad += 0.1;
		if (data->rad > 6.28319)
			data->rad = 0.000001;
		printf("%f\n", data->rad);
	}

	data->player->instances[0].x = data->px;
	data->player->instances[0].y = data->py;
}
