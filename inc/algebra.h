/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algebra.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:05:49 by tzanchi           #+#    #+#             */
/*   Updated: 2024/01/30 09:39:02 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGEBRA_H
# define ALGEBRA_H

# include "minirt.h"
# include <math.h>

# ifndef PI
#  define PI 3.14159265358979323846
# endif

/* Functions **************************************************************** */

t_vec3	vec_add(t_vec3 u, t_vec3 v);
t_vec3	vec_sub(t_vec3 u, t_vec3 v);
t_vec3	vec_mul(t_vec3 u, t_vec3 v);
double	dot(t_vec3 u, t_vec3 v);
t_vec3	mul_scalar(t_vec3 v, double t);
t_vec3	normalize(t_vec3 v);
t_vec3	vec(double x, double y, double z);
t_vec3	unit_vec(double x, double y, double z);
double	dot2(t_vec3 v);
int		equal(t_vec3 u, t_vec3 v);
t_vec3	neg(t_vec3 u);
t_vec3	prod(t_vec3 u, t_vec3 v);
t_vec3	mtx_vec_prod(t_mtx33 mtx, t_vec3 u);
double	vec_len(t_vec3 u);
double	calculate_distance(t_vec3 point1, t_vec3 point2);
t_vec3	point_travel_by_vec_and_length(t_vec3 point_a, t_vec3 vec_b, double len);
t_vec3	calculate_vector(t_vec3 a, t_vec3 b);
t_vec3	vec_multiplier(t_vec3 a, double b);


#endif
