/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:37:54 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/12/18 18:33:12 by fcasaubo         ###   ########.fr       */
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

void	check_movement(t_data *data, double delta_x, double delta_y)
{
	int	new_x;
	int	new_y;

	new_x = (data->px + delta_x) / 64;
	new_y = (data->py + delta_y) / 64;
	if (data->map[(int)(data->py / 64)][new_x] != '1')
		data->px += delta_x;
	if (data->map[new_y][(int)(data->px / 64)] != '1')
		data->py += delta_y;
}

void	move_player(t_data	*data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		check_movement(data, -cos(data->view_angle) * 2,
			-sin(data->view_angle) * 2);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		check_movement(data, cos(data->view_angle) * 2,
			sin(data->view_angle) * 2);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		check_movement(data, cos(data->view_angle + (M_PI / 2)) * 2,
			sin(data->view_angle + (M_PI / 2)) * 2);
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		check_movement(data, -cos(data->view_angle + (M_PI / 2)) * 2,
			-sin(data->view_angle + (M_PI / 2)) * 2);
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
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
	{
		free_data(data);
		exit(EXIT_FAILURE);
	}
	if (px_o != data->px || py_o != data->py || data->view_angle != angle_o)
	{
		select_ray(data);
		draw_image(data);
	}
}
