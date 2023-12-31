/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algebra_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:06:29 by tzanchi           #+#    #+#             */
/*   Updated: 2024/01/03 19:12:05 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/algebra.h"

/**
 * @brief Normalizes a vector
 * 
 * @param v t_vec3
 * @return t_vec3 of length 1
 */
t_vec3	vec_normalize(t_vec3 v)
{
	double	length;

	length = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	if (length)
	{
		v.x /= length;
		v.y /= length;
		v.z /= length;
	}
	return (v);
}

/**
 * @brief Generates a vector with parameters x, y and z
 * 
 * @param x double
 * @param y double
 * @param z double
 * @return t_vec3 
 */
t_vec3	vec3(double x, double y, double z)
{
	t_vec3	vec3;

	vec3.x = x;
	vec3.y = y;
	vec3.z = z;
	return (vec3);
}

/**
 * @brief Generates a normal vector with parameters x, y, z
 * 
 * @param x double
 * @param y double
 * @param z double
 * @return t_vec3 
 */
t_vec3	unit_vec3(double x, double y, double z)
{
	return (vec_normalize(vec3(x, y, z)));
}
