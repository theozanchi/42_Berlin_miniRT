/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algebra_utils_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 02:16:45 by helauren          #+#    #+#             */
/*   Updated: 2024/01/28 01:05:59 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algebra.h"

/**
 * @brief makes point_a travel the distance of lenght in the direction of vector_b
 * @param point_a t_vec3 (x, y, z)
 * @param vec_b t_vec3 (x, y, z)
 * @param length double
 * @return 't_vec3'
*/
t_vec3	point_travel_by_vec_and_length(t_vec3 point_a, t_vec3 vec_b, double len)
{
	point_a.x = point_a.x + vec_b.x * len;
	point_a.y = point_a.y + vec_b.y * len;
	point_a.z = point_a.z + vec_b.z * len;
	return (point_a);
}

/**
 * @brief returns the distance between two points in a 3D space
 * @param a t_vec3 (x, y, z)
 * @param b t_vec3 (x, y, z)
 * @return 'double'
 */
double calculate_distance(t_vec3 a, t_vec3 b)
{
	double dx = b.x - a.x;
	double dy = b.y - a.y;
	double dz = b.z - a.z;
	return (sqrt(dx * dx + dy * dy + dz * dz));
}

/**
 * @brief takes two points and returns the vector from a to b
 * @param a t_vec3 (x, y, z)
 * @param b t_vec3 (x, y, z)
 * @return 'double'
 */
t_vec3 calculate_vector(t_vec3 a, t_vec3 b)
{
	t_vec3 vector;

	vector.x = b.x - a.x;
	vector.y = b.y - a.y;
	vector.z = b.z - a.z;
	return (vector);
}

t_vec3	vec_multiplier(t_vec3 a, double b)
{
	t_vec3	result;

	result.x = a.x * b;
	result.y = a.y * b;
	result.z = a.z * b;
	return (result);
}
