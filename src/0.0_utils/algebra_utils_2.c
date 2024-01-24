/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algebra_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:02:49 by tzanchi           #+#    #+#             */
/*   Updated: 2024/01/24 19:34:16 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algebra.h"

/**
 * @brief Inverts the vector u
 * 
 * @param u t_vec3 (x, y, z)
 * @return `-u`  (-x, -y, -z)
 */
t_vec3	neg(t_vec3 u)
{
	return (mul_scalar(u, -1.0));
}

/**
 * @brief Returns the cross product u × v
 * 
 * @param u t_vec3 (x, y, z)
 * @param v t_vec3 (x, y, z)
 * @return t_vec3 
 */
t_vec3	prod(t_vec3 u, t_vec3 v)
{
	t_vec3	w;

	w.x = u.y * v.z - u.z * v.y;
	w.y = u.z * v.x - u.x * v.z;
	w.z = u.x * v.y - u.y * v.x;
	return (w);
}

/**
 * @brief Returns the product mtx × u between a matrix and a vector
 * 
 * @param mtx t_mtx33 [(x, y, z), (x, y, z), (x, y, z)]
 * @param u t_vec3 (x, y, z)
 * @return `v` – t_vec3 (x, y, z)
 */
t_vec3	mtx_vec_prod(t_mtx33 mtx, t_vec3 u)
{
	t_vec3	v;

	v.x = mtx.c0.x * u.x + mtx.c1.x * u.y + mtx.c2.x * u.z;
	v.y = mtx.c0.y * u.x + mtx.c1.y * u.y + mtx.c2.y * u.z;
	v.z = mtx.c0.z * u.x + mtx.c1.z * u.y + mtx.c2.z * u.z;
	return (v);
}

/**
 * @brief Returns the length of vector v
 * 
 * @param v t_vec3 (x, y, z)
 * @return double 
 */
double	vec_len(t_vec3 v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}
