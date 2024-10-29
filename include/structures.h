/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:39:38 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/10/25 13:57:42 by fcasaubo         ###   ########.fr       */
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

typedef struct s_data {
	mlx_t		*mlx;
	mlx_image_t	*img;
	mlx_image_t	*player;
	double		px;
	double		py;
	double		deg;
}	t_data;

#endif