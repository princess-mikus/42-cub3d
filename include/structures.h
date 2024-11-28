/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:39:38 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/11/28 13:32:17 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
#define STRUCTURES_H
#define M_PI 3.14159265358979323846

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>
#include <MLX42/MLX42.h>

typedef struct s_parameters
{
	int		fd;
	char	**raw;
	int		raw_heigth;
	int		player_x;
	int		player_y;
	char	player_pos;
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	char	*C;
	char	*F;
	int		map_len;
	int		map_heigth;
	char	*map_path;
	char	*map_name;
	char	**map;
}			t_params;

typedef struct s_ray
{
	double	angle;
	double	lenght;
	char	type;
	double	rayX;
	double	rayY;
} t_ray;

typedef struct s_texture
{
	uint32_t	width;
	uint32_t	height;
	uint32_t	**pixels;
} t_texture;


typedef struct s_textures
{
	t_texture	north;
	t_texture	south;
	t_texture	east;
	t_texture	west;
} t_textures;


typedef struct s_data {
	t_ray		ray[2048]; // Replace with WIDTH macros
	t_textures	texture;
	mlx_t		*mlx;
	mlx_image_t	*img;
	mlx_image_t	*viewpoint;
	int			map_x;
	int			map_y;
	double		px;
	double		py;
	double		rad;
	double		fov;
	int			ceiling;
	int			floor;
}	t_data;

#endif