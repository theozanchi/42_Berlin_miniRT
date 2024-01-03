/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algebra_utils_0.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:09:48 by tzanchi           #+#    #+#             */
/*   Updated: 2024/01/03 19:09:28 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/algebra.h"

/**
 * @brief Vector addition (A + B)
 * 
 * @param A t_vec3
 * @param B t_vec3
 * @return t_vec3 
 */
t_vec3	vec_add(t_vec3 A, t_vec3 B)
{
	t_vec3	output;

	output.x = A.x + B.x;
	output.y = A.y + B.y;
	output.z = A.z + B.z;
	return (output);
}

/**
 * @brief Vector substraction (A - B)
 * 
 * @param A t_vec3
 * @param B t_vec3
 * @return t_vec3 
 */
t_vec3	vec_sub(t_vec3 A, t_vec3 B)
{
	t_vec3	output;

	output.x = A.x - B.x;
	output.y = A.y - B.y;
	output.z = A.z - B.z;
	return (output);
}

/**
 * @brief Vector multiplication (A * B)
 * 
 * @param A t_vec3
 * @param B t_vec3
 * @return t_vec3 
 */
t_vec3	vec_mul(t_vec3 A, t_vec3 B)
{
	t_vec3	output;

	output.x = A.x * B.x;
	output.y = A.y * B.y;
	output.z = A.z * B.z;
	return (output);
}

/**
 * @brief Vector dot product (A · B)
 * 
 * @param A t_vec3
 * @param B t_vec3
 * @return double 
 */
double	dot_product(t_vec3 A, t_vec3 B)
{
	return (A.x * B.x + A.y * B.y + A.z * B.z);
}

/**
 * @brief Vector and scalar multiplication (t * v)
 * 
 * @param v t_vec3
 * @param t double
 * @return t_vec3 
 */
t_vec3	vec_mul_scalar(t_vec3 v, double t)
{
	v.x *= t;
	v.y *= t;
	v.z *= t;
	return (v);
}
