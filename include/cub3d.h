#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>
#include <MLX42/MLX42.h>
#include "structures.h"

#define WIDTH 320
#define HEIGHT 320
#define FOV 64

#define NORTH 1.5708
#define RIGHT 3.14159
#define SOUTH 4.71239 

void	movement(void *mlx);
double	deg_to_rad(double deg);
void	select_ray(t_data *data);
mlx_image_t	*draw_small_cube(mlx_t *mlx);

#endif