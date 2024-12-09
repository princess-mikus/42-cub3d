/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:37:54 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/12/11 12:02:15 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_camera(t_data	*data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
	{
		data->view_angle -= 0.05;
		if (data->view_angle <= 0)
			data->view_angle = 6.28319;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
	{
		data->view_angle += 0.05;
		if (data->view_angle >= 6.28319)
			data->view_angle = 0.000001;
	}
}

void	move_player(t_data	*data)
{
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
}

void	movement(void *mlx)
{
	t_data	*data;
	int		px_o;
	int		py_o;
	double	angle_o;

	data = mlx;
	px_o = data->px;
	py_o = data->py;
	angle_o = data->view_angle;
	move_player(data);
	move_camera(data);
	if (px_o != data->px || py_o != data->py || data->view_angle != angle_o)
	{
		select_ray(data);
		draw_image(data);
	}
}
