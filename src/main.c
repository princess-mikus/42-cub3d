/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:58:17 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/12/18 16:08:23 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data		data;
	t_params	params;

	if (argc != 2)
		return (-1);
	params.map_path = ft_strdup(argv[1]);
	init_params(&params);
	parse_map(&params);
	init_data(&data, &params);
	data.mlx = mlx_init(WIDTH, HEIGHT, "cub3d", true);
	free_map(&params);
	select_ray(&data);
	draw_image(&data);
	mlx_loop_hook(data.mlx, movement, &data);
	mlx_loop(data.mlx);
	free_data(&data);
	return (EXIT_SUCCESS);
}
