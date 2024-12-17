/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:39:38 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/12/17 12:34:25 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H
# define M_PI 3.14159265358979323846

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>
# include <limits.h>
# include <MLX42/MLX42.h>

# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_params
{
	int		fd;
	char	**raw;
	size_t	raw_heigth;
	size_t	longest;
	int		player_x;
	int		player_y;
	char	player_dir;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*c;
	char	*f;
	int		map_len;
	int		map_height;
	char	*map_path;
	char	*map_name;
	char	**map;
}			t_params;

typedef struct s_ff_list
{
	int		x;
	int		y;
	void	*next;
}	t_fflst;

typedef struct s_ray
{
	double	angle;
	double	lenght;
	char	type;
	double	ray_x;
	double	ray_y;
}	t_ray;

typedef struct s_texture
{
	uint32_t	width;
	uint32_t	height;
	uint32_t	**pixels;
}	t_texture;

typedef struct s_textures
{
	t_texture	north;
	t_texture	south;
	t_texture	east;
	t_texture	west;
}	t_textures;

typedef struct s_data
{
	t_ray		ray[WIDTH];
	t_textures	texture;
	mlx_t		*mlx;
	mlx_image_t	*viewpoint;
	char		**map;
	int			map_x;
	int			map_y;
	double		px;
	double		py;
	double		view_angle;
	double		fov;
	int			ceiling;
	int			floor;
	int			sky_size;
	int			wall_size;
	int			wall_diff;
}	t_data;

#endif