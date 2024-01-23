/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algebra_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:06:29 by tzanchi           #+#    #+#             */
/*   Updated: 2024/01/17 13:00:26 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algebra.h"

/**
 * @brief Normalizes a vector
 * 
 * @param v t_vec3
 * @return t_vec3 of length 1
 */
t_vec3	normalize(t_vec3 v)
{
	double	length;

	length = vec_len(v);
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
t_vec3	vec(double x, double y, double z)
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
t_vec3	unit_vec(double x, double y, double z)
{
	return (normalize(vec(x, y, z)));
}

/**
 * @brief Returns the dot product square of a vector
 * 
 * @param v 
 * @return double 
 */
double	dot2(t_vec3 v)
{
	return (dot(v, v));
}

/**
 * @brief Checks if u and v are equal
 * 
 * @param u t_vec3 (x, y, z)
 * @param v t_vec3 (x, y, z)
 * @return 1 or 0 
 */
int	equal(t_vec3 u, t_vec3 v)
{
	if (u.x != v.x || u.y != v.y || u.z != v.z)
		return (0);
	else
		return (1);
}
