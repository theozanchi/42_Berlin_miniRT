/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algebra_utils_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 02:16:45 by helauren          #+#    #+#             */
/*   Updated: 2024/01/24 02:23:29 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algebra.h"

/**
 * @brief returns the distance between two points in a 3D space
 * 
 * @param point1 t_vec3 (x, y, z)
 * @param point2 t_vec3 (x, y, z)
 * @return 'double'
 */
double calculate_distance(t_vec3 point1, t_vec3 point2)
{
	double dx = point2.x - point1.x;
	double dy = point2.y - point1.y;
	double dz = point2.z - point1.z;

	return (sqrt(dx * dx + dy * dy + dz * dz));
}
