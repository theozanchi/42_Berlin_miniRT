/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algebra_utils_0.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:09:48 by tzanchi           #+#    #+#             */
/*   Updated: 2024/01/16 11:09:19 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algebra.h"

/**
 * @brief Vector addition (u + v)
 * 
 * @param u t_vec3
 * @param v t_vec3
 * @return t_vec3 
 */
t_vec3	vec_add(t_vec3 u, t_vec3 v)
{
	t_vec3	output;

	output.x = u.x + v.x;
	output.y = u.y + v.y;
	output.z = u.z + v.z;
	return (output);
}

/**
 * @brief Vector substraction (u - v)
 * 
 * @param u t_vec3
 * @param v t_vec3
 * @return t_vec3 
 */
t_vec3	vec_sub(t_vec3 u, t_vec3 v)
{
	t_vec3	output;

	output.x = u.x - v.x;
	output.y = u.y - v.y;
	output.z = u.z - v.z;
	return (output);
}

/**
 * @brief Vector multiplication (u * v)
 * 
 * @param u t_vec3
 * @param v t_vec3
 * @return t_vec3 
 */
t_vec3	vec_mul(t_vec3 u, t_vec3 v)
{
	t_vec3	output;

	output.x = u.x * v.x;
	output.y = u.y * v.y;
	output.z = u.z * v.z;
	return (output);
}

/**
 * @brief Vector dot product (u · v)
 * 
 * @param u t_vec3
 * @param v t_vec3
 * @return double 
 */
double	dot(t_vec3 u, t_vec3 v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

/**
 * @brief Vector and scalar multiplication (t * v)
 * 
 * @param v t_vec3
 * @param t double
 * @return t_vec3 
 */
t_vec3	mul_scalar(t_vec3 v, double t)
{
	v.x *= t;
	v.y *= t;
	v.z *= t;
	return (v);
}
