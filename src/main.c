// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

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
	data.mlx = mlx_init(WIDTH, HEIGHT, "cub3d", true);
	init_data(&data, &params);
	select_ray(&data);
	draw_image(&data);
	printf("%f\n", data.view_angle);
	//mlx_loop_hook(data.mlx, draw_image, &data);
	mlx_loop_hook(data.mlx, movement, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (EXIT_SUCCESS);
}
