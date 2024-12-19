/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:25:37 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/12/19 14:08:32 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>
# include <limits.h>
# include <MLX42/MLX42.h>
# include "structures.h"
# include "libft.h"

# define FOV 60

# define NORTH 1.5708
# define EAST 3.14159
# define SOUTH 4.71239 

void	init_data(t_data *data, t_params *params);
void	load_textures(t_data *data, t_params *params);
void	movement(void *mlx);
void	draw_image(t_data *data);
void	draw_textures(t_data *data, int x, int y);

//------------------------------------------------------------------------------
//			RAYCASTING
//------------------------------------------------------------------------------

void	select_ray(t_data *data);
void	north_ray(t_data *data, double rad, t_ray *ray);
void	south_ray(t_data *data, double rad, t_ray *ray);
void	east_ray(t_data *data, double rad, t_ray *ray);
void	west_ray(t_data *data, double rad, t_ray *ray);

//------------------------------------------------------------------------------
//			FLOODFILL
//------------------------------------------------------------------------------

void	c3d_lstadd_back(t_fflst **lst, t_fflst *new);
void	c3d_lstadd_front(t_fflst **lst, t_fflst *new);
t_fflst	*c3d_lstlast(t_fflst *lst);
t_fflst	*c3d_lstnew(int y, int x);

//------------------------------------------------------------------------------
//			UTILS
//------------------------------------------------------------------------------

double	radian_to_circle(double angle);
double	deg_to_rad(double deg);
int		arr_len(char **array);
void	error(char *message, t_params *params);

//------------------------------------------------------------------------------
//			PARSE MAP
//------------------------------------------------------------------------------
void	init_params(t_params *params);
void	file_check(t_params *params);
void	parse_map(t_params *params);
void	dump_raw(t_params *params);
void	player_position(t_params *params, char *str, int y, bool *player_found);
void	dump_info(t_params *params);
void	dump_info2(t_params *params);
char	*take_path(char *str, int nbr);
void	dump_map(t_params *params);
void	dump_map2(t_params *params, size_t k);
void	check_char_map(t_params *params, int k);
void	longest_line(t_params *params, int k);
bool	is_closed(t_params *params);
void	info_manager(t_params *params, int i);
void	parse_info(t_params *params, int info_height);
void	no_path(t_params *params, int i);
void	so_path(t_params *params, int i);
void	ea_path(t_params *params, int i);
void	we_path(t_params *params, int i);
void	c_f_numbers(t_params *params);

//------------------------------------------------------------------------------
//			LEAKS CONTROL
//------------------------------------------------------------------------------
void	free_map(t_params *params);
void	free_data(t_data *data);
void	free_array(void **array);

#endif // CUB3D_H
