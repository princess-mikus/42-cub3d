/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikus <mikus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:37:54 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/12/10 21:18:03 by mikus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	movement(void *mlx)
{
	t_data	*data = mlx;
	int	px_o;
	int	py_o;
	double	angle_o;

	px_o = data->px;
	py_o = data->py;
	angle_o = data->view_angle;
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
	{
		data->px -= cos(data->view_angle);
		data->py -= sin(data->view_angle);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
	{
		data->px += cos(data->view_angle);
		data->py += sin(data->view_angle);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
	{
		data->px += cos(data->view_angle + (M_PI / 2));
		data->py += sin(data->view_angle + (M_PI / 2));
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
	{
		data->px -= cos(data->view_angle + (M_PI / 2));
		data->py -= sin(data->view_angle + (M_PI / 2));
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
	{
		data->view_angle -= 0.1;
		if (data->view_angle <= 0)
			data->view_angle = 6.28319;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
	{
		data->view_angle += 0.1;
		if (data->view_angle >= 6.28319)
			data->view_angle = 0.000001;
	}
	if (px_o != data->px || py_o != data->py || data->view_angle != angle_o)
	{
		select_ray(data);
		draw_image(data);
	}
}
