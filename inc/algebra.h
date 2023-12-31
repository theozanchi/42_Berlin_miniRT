/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algebra.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:05:49 by tzanchi           #+#    #+#             */
/*   Updated: 2024/01/08 19:30:35 by tzanchi          ###   ########.fr       */
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

t_vec3	vec_add(t_vec3 A, t_vec3 B);
t_vec3	vec_sub(t_vec3 A, t_vec3 B);
t_vec3	vec_mul(t_vec3 A, t_vec3 B);
double	dot_product(t_vec3 A, t_vec3 B);
t_vec3	vec_mul_scalar(t_vec3 v, double t);
t_vec3	vec_normalize(t_vec3 v);
t_vec3	vec3(double x, double y, double z);
t_vec3	unit_vec3(double x, double y, double z);

#endif
